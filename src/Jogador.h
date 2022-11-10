#pragma once

#include "stdafx.h"
#include "Personagem.h"
#include "Inimigo.h"

class Jogador
        : public Personagem {
public:
    explicit Jogador(Gerenciador_Grafico *gerenciador = NULL);

    virtual ~Jogador();

    virtual void morrer();

    __attribute__((unused)) bool atacar(Inimigo *inim);

    void imprimir();

    void executar();

    //Sets e Gets

    bool getAtacando() const { return atacando; }

    Corpo_Grafico *getHitbox() { return &hitbox; }

protected:
    Vector2f posInicial;
    Corpo_Grafico hitbox;

};


