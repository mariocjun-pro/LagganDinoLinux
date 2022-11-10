#pragma once

#include "stdafx.h"

class Gerenciador_Grafico {
public:
    Gerenciador_Grafico();

    virtual ~Gerenciador_Grafico();

    RenderWindow *getJanela() { return &janela; }

    bool getAberto() const { return janela.isOpen(); }

    void limpar();

    void leEventos();

    void desenhar(RectangleShape *elem) { janela.draw(*elem); }

    View *getVisao() { return &visao; }

    void setDt(float delta) { dT = delta; }

    float getDt() const { return dT; }

private:
    RenderWindow janela;
    View visao;
    float dT;

    float AJ;
    float LJ;
    float LP;
    float AP;

};


