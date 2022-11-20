#include "FabricaFase.h"
#include "AtiradinoThread.h"

using namespace Fabricas;

FabricaFase::FabricaFase(Jogo *jogo) {
    pJogo = jogo;
    carrega = false;
    doisJogadores = false;
    idFase = 0;

    j1 = NULL;
    j2 = NULL;
}

FabricaFase::~FabricaFase() {
}

void FabricaFase::setJogadores(Guigo *jog1, Titi *jog2) {
    j1 = new Guigo(pJogo->getGerenciador());
    j1->setVidas(jog1->getVidas());
    j1->setPontos(jog1->getPontos());
    j1->setPosicao(Vector2f(j1->getPosicao().x, -1000.0f));

    if (doisJogadores) {
        j2 = new Titi(pJogo->getGerenciador());
        j2->setVidas(jog2->getVidas());
        j2->setPontos(jog2->getPontos());
        j2->setPosicao(Vector2f(j2->getPosicao().x, -1000.0f));
    }
}

void FabricaFase::carregar() {
    string salvo = "SemNome";

    ifstream leitor;
    ifstream plats;

    if (idFase == 0)
        plats.open("../arquivos/PlataformasMontanha.txt", ios::in);
    else if (idFase == 1)
        plats.open("../arquivos/PlataformasFloresta.txt", ios::in);

    if (!plats) {
        cerr << "Falha ao abrir o Arquivo";
    }

    int tipo = 0, id = 0, aux1 = 0, aux2 = 0, numJogadores = 1, i = 0;
    Vector2f pos, tam;

    Entidade *ent = NULL;
    Inimigo *inim = NULL;
    Plataforma *plat = NULL;
    Andino *andi = NULL;
    Atiradino *atira = NULL;
    Espinho *esp = NULL;
    ChefeDino *chefe = NULL;
    Galho *galho = NULL;
    Pedra *pedra = NULL;
    Jogador *jog = NULL;

    if (doisJogadores)
        numJogadores = 2;

    leitor.open("../arquivos/save/Jogador" + salvo + ".dino", ios::in);

    if (!leitor) {
        cerr << "Falha ao abrir arquivo";
    }

    for (i = 0; i < numJogadores; i++) {
        leitor >> id;
        if (id == 7) {
            j1 = new Guigo(pJogo->getGerenciador());
            fase->setJogador1(j1);
            jog = reinterpret_cast<Jogador *>(j1);
        } else {
            j2 = new Titi(pJogo->getGerenciador());
            fase->setJogador2(j2);
            jog = reinterpret_cast<Jogador *>(j2);
        }

        //Pontos
        leitor >> aux1;
        //Vidas
        leitor >> aux2;
        //Posição x, y
        leitor >> pos.x >> pos.y;

        jog->setPontos(aux1);
        jog->setVidas(aux2);
        jog->setPosicao(pos);
        fase->incluirEntidade(static_cast<Entidade *>(jog));
    }
    leitor.close();

    while (plats >> tam.x >> tam.y) {
        plats >> pos.x >> pos.y;
        plats >> tipo;

        plat = new Plataforma(tam);
        plat->setGerenciador(pJogo->getGerenciador());
        plat->getCorpoGraf()->setPosicao(pos);
        fase->incluirEntidade(static_cast<Entidade *>(plat));
        plataformas.push_back(plat);
    }

    plats.close();

    leitor.open("../arquivos/save/Objetos" + salvo + ".dino", ios::in);

    if (!leitor) {
        cerr << "Falha ao abrir arquivo";
    }

    while (leitor >> id) {
        inim = NULL;

        //plataformas
        leitor >> aux1;

        //Posição
        leitor >> pos.x >> pos.y;

        switch (id) {
            case 1:
                inim = static_cast<Inimigo *>(new Andino(plataformas.at(aux1)));
                ent = static_cast<Entidade *>(inim);
                break;
            case 3:
                if (idFase == 1) {
                    inim = static_cast<Inimigo *>(new Atiradino(plataformas.at(aux1)));
                    ent = static_cast<Entidade *>(inim);
                } else {
                    inim = static_cast<Inimigo *>(new AtiradinoThread(plataformas.at(aux1)));
                    ent = static_cast<Entidade *>(inim);
                }
                break;
            case 4:
                ent = static_cast<Entidade *>( new Espinho(pJogo->getGerenciador()));
                break;
            case 5:
                inim = static_cast<Inimigo *>(new ChefeDino(plataformas.at(aux1)));
                ent = static_cast<Entidade *>(inim);
                break;
            case 6:
                ent = static_cast<Entidade *>(new Galho(plataformas.at(aux1)));
                break;
            case 8:
                ent = static_cast<Entidade *>(new Pedra(plataformas.at(aux1)));
                break;
            default:
                break;
        }

        ent->setPosicao(pos);
        if (inim) {
            //Vidas
            leitor >> aux2;
            inim->setVidas(aux2);
        }

        fase->incluirEntidade(ent);
    }

    leitor.close();
}

void FabricaFase::limpar() {
    carrega = false;
    doisJogadores = false;

    j1 = NULL;
    j2 = NULL;
}