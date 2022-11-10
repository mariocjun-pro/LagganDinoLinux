#pragma once

#include "stdafx.h"
#include "Entidade.h"
#include "ListaEntidade.h"
#include "Ent.h"
#include "Huatli.h"

class Jogo;

class Fase
        : public Ent {
public:
    explicit Fase(Jogo *jooj = NULL);

    virtual ~Fase();

    virtual void executar();

    __attribute__((unused)) virtual void gerenciar_colisoes();

    __attribute__((unused)) virtual void reiniciar();

    //Sets e Gets
    Huatli *getJogador() { return jogador; }

    __attribute__((unused)) void setJogo(Jogo *jooj) { pJogo = jooj; }

protected:
    ListaEntidade entidades;

    Jogo *pJogo;
    Huatli *jogador{};

};

