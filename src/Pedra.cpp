#include "Pedra.h"

Pedra::Pedra(Plataforma* plataforma):
Obstaculo(plataforma->getGerenciador())
{
    Vector3f fronteira;
    float posicaoInicial;
    
    podeMatar = false;
    podeMorrer = false;
    empurrao = 0.5f;

    corpo.inicializa(Vector2f(100.0f, 150.0f), NULL);

    corpo.setTextura("../Texturas/Obstaculos/Pedra.png");
    corpo.inicializaAnimadora(Vector2f(0.0f, 0.0f), Vector2u(1, 1), Vector2u(1, 1));
    corpo.atualizaAnimacao(0.0f, false, 0, 0, 1, 0);
    
    float aux, aux2;

    plat = plataforma;

    aux = (plat->getTamanho().x / 2.0f) - 50.0f;
    aux2 = (plat->getTamanho().y / 2.0f) + 50.0f;
    fronteira = Vector3f(plat->getPosicao().x - aux, plat->getPosicao().x + aux, plat->getPosicao().y - aux2);

    posicaoInicial = fronteira.x + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(fronteira.y-fronteira.x)));

    corpo = Vector2f(posicaoInicial, fronteira.z - 100);
    
    id = 8;
}

Pedra::~Pedra() {
}

void Pedra::executar() {
    
    movimento.y += 981.0f * pGG->getDt();
    corpo.mover(movimento * pGG->getDt());
    
    if(corpo.getPosicao().y >  1000.0f)
        morto = true;
}