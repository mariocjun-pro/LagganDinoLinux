#include "FabricaFloresta.h"

using namespace Fabricas;

FabricaFloresta::FabricaFloresta(Jogo *jogo) :
        FabricaFase(jogo) {
    idFase = 1;
}

FabricaFloresta::~FabricaFloresta() {
}

Fase *FabricaFloresta::criar() {
    fase = static_cast<Fase *>(new Floresta(pJogo, doisJogadores));

    if (carrega) {
        carregar();
    } else {
        instanciaJogadores();
        instanciaPlataformas();
    }

    instanciaFundo();
    limpar();

    return fase;
}

void FabricaFloresta::instanciaJogadores() {

    if (not j1) {
        j1 = new Vita(pJogo->getGerenciador());
    }
    if (not j2) {
        if (doisJogadores) {
            j2 = new Tard(pJogo->getGerenciador());
        }
    }
    fase->incluirEntidade(static_cast<Entidade *>(j1));
    fase->incluirEntidade(static_cast<Entidade *>(j2));
    fase->setJogador1(j1);
    fase->setJogador2(j2);
}

void FabricaFloresta::instanciaPlataformas() {
    ifstream plats("../arquivos/PlataformasFloresta.txt", ios::in);
    Vector2f pos, tam;
    Plataforma *plat;
    Atiradino *atr;
    ChefeDino *chefe;
    int tipo;

    if (!plats) {
        cerr << "Erro ao carregar o arquivo de Plataformas";
    }

    //Instancia as outras plataformas

    while (plats >> tam.x >> tam.y) {
        plats >> pos.x >> pos.y;
        plats >> tipo;

        plat = new Plataforma(tam);
        plat->setGerenciador(pJogo->getGerenciador());
        plat->getCorpoGraf()->setPosicao(pos);
        fase->incluirEntidade(static_cast<Entidade *>(plat));

        int aleatorio;
        aleatorio = rand() % 3;

        if (tipo == 1) {
            if (aleatorio == 0) {
                instanciaInimigos(plat);
                instanciaObstaculos(plat);
            } else if (aleatorio == 1)
                instanciaObstaculos(plat);
            else if (aleatorio == 2)
                instanciaInimigos(plat);
        } else if (tipo == 2) {
            if (aleatorio) {
                atr = new Atiradino(plat);
                fase->incluirEntidade(static_cast<Entidade *>(atr));
                fase->incluirEntidade(static_cast<Entidade *>(atr->getProjetil()));
            }
        } else if (tipo == 3) {
            chefe = new ChefeDino(plat);
            int numJog = (int) doisJogadores + 1;
            chefe->setVidas(numJog * 4);
            fase->incluirEntidade(static_cast<Entidade *>(chefe));
            fase->incluirEntidade(static_cast<Entidade *>(chefe->getProjetil()));
        }
    }

    plats.close();
}

void FabricaFloresta::instanciaInimigos(Plataforma *plat) {
    Andino *andi;
    Atiradino *atr;
    AtiradinoThread *atrT;
    int aleatorio;

    aleatorio = rand() % 3;

    if (aleatorio == 0) {
        andi = new Andino(plat);
        fase->incluirEntidade(static_cast<Entidade *>(andi));

        andi = new Andino(plat);
        fase->incluirEntidade(static_cast<Entidade *>(andi));

        atrT = new AtiradinoThread(plat);
        fase->incluirEntidade(static_cast<Entidade *>(atrT));
        fase->incluirEntidade(static_cast<Entidade *>(atrT->getProjetil()));
    } else if (aleatorio == 1) {
        andi = new Andino(plat);
        fase->incluirEntidade(static_cast<Entidade *>(andi));

        atrT = new AtiradinoThread(plat);
        fase->incluirEntidade(static_cast<Entidade *>(atrT));
        fase->incluirEntidade(static_cast<Entidade *>(atrT->getProjetil()));
    } else if (aleatorio == 2) {
        atrT = new AtiradinoThread(plat);
        fase->incluirEntidade(static_cast<Entidade *>(atrT));
        fase->incluirEntidade(static_cast<Entidade *>(atrT->getProjetil()));

        atrT = new AtiradinoThread(plat);
        fase->incluirEntidade(static_cast<Entidade *>(atrT));
        fase->incluirEntidade(static_cast<Entidade *>(atrT->getProjetil()));
    }
}

void FabricaFloresta::instanciaObstaculos(Plataforma *plat) {

    Espinho *carn;
    Pedra *pedra;
    Galho *galho;

    int aleatorio;

    aleatorio = rand() % 4;

    if (aleatorio == 0) {
        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x - 200.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 200.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));
    } else if (aleatorio == 1) {
        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x - 110.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x - 40.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 30.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 100.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));

        galho = new Galho(plat);
        fase->incluirEntidade(static_cast<Entidade *>(galho));
    } else if (aleatorio == 2) {
        galho = new Galho(plat);
        fase->incluirEntidade(static_cast<Entidade *>(galho));

        galho = new Galho(plat);
        fase->incluirEntidade(static_cast<Entidade *>(galho));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 100.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));
    } else if (aleatorio == 3) {
        galho = new Galho(plat);
        fase->incluirEntidade(static_cast<Entidade *>(galho));

        galho = new Galho(plat);
        fase->incluirEntidade(static_cast<Entidade *>(galho));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 100.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));
    }
}

void FabricaFloresta::instanciaFundo() {
    auto *fundo = new Fundo(3, pJogo->getGerenciador());

    fundo->setTextura("../arquivos/texturas/bg-floresta/background_layer_1.png", 0);
    fundo->setTextura("../arquivos/texturas/bg-floresta/background_layer_2.png", 1);
    fundo->setTextura("../arquivos/texturas/bg-floresta/background_layer_3.png", 2);

    fundo->setTamanho(Vector2f(1280.0f, 960.0f));

    fase->setFundo(fundo);
}
