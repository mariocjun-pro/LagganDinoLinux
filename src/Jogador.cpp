#include "Jogador.h"
using namespace Jogadores;

Jogador::Jogador(Gerenciador_Grafico* gerenciador):
Personagem(gerenciador), ataquePronto(true), ladoAtaque(1), pontos(000), pulo(700), vJog(0)
{
    hitbox = NULL;
    vidas = 10;
    lado = 1;
    aDireita = true;
    hitbox = new Projetil(pGG);
    hitbox->getCorpoGraf()->inicializa(Vector2f(100.0f, 100.0f), NULL);
    posInicial = Vector2f(0.0f, 0.0f);

    podeMatar = false;
}

Jogador::~Jogador() {

}

void Jogador::morrer() {
    pontos -= 12;
    vidas--;
    if(vidas >= 0) {
        corpo = (posInicial);
    }
}

void Jogador::morrer(Vector2f pos) {
    pontos -= 12;
    vidas--;
    if(vidas >= 0) {
        corpo = (pos);
    }
}

void Jogador::imprimir() {

    if(atacando)
        pGG->desenhar(hitbox->getCorpoGraf()->getCorpo());

    pGG->desenhar(corpo.getCorpo());

}
