#include "Montanha.h"
#include "Jogo.h"

Montanha::Montanha(Jogo *jooj) :
        Fase(jooj) {

    texturaFundo[0].loadFromFile("../Texturas//Montanha//parallax-mountain-bg.png");
    texturaFundo[1].loadFromFile("../Texturas//Montanha//parallax-mountain-montain-far.png");
    texturaFundo[2].loadFromFile("../Texturas//Montanha//parallax-mountain-mountains.png");
    texturaFundo[3].loadFromFile("../Texturas//Montanha//parallax-mountain-trees.png");
    texturaFundo[4].loadFromFile("../Texturas//Montanha//parallax-mountain-foreground-trees.png");

    for (int j = 0; j < 5; j++) {
        fundo[j].setSize(Vector2f(1280.0f, 960.0f));
        fundo[j].setOrigin(Vector2f(1280.0f / 2.0f, 960.0f / 2.0f));
        fundo[j].setTexture(&(texturaFundo[j]));
    }


    /*ifstream plats ("Plataformas.txt", ios::in);
    char c;
    Vector2f pos, tam;*/

    float aux, aux2;

    //Instanciar jogador

    jogador = new Huatli(pJogo->getGerenciador());
    pJogo->setJogador1(jogador);
    entidades.incluir(static_cast<Entidade *>(jogador));


    /*if (!plats)
    {
        cout << "AA";
    }

    plats >> contPlat;

    //Instancia a plataforma do jogador

    plats >> tam.x >> tam.y;
    plats >> pos.x >> pos.y;
    plats >> c;

    plat = new Plataforma(tam);
    plat->setGerenciador(pJogo->getGerenciador());
    plat->getCorpoGraf()->getCorpo()->setPosition(pos);
    entidades.incluir(static_cast<Entidade*>(plat));

    //Instancia as outras plataformas

    for (int i = 1; i < contPlat; i++)
    {
        plats >> tam.x >> tam.y;
        plats >> pos.x >> pos.y;
        plats >> c;

        plat = new Plataforma(tam);
        plat->setGerenciador(pJogo->getGerenciador());
        plat->getCorpoGraf()->getCorpo()->setPosition(pos);
        entidades.incluir(static_cast<Entidade*>(plat));

        aux = (plat->getTamanho().x / 2.0f) - 50.0f;
        aux2 = (plat->getTamanho().y / 2.0f) + 50.0f;
        andi = new Andino(pJogo->getGerenciador(), Vector3f(plat->getPosicao().x - aux, plat->getPosicao().x + aux, plat->getPosicao().y - aux2));
        andi->setPlataforma(plat);
        entidades.incluir(static_cast<Entidade*>(andi));
    }

    plats.close();*/

    // Instanciar plataformas

    //Posicao em y da plataforma:
    //Tamanho da janela (960) - (plat->getTamanho().y / 2.0f) == mais baixo possivel

    plat = new Plataforma(Vector2f(500.0f, 60.0f));
    plat->setGerenciador(pJogo->getGerenciador());
    plat->getCorpoGraf()->getCorpo()->setPosition(Vector2f(0, 830));
    entidades.incluir(static_cast<Entidade *>(plat));

    plat = new Plataforma(Vector2f(500.0f, 100.0f));
    plat->setGerenciador(pJogo->getGerenciador());
    plat->getCorpoGraf()->getCorpo()->setPosition(Vector2f(900, 830));
    plat->getCorpoGraf()->getCorpo()->setFillColor(sf::Color::White);
    entidades.incluir(static_cast<Entidade *>(plat));

    //cout << plat->getPosicao().x << " " << plat->getPosicao().y << endl;

    aux = (plat->getTamanho().x / 2.0f) - 50.0f;
    aux2 = (plat->getTamanho().y / 2.0f) + 50.0f;
    andi = new Andino(pJogo->getGerenciador(),
                      Vector3f(plat->getPosicao().x - aux, plat->getPosicao().x + aux, plat->getPosicao().y - aux2));
    andi->setPlataforma(plat);
    entidades.incluir(static_cast<Entidade *>(andi));

    plat = new Plataforma(Vector2f(500.0f, 100.0f));
    plat->setGerenciador(pJogo->getGerenciador());
    plat->getCorpoGraf()->getCorpo()->setPosition(Vector2f(1700, 630));
    plat->getCorpoGraf()->getCorpo()->setFillColor(sf::Color::White);
    entidades.incluir(static_cast<Entidade *>(plat));

    aux = (plat->getTamanho().x / 2.0f) - 50.0f;
    aux2 = (plat->getTamanho().y / 2.0f) + 50.0f;
    andi = new Andino(pJogo->getGerenciador(),
                      Vector3f(plat->getPosicao().x - aux, plat->getPosicao().x + aux, plat->getPosicao().y - aux2));
    andi->setPlataforma(plat);
    entidades.incluir(static_cast<Entidade *>(andi));

    plat = new Plataforma(Vector2f(500.0f, 100.0f));
    plat->setGerenciador(pJogo->getGerenciador());
    plat->getCorpoGraf()->getCorpo()->setPosition(Vector2f(900, 380));
    plat->getCorpoGraf()->getCorpo()->setFillColor(sf::Color::White);
    entidades.incluir(static_cast<Entidade *>(plat));

    aux = (plat->getTamanho().x / 2.0f) - 50.0f;
    aux2 = (plat->getTamanho().y / 2.0f) + 50.0f;
    andi = new Andino(pJogo->getGerenciador(),
                      Vector3f(plat->getPosicao().x - aux, plat->getPosicao().x + aux, plat->getPosicao().y - aux2));
    andi->setPlataforma(plat);
    entidades.incluir(static_cast<Entidade *>(andi));
}

Montanha::~Montanha() {

}

void Montanha::executar() {

    for (i = 0; i < 5; i++) {
        fundo[i].setPosition(pJogo->getGerenciador()->getVisao()->getCenter());
        pJogo->getGerenciador()->desenhar(&fundo[i]);
    }
    entidades.executar();
    entidades.imprimir();
    entidades.colidir(jogador);


    /*plat->executar();
    if(andi)
        andi->mover();
    jogador->executar();
    gerenciar_colisoes();
    if(andi)
        andi->imprimir();
    jogador->imprimir();
    plat->imprimir();
    plat2->imprimir();*/

}

/*void Montanha::gerenciar_colisoes() {
    Vector2f direcao;

    if(plat->verificarColisao(jogador->getColisora(), direcao, 1.0f))
        jogador->Colidindo(direcao);
    if(plat2->verificarColisao(jogador->getColisora(), direcao, 1.0f))
        jogador->Colidindo(direcao);

    if(andi) {
        if(plat2->verificarColisao(andi->getColisora(), direcao, 1.0f))
            andi->Colidindo(direcao);
        if(jogador->verificarColisao(andi->getColisora(), direcao, 0.0f)) {
                jogador->morrer();
        }
        if(jogador->atacar(static_cast<Inimigo*>(andi)))
        {
            delete andi;
            andi = NULL;
        }
    }

}*/
