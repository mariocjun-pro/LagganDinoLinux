#include "Personagem.h"

using namespace Personagens;

Personagem::Personagem(Gerenciador_Grafico* g):
Entidade(g)
{
    hitbox = NULL;
    ataquePronto = false;
    velocidade = 500.0f;

    atacando = false;
    totalT = 0.0f;

    noChao = true;

    aDireita = false;
    lado = 1;

    podeMorrer = true;
    
    tomaDano = true;
    ferido = false;
}

Personagem::~Personagem() {
}

void Personagem::executar() {
    mover();
}

void Personagem::imprimir(){
    pGG->desenhar(corpo.getCorpo());
}

void Personagem::animar(Vector2f movimento) {
    Vector2u animacao(0, 4);
    float tempoTrocaAnimacao = 0.3f;
    if(ferido) {
        animacao.x = 14;
        animacao.y = 3;
    }
    else if (movimento.x == 0.0f) {
        //Animação parado
        if(atacando) {
            animacao.x = 17;
            animacao.y = 1;
        }
    }
    else {
        tempoTrocaAnimacao = 0.2f;
        if(atacando) {
            animacao.x = 18;
            animacao.y = 5;
        }
        else {
            animacao.x = 4;
            animacao.y = 5;
        }
        if (movimento.x > 0.0f) {
            //Animação de andar para a direita
            aDireita = true;
        }
        else {
            //Animação de andar para a esquerda
            aDireita = false;
        }
    }

    corpo.atualizaAnimacao(pGG->getDt(), aDireita, animacao.x, animacao.y, tempoTrocaAnimacao, 0);
}

