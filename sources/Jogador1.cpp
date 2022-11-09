#include "Jogador1.h"

using namespace Jogadores;

Jogador1::Jogador1(GerenciadorGrafico *g) : Jogador(g) {
    velocidade = 700.f;
    corpoGrafico.inicializa(sf::Vector2f(100.f, 130.f), nullptr, sf::Vector2f(80.0f, 130.0f));
    corpoGrafico.setTextura("../assets//images//jogador1.png");
    corpoGrafico.inicializaAnimadora(sf::Vector2f(0.0f, -2.5f), sf::Vector2u(8, 8), sf::Vector2u(8, 8));

    posInicial = sf::Vector2f(corpoGrafico.getPosicao().x / 2.0f, 710.f);
    corpoGrafico = posInicial;
}

Jogador1::~Jogador1() {}

void Jogador1::executar() { mover(); }

void Jogador1::mover() {
    float DT = gerenciadorGrafico->getDT();
    movimentacao.x = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movimentacao.x -= velocidade;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movimentacao.x += velocidade;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        movimentacao.y = -sqrtf(2.0f * 981.0f * pulo);
    }

    movimentacao.y += 981.0f * DT * 2.5f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        movimentacao.y -= 20.0f;
    }

    corpoGrafico.mover(movimentacao * DT);
    animar(movimentacao);
}