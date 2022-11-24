#include "Pedra.h"

Pedra::Pedra(Plataforma *plataforma) :
Obstaculo(plataforma->getGerenciador()), dificuldade_empurrar(0.7F) {
    Vector3f fronteira;
    float posicaoInicial;

    podeMatar = obstaculo_danoso;
    podeMorrer = false;
    empurrao = dificuldade_empurrar;

    corpo.inicializa(Vector2f(100.0F, 150.0F), nullptr);

    corpo.setTextura("../arquivos/texturas/obstaculos/Pedra.png");
    corpo.inicializaAnimadora(Vector2f(0.0F, 0.0F), Vector2u(1, 1), Vector2u(1, 1));
    corpo.atualizaAnimacao(0.0F, false, 0, 0, 1, 0);

    float aux, aux2;

    plat = plataforma;

    aux = (plat->getTamanho().x / 2.0F) - 50.0F;
    aux2 = (plat->getTamanho().y / 2.0F) + 50.0F;
    fronteira = Vector3f(plat->getPosicao().x - aux, plat->getPosicao().x + aux, plat->getPosicao().y - aux2);

    posicaoInicial =
            fronteira.x + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (fronteira.y - fronteira.x)));

    corpo = Vector2f(posicaoInicial, fronteira.z - 100);

    id = 8;
}

Pedra::~Pedra()
{
}

void Pedra::executar() {

    movimento.y += 981.0F * pGG->getDt();
    corpo.mover(movimento * pGG->getDt());

    if (corpo.getPosicao().y > 1000.0F)
        morto = true;
}