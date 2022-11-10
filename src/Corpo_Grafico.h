#pragma once

#include "stdafx.h"
#include "Animadora.h"
#include "Colisora.h"

class Corpo_Grafico {
public:
    Corpo_Grafico();

    virtual ~Corpo_Grafico();

    void inicializa(Vector2f tam, Texture *tex);

    //Sets e Gets

    RectangleShape *getCorpo() { return corpo; }

    Colisora *getColisora() { return colisor; }

    Vector2f getPosicao() { return corpo->getPosition(); }

    __attribute__((unused)) Vector2f getTamanho() { return corpo->getSize(); }

    Texture *getTextura() { return textura; }

    void setTextura(const string &arquivo) { if (textura->loadFromFile(arquivo)) cout << "pass"; }

    void inicializaAnimadora(Vector2f margem, Vector2u quantidadeQuadros, Vector2u TotalDeQuadros);

    void atualizaAnimacao(float dT, bool aDireita, unsigned int comecoP = 0, unsigned int quantidadeQuadrosX = 4,
                          float troca = 0.3f, unsigned int linha = 0);

    Animadora *getAnimadora() { return animacao; }

private:
    RectangleShape *corpo;
    Animadora *animacao;
    Colisora *colisor;
    Texture *textura;
};

