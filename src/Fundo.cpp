#include "Fundo.h"

Fundo::Fundo(unsigned int qtd, Gerenciador_Grafico* GG) {
    qtdFundos = qtd;
    pGG = GG;
    
    corpo = new RectangleShape[qtdFundos];
    textura = new Texture[qtdFundos];
}

Fundo::~Fundo() {
    delete[] corpo;
    delete[] textura;
}

void Fundo::imprimir() {
    int i;
    for(i = 0; i < qtdFundos; i++) {
        pGG->desenhar(&corpo[i]);
    }
}



void Fundo::setPosicao(const Vector2f pos) {
    int i;
    for(i = 0; i < qtdFundos; i++) {
        corpo[i].setPosition(pos);
    }
}

void Fundo::setTamanho(const Vector2f tam) {
    int i;
    for(i = 0; i < qtdFundos; i++) {
        corpo[i].setSize(tam);
        corpo[i].setOrigin(tam / 2.0f);
    }
}