#include "Vita.h"

using namespace Jogadores;

Vita::Vita(Gerenciador_Grafico *g) :
Jogador(g) {
    velocidade_Vita = static_cast<int>(this->vJog + static_cast<float>(700));

    corpo.inicializa(Vector2f(100.0F, 130.0F), nullptr, Vector2f(80.0F, 130.0F));
    corpo.setTextura("../arquivos/texturas/sprites-dinos/vita.png");
    corpo.inicializaAnimadora(Vector2f(0.0F, -2.5F), Vector2u(4, 1), Vector2u(24, 1));

    hitbox->getCorpoGraf()->setTextura("../arquivos/texturas/efeitos-projetil/sunburn.png");
    hitbox->getCorpoGraf()->inicializaAnimadora(Vector2f(0.0F, 0.0F), Vector2u(8, 8), Vector2u(8, 8));

    posInicial = Vector2f(corpo.getPosicao().x / 2.0F, static_cast<float>(710));
    corpo = (posInicial);

    id = 7;
}

Vita::~Vita()
{
}

void Vita::executar() {
    if (!ataquePronto)
        totalT += pGG->getDt();

    Keyboard::Key tecla = Keyboard::Space;
    if (Keyboard::isKeyPressed(tecla) && ataquePronto) {
        atacando = true;
        totalT -= 0.5f;
        hitbox->getCorpoGraf()->setPosicao(corpo.getPosicao().x + (100.0f * lado), corpo.getPosicao().y);
        ataquePronto = false;
        ladoAtaque = lado;

        if (abs(movimento.x) > static_cast<float>(0))
            vJog = static_cast<float>(this->getVelocidade_Vita());
        else
            vJog = 0;
    }
    if (atacando && totalT >= 0.5F) {
        atacando = false;
        totalT = 0.0F;
        ataquePronto = true;
    }

    hitbox->getCorpoGraf()->mover((298.0F + vJog) * pGG->getDt() * static_cast<float>(this->ladoAtaque), 0.0F);
    if (atacando)
        hitbox->getCorpoGraf()->getAnimadora()->atualizarLinhasSequencial(pGG->getDt(), aDireita, Vector2u(8, 8), 5,
                                                                          0.1F);
    mover();
}

void Vita::mover() {

    float dT = pGG->getDt();
    movimento.x = 0;

    if (Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movimento.x += static_cast<float>(this->getVelocidade_Vita());
        lado = 1;
    }

    if (Keyboard::isKeyPressed(Keyboard::A)) {
        movimento.x -= static_cast<float>(this->getVelocidade_Vita());
        lado = -1;
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
        noChao = false;
        movimento.y = -sqrtf(2.0 * 981.0 * pulo);
    }

    movimento.y += 981.0 * dT * 2.5F;

    if (Keyboard::isKeyPressed(Keyboard::Q)) {
        movimento.y -= 20.0F;
    }

    corpo.mover(movimento * dT);
    animar(movimento);
}
