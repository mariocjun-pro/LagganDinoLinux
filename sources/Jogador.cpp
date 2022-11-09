#include "Jogador.h"

using namespace Jogadores;

Jogador::Jogador(GerenciadorGrafico *gerenciador) :
        Personagem(gerenciador), ataquePronto(true), ladoAtaque(1), pontos(000), pulo(700), vJog(0) {
    vida = 10;
    lado = 1;
    aDireita = true;
    posInicial = sf::Vector2f(0.0f, 0.0f);
    podeMatar = false;
}

Jogador::~Jogador() {}

void Jogador::imprimir() { gerenciadorGrafico->desenhar(corpoGrafico.getCorpo()); }