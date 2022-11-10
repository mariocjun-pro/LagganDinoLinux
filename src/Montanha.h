#pragma once

#include "stdafx.h"
#include "Fase.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "Huatli.h"
#include "Andino.h"

class Montanha
        : public Fase {
public:
    explicit Montanha(Jogo *jooj = NULL);

    ~Montanha();

    void executar();
    //void gerenciar_colisoes();

private:

    Plataforma *plat;
    //Plataforma* plat2;
    Andino *andi;

    RectangleShape fundo[5];
    Texture texturaFundo[5];

    __attribute__((unused)) int i{};

    __attribute__((unused)) unsigned short int contPlat{};
    __attribute__((unused)) unsigned short int contInim{};
    __attribute__((unused)) unsigned short int contObs{};
    __attribute__((unused)) unsigned short int contJog{};
};

