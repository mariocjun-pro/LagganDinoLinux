#include "Galho.h"

Galho::Galho(Plataforma *plataforma) :
        Obstaculo(plataforma->getGerenciador()) {
    Vector3f fronteira;
    float posicaoInicial;

    podeMatar = false;
    podeMorrer = true;
    empurrao = 1.0f;

    corpo.inicializa(Vector2f(150.0f, 100.0f), NULL);

    corpo.setTextura("../Texturas/Obstaculos/galhoss.png");
    corpo.inicializaAnimadora(Vector2f(0.0f, -50.0f), Vector2u(1, 1), Vector2u(1, 1));
    corpo.atualizaAnimacao(0.0f, false, 0, 0, 1, 0);

    float aux, aux2;

    plat = plataforma;

    aux = (plat->getTamanho().x / 2.0f) - 50.0f;
    aux2 = (plat->getTamanho().y / 2.0f) + 50.0f;
    fronteira = Vector3f(plat->getPosicao().x - aux, plat->getPosicao().x + aux, plat->getPosicao().y + 70.0f);

    posicaoInicial =
            fronteira.x + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (fronteira.y - fronteira.x)));

    corpo = Vector2f(posicaoInicial, fronteira.z - 100);

    id = 6;
}

Galho::~Galho() {
}