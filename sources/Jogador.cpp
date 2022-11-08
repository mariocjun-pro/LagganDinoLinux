#include "Jogador.h"

using namespace Jogadores;

Jogador::Jogador(GerenciadorGrafico *gerenciador) :
        Personagem(gerenciador), ataquePronto(true), ladoAtaque(1), pontos(000), pulo(700), vJog(0) {
    hitbox = nullptr;
    vida = 10;
    lado = 1;
    aDireita = true;
    posInicial = sf::Vector2f(0.0f, 0.0f);
    podeMatar = false;
}

Jogador::~Jogador() {

}

void Jogador::morrer() {
    pontos -= 12;
    vida--;
    if (vida >= 0) {
        corpoGrafico = (posInicial);
    }
}

void Jogador::morrer(sf::Vector2f pos) {
    pontos -= 12;
    vida--;
    if (vida >= 0) {
        corpoGrafico = (pos);
    }
}

void Jogador::imprimir() {

    if (atacando)
        gerenciadorGrafico->desenhar(hitbox->getCorpoGrafico()->getCorpo());

    gerenciadorGrafico->desenhar(corpoGrafico.getCorpo());

}