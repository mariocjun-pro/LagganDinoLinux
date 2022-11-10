#include "Guigo.h"

using namespace Jogadores;

Guigo::Guigo(Gerenciador_Grafico* g):
Jogador(g)
{
    velocidade = 700.0f;
    corpo.inicializa(Vector2f(100.0f, 130.0f), NULL, Vector2f(80.0f, 130.0f));
    corpo.setTextura("../Texturas/Dinos/vita.png");
    corpo.inicializaAnimadora(Vector2f(0.0f, -2.5f), Vector2u(4, 1), Vector2u(24, 1));

    hitbox->getCorpoGraf()->setTextura("../Texturas/Efeitos/sunburn.png");
    hitbox->getCorpoGraf()->inicializaAnimadora(Vector2f(0.0f, 0.0f), Vector2u(8, 8), Vector2u(8, 8));

    posInicial = Vector2f(corpo.getPosicao().x / 2.0f, 710);
    corpo = (posInicial);

    id = 7;
}

Guigo::~Guigo() {

}

void Guigo::executar() {
    if(ataquePronto == false)
        totalT += pGG->getDt();

    Keyboard::Key tecla = Keyboard::E;
    if(Keyboard::isKeyPressed(tecla) && ataquePronto) {
        atacando = true;
        totalT -= 0.5f;
        hitbox->getCorpoGraf()->setPosicao(corpo.getPosicao().x + (100.0f * lado), corpo.getPosicao().y);
        ataquePronto = false;
        ladoAtaque = lado;

        if(abs(movimento.x) > 0)
            vJog = velocidade;
        else
            vJog = 0;

    }
    if(atacando && totalT >= 0.5f) {
        atacando = false;
        totalT = 0.0f;
        ataquePronto = true;
    }


    hitbox->getCorpoGraf()->mover((298.0f + vJog) * pGG->getDt() * ladoAtaque, 0.0f);
    if(atacando)
        hitbox->getCorpoGraf()->getAnimadora()->atualizarLinhasSequencial(pGG->getDt(), aDireita, Vector2u(8, 8), 5, 0.1f);

    mover();
}

void Guigo::mover() {
    Vector2u animacao(0, 0);
    float tempoTrocaAnimacao = 0.3f;
    float dT = pGG->getDt();
    movimento.x = 0;

    if(Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movimento.x += velocidade;
        lado = 1;
    }

    if(Keyboard::isKeyPressed(Keyboard::A)){
        movimento.x -= velocidade;
        lado = -1;
    }

    if(Keyboard::isKeyPressed(Keyboard::Key::Space) && noChao)
    {
        noChao = false;
        movimento.y = -sqrtf(2.0 * 981.0 * pulo);
    }

    movimento.y += 981.0 * dT * 2.5f;

    if(Keyboard::isKeyPressed(Keyboard::Q)) {
        movimento.y -= 20.0f;
    }

    corpo.mover(movimento * dT);
    animar(movimento);
}
