#include "Tard.h"

using namespace Jogadores;

Tard::Tard(Gerenciador_Grafico *g) :
        Jogador(g) {
    pulo_Tard = pulo + static_cast<float>(1000);
    vidas = 10;
    corpo.inicializa(Vector2f(100.0F, 130.0F), nullptr, Vector2f(80.0F, 130.0F));
    corpo.setTextura("../arquivos/texturas/sprites-dinos/tard.png");
    corpo.inicializaAnimadora(Vector2f(0.0F, -2.5F), Vector2u(4, 1), Vector2u(24, 1));

    hitbox->getCorpoGraf()->setTextura("../arquivos/texturas/efeitos-projetil/magic.png");
    hitbox->getCorpoGraf()->inicializaAnimadora(Vector2f(0.0F, 0.0F), Vector2u(9, 9), Vector2u(9, 9));

    posInicial = Vector2f((corpo.getPosicao().x / 2.0F) + 70.0F, static_cast<float>(710));
    corpo = (posInicial);

    id = 2;
}

Tard::~Tard()
{
}

void Tard::executar() {
    totalT += pGG->getDt();

    if (Keyboard::isKeyPressed(Keyboard::Numpad0) && ataquePronto) {
        atacando = true;
        totalT -= 0.5F;
        hitbox->getCorpoGraf()->setPosicao(corpo.getPosicao().x + (100.0F * static_cast<float>(this->lado)), corpo.getPosicao().y);
        ataquePronto = false;
        ladoAtaque = lado;

        if (abs(movimento.x) > static_cast<float>(0))
            vJog = velocidade;
        else
            vJog = 0;

    }
    if (atacando && totalT >= 0.5F) {
        atacando = false;
        totalT = 0.0F;
        ataquePronto = true;
    }

    hitbox->getCorpoGraf()->mover((500.0F + vJog) * pGG->getDt() * static_cast<float>(this->ladoAtaque), 0.0F);
    if (atacando)
        hitbox->getCorpoGraf()->getAnimadora()->atualizarLinhasSequencial(pGG->getDt(), aDireita, Vector2u(9, 9), 5,
                                                                          0.1F);


    mover();
}

void Tard::mover() {
    float dT = pGG->getDt();
    movimento.x = 0;

    if (Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        movimento.x += velocidade;
        lado = 1;
    }

    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        movimento.x -= velocidade;
        lado = -1;
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::Up) && noChao) {
        noChao = false;
        movimento.y = -sqrtf(2.0 * 981.0 * getPulo_Tard());
    }

    movimento.y += 981.0 * dT * 2.5F;

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        movimento.y += 20.0F;
    }

    corpo.mover(movimento * dT);
    animar(movimento);
}
