#include "Personagem.h"

using namespace Personagens;

Personagem::Personagem(GerenciadorGrafico *gerenciadorGrafico) : Entidade(gerenciadorGrafico),
                                                                 velocidade(500.0f),
                                                                 atacando(false),
                                                                 totalT(0.0f),
                                                                 aDireita(false),
                                                                 lado(1),
                                                                 tomarDano(true),
                                                                 ferido(false),
                                                                 ataquePronto(false) {}

Personagem::~Personagem() {}

void Personagem::executar() { mover(); }

void Personagem::imprimir() { gerenciadorGrafico->desenhar(corpoGrafico.getCorpo()); }

void Personagem::animar(sf::Vector2f movimento) {
    sf::Vector2u animacao(0, 4);
    float tempoTrocaAnimacao = 0.3f;
    if (ferido) {
        animacao.x = 14;
        animacao.y = 3;
    } else if (movimento.x == 0.0f) {
        // Parado
        if (atacando) {
            animacao.x = 17;
            animacao.y = 1;
        }
    } else {
        tempoTrocaAnimacao = 0.2f;
        if (atacando) {
            animacao.x = 18;
            animacao.y = 5;
        } else {
            animacao.x = 4;
            animacao.y = 5;
        }
        if (movimento.x > 0.0f) {
            aDireita = true;
        } else {
            lado = false;
        }
    }

    corpoGrafico.atualizaAnimacao(gerenciadorGrafico->getDT(), aDireita, animacao.x, animacao.y, tempoTrocaAnimacao, 0);

}
