#include "Atiradino.h"

using namespace Inimigos;

Atiradino::Atiradino(Plataforma *plataforma) :
        Inimigo(plataforma->getGerenciador()) {
    float aux, aux2;

    vidas = 2;

    plat = plataforma;
    movimento.x = 0;
    movimento.y = 0;
    ataquePronto = true;

    aux = (plat->getTamanho().x / 2.0f) - 50.0f;
    aux2 = (plat->getTamanho().y / 2.0f) + 50.0f;
    fronteira = Vector3f(plat->getPosicao().x - aux, plat->getPosicao().x + aux, plat->getPosicao().y - aux2);

    posicaoInicial =
            fronteira.x + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (fronteira.y - fronteira.x)));

    corpo.inicializa(Vector2f(100.0f, 130.0f), NULL);
    corpo.setTextura("../arquivos/texturas/sprites-dinos/doux.png");
    corpo.inicializaAnimadora(Vector2f(0.0f, -2.5f), Vector2u(4, 1), Vector2u(24, 1));

    corpo = Vector2f(posicaoInicial, fronteira.z);
    corpo.getCorpo()->setFillColor(Color::White);
    totalT = 0;

    hitbox = new Projetil(plataforma->getGerenciador());
    hitbox->getCorpoGraf()->inicializa(Vector2f(100.0f, 100.0f), NULL, Vector2f(30.0f, 30.0f));
    hitbox->getCorpoGraf()->setTextura("../arquivos/texturas/efeitos-projetil/sunburn.png");
    hitbox->getCorpoGraf()->inicializaAnimadora(Vector2f(0.0f, 0.0f), Vector2u(8, 8), Vector2u(8, 8));

    id = 3;
}

Atiradino::~Atiradino() {
    hitbox->setMorto();
}

void Atiradino::executar() {
    if (tomaDano == false) {
        danoT += pGG->getDt();
        if (danoT >= 0.5f) {
            danoT -= 0.5f;
            tomaDano = true;
            ferido = false;
        }
    }

    if (ferido)
        ataquePronto = false;

    atirar();


    animar(movimento);
}

void Atiradino::imprimir() {
    if (atacando)
        pGG->desenhar(hitbox->getCorpoGraf()->getCorpo());

    pGG->desenhar(corpo.getCorpo());
}

void Atiradino::atirar() {
    if (ataquePronto == false)
        totalT += pGG->getDt();

    if (ataquePronto && rand() % 400 == 0) {
        atacando = true;
        totalT -= 0.5f;
        hitbox->getCorpoGraf()->setPosicao(corpo.getPosicao().x + (100.0f * -1), corpo.getPosicao().y);
        ataquePronto = false;

    }

    if (atacando && totalT >= 0.5f) {
        atacando = false;
        totalT = 0.0f;
        ataquePronto = true;
        hitbox->getCorpoGraf()->setPosicao(corpo.getPosicao().x + (100.0f * -1), corpo.getPosicao().y);
    }

    hitbox->getCorpoGraf()->mover(298.0f * pGG->getDt() * -1, 0.0f);
    if (atacando)
        hitbox->getCorpoGraf()->getAnimadora()->atualizarLinhasSequencial(pGG->getDt(), aDireita, Vector2u(8, 8), 5,
                                                                          0.1f);

}