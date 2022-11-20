#include "Titi.h"

using namespace Jogadores;

Titi::Titi(Gerenciador_Grafico *g) :
        Jogador(g) {
    pulo = 1000.0f;
    vidas = 10;
    corpo.inicializa(Vector2f(100.0f, 130.0f), NULL, Vector2f(80.0f, 130.0f));
    corpo.setTextura("../arquivos/texturas/sprites-dinos/tard.png");
    corpo.inicializaAnimadora(Vector2f(0.0f, -2.5f), Vector2u(4, 1), Vector2u(24, 1));

    hitbox->getCorpoGraf()->setTextura("../arquivos/texturas/efeitos-projetil/magic.png");
    hitbox->getCorpoGraf()->inicializaAnimadora(Vector2f(0.0f, 0.0f), Vector2u(9, 9), Vector2u(9, 9));

    posInicial = Vector2f((corpo.getPosicao().x / 2.0f) + 70.0f, 710);
    corpo = (posInicial);

    id = 2;

}

Titi::~Titi() {

}

void Titi::executar() {
    totalT += pGG->getDt();

    if (Keyboard::isKeyPressed(Keyboard::Numpad0) && ataquePronto) {
        atacando = true;
        totalT -= 0.5f;
        hitbox->getCorpoGraf()->setPosicao(corpo.getPosicao().x + (100.0f * lado), corpo.getPosicao().y);
        ataquePronto = false;
        ladoAtaque = lado;

        if (abs(movimento.x) > 0)
            vJog = velocidade;
        else
            vJog = 0;

    }
    if (atacando && totalT >= 0.5f) {
        atacando = false;
        totalT = 0.0f;
        ataquePronto = true;
    }


    hitbox->getCorpoGraf()->mover((500.0f + vJog) * pGG->getDt() * ladoAtaque, 0.0f);
    if (atacando)
        hitbox->getCorpoGraf()->getAnimadora()->atualizarLinhasSequencial(pGG->getDt(), aDireita, Vector2u(9, 9), 5,
                                                                          0.1f);


    mover();
}

void Titi::mover() {
    Vector2u animacao(0, 0);
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
        movimento.y = -sqrtf(2.0 * 981.0 * pulo);
    }

    movimento.y += 981.0 * dT * 2.5f;

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        movimento.y += 20.0f;
    }

    corpo.mover(movimento * dT);
    animar(movimento);
}
