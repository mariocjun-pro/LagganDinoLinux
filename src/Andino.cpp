#include "Andino.h"

using namespace Inimigos;

Andino::Andino(Plataforma *plataforma) :
        Inimigo(plataforma->getGerenciador()) {
    float aux, aux2;
    plat = plataforma;

    vidas = 2;
    pulo = 280.0f;

    aux = (plat->getTamanho().x / 2.0f) - 50.0f;
    aux2 = (plat->getTamanho().y / 2.0f) + 50.0f;
    fronteira = Vector3f(plat->getPosicao().x - aux, plat->getPosicao().x + aux, plat->getPosicao().y - aux2);

    velocidade = 200.0f;

    corpo.inicializa(Vector2f(100.0f, 130.0f), NULL);
    corpo.setTextura("../Texturas/Dinos/mort.png");
    corpo.inicializaAnimadora(Vector2f(0.0f, -2.5f), Vector2u(4, 1), Vector2u(24, 1));

    posicaoInicial =
            fronteira.x + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (fronteira.y - fronteira.x)));
    if (rand() % 2)
        lado = 1;

    corpo = Vector2f(posicaoInicial, fronteira.z);
    corpo.getCorpo()->setFillColor(Color::White);
    totalT = 0;

    id = 1;
}

Andino::~Andino() {

}

void Andino::mover() {

    int chancePulo;
    float dT = pGG->getDt();
    totalT += dT;
    movimento.x = velocidade * lado;

    chancePulo = rand() % 700;

    if (!chancePulo && noChao) {
        noChao = false;

        movimento.y = -sqrtf(2.0 * 981.0 * pulo);
    }

    movimento.y += 981.0 * dT;

    float tempoTroca = 0.2f;

    if ((corpo.getCorpo()->getPosition().x < fronteira.x || corpo.getCorpo()->getPosition().x > fronteira.y) &&
        totalT >= tempoTroca) {
        lado *= -1;
        totalT -= tempoTroca;
    }


    corpo.mover(movimento * dT);
}

