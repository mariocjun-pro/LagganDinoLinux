#pragma once

#include "stdafx.h"
#include "Fase.h"
#include "Jogador.h"
#include "Menu.h"
#include "Gerenciador_Grafico.h"
#include "Montanha.h"
#include "Floresta.h"
#include "Huatli.h"
#include "Angrath.h"

class Jogo {
public:
    Jogo();

    ~Jogo();

    void executar();

    //Sets e Gets

    Gerenciador_Grafico *getGerenciador() { return &GG; }

    void setJogador1(Huatli *jogador1) { j1 = jogador1; }

    void setJogador2(Angrath *jogador2) { j2 = jogador2; }

private:
    Huatli *j1;
    Angrath *j2;

    Menu m1;

    Montanha *montanha;
    Floresta *f2;

    Gerenciador_Grafico GG;

    float dT;
    Clock clock;
};
