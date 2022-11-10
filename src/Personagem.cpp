#include "Personagem.h"

Personagem::Personagem(Gerenciador_Grafico *gerenciador) :
        Entidade(gerenciador), lado(-1), aDireita(false) {
    atacando = false;
    totalT = 0;
    vidas = 3;
    velocidade = 500.0f;
    noChao = true;
    movimento = Vector2f(0.0f, 0.0f);
}

Personagem::~Personagem() {
}

void Personagem::executar() {
    mover();
}

void Personagem::imprimir() {
    pGG->desenhar(corpo.getCorpo());
}

void Personagem::Colidindo(Vector2f direcao) {
    if (direcao.x < 0) //Colidindo na esquerda
        movimento.x = 0;

    else if (direcao.x > 0) //Colidindo na direita
        movimento.x = 0;

    if (direcao.y > 0) //Colidindo em cima
    {
        movimento.y = 0;
    } else if (direcao.y < 0) //Colidindo em baixo
    {
        movimento.y = 0;
        noChao = true;
    }
}

bool Personagem::verificarColisao(Colisora *outro, Vector2f &direcao, float f) {
    bool colidiu;
    colidiu = corpo.getColisora()->verificarColisao(outro, direcao, f);
    if (colidiu)
        Colidindo(direcao);

    return colidiu;
}

void Personagem::animar(Vector2f movimento) {
    Vector2u animacao(0, 4);
    float tempoTrocaAnimacao = 0.3f;
    if (movimento.x == 0.0f) {
        //Animação parado
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
            //Animação de andar para a direita
            aDireita = true;
        } else {
            //Animação de andar para a esquerda
            aDireita = false;
        }
    }

    corpo.atualizaAnimacao(pGG->getDt(), aDireita, animacao.x, animacao.y, tempoTrocaAnimacao, 0);
}

