#include "Personagem.h"

using namespace Personagens;

Personagem::Personagem(GerenciadorGrafico *gerenciadorGrafico) : Entidade(gerenciadorGrafico),
                                                                 velocidade(500.0f),
                                                                 aDireita(false) {}

Personagem::~Personagem() {}

void Personagem::executar() { mover(); }

void Personagem::imprimir() { gerenciadorGrafico->desenhar(corpoGrafico.getCorpo()); }

void Personagem::animar(sf::Vector2f movimento) {
    sf::Vector2u animacao(0, 4);
    float tempoTrocaAnimacao = 0.3f;
    corpoGrafico.atualizaAnimacao(gerenciadorGrafico->getDT(), aDireita, animacao.x, animacao.y, tempoTrocaAnimacao, 0);
}
