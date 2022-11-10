#include "Andino.h"

Andino::Andino(Gerenciador_Grafico *g, Vector3f f) :
        Inimigo(g), fronteira(f), pulo(300) {
    noChao = true;
    velocidade = 200.0f;

    corpo.inicializa(Vector2f(100.0f, 130.0f), NULL);
    corpo.setTextura("../Texturas//Dinos//mort.png");
    corpo.inicializaAnimadora(Vector2f(0.0f, -2.5f), Vector2u(4, 1), Vector2u(24, 1));

    posicaoInicial =
            fronteira.x + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (fronteira.y - fronteira.x)));
    if (rand() % 2)
        lado = 1;

    corpo.getCorpo()->setPosition(Vector2f(posicaoInicial, fronteira.z));
    corpo.getCorpo()->setFillColor(Color::White);
    totalT = 0;
}

Andino::~Andino() {

}

void Andino::mover() {

    int chancePulo;
    float dT = pGG->getDt();
    totalT += dT;
    movimento.x = velocidade * lado;

    chancePulo = rand() % 1000;

    if (!chancePulo && noChao) {
        noChao = false;

        movimento.y = -sqrtf(2.0 * 981.0 * pulo);
    }

    movimento.y += 981.0 * dT;

    float tempoTroca = 0.1f;

    if ((corpo.getCorpo()->getPosition().x < fronteira.x || corpo.getCorpo()->getPosition().x > fronteira.y)
        && totalT >= tempoTroca) {
        lado *= -1;
        totalT -= tempoTroca;
    }

    corpo.getCorpo()->move(movimento * dT);
    animar(movimento);
}

/*void Andino::morrer() {
    morto = true;
}*/
