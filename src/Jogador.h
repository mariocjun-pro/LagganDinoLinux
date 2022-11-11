#pragma once

#include "stdafx.h"
#include "Personagem.h"
#include "Projetil.h"

using namespace Personagens;
using namespace Auxiliares;

namespace Jogadores {
    class Jogador : public Personagem {
    public:
        explicit Jogador(Gerenciador_Grafico *gerenciador = nullptr);

        virtual ~Jogador();

        void morrer();

        void morrer(Vector2f pos);

        void imprimir();

        virtual void executar() = 0;

        //Sets e Gets

        __attribute__((unused)) void setAtacando(const bool atac) { atacando = atac; }

        bool getAtacando() const { return atacando; }

        __attribute__((unused)) Corpo_Grafico *getHitbox() { return hitbox->getCorpoGraf(); }

        Projetil *getProjetil() { return hitbox; }

        void setPontos(const int p) { pontos = p; }

        int getPontos() const { return pontos; }

    protected:
        Vector2f posInicial;
        Projetil *hitbox;
        bool ataquePronto;
        short ladoAtaque;

        int pontos;
        float pulo;

        //Auxiliares
        float vJog;
    };
}

