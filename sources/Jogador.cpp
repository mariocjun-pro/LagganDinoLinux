#include "Jogador.h"

using namespace Jogadores;

Jogador::Jogador(GerenciadorGrafico *gerenciador) : Personagem(gerenciador) {
    aDireita = true;
    posInicial = sf::Vector2f(0.0f, 0.0f);
}

Jogador::~Jogador() {}

void Jogador::imprimir() { gerenciadorGrafico->desenhar(corpoGrafico.getCorpo()); }