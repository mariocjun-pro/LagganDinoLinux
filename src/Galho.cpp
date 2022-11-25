#include "Galho.h"

Galho::Galho(Plataforma *plataforma) :
Obstaculo(plataforma->getGerenciador()), obstaculo_destruivel(true) {
    Vector3f fronteira;
    float posicaoInicial;

    podeMatar = false;
    podeMorrer = obstaculo_destruivel;
    empurrao = 1.0F;

    corpo.inicializa(Vector2f(150.0F, 100.0F), nullptr);

    corpo.setTextura("../arquivos/texturas/obstaculos/galhoss.png");
    corpo.inicializaAnimadora(Vector2f(0.0F, -50.0F), Vector2u(1, 1), Vector2u(1, 1));
    corpo.atualizaAnimacao(0.0F, false, 0, 0, 1, 0);

    float aux;

    plat = plataforma;

    aux = (plat->getTamanho().x / 2.0F) - 50.0F;

    fronteira = Vector3f(plat->getPosicao().x - aux, plat->getPosicao().x + aux, plat->getPosicao().y + 70.0F);

    posicaoInicial =
            fronteira.x + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (fronteira.y - fronteira.x)));

    corpo = Vector2f(posicaoInicial, fronteira.z - static_cast<float>(100));

    id = 6;
}

Galho::~Galho()
{
}