#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Projetil.h"

using namespace Abstratas;
using namespace Auxiliares;

namespace Personagens {
    class Personagem : public Entidade {
    public:
        Personagem(Gerenciador_Grafico* gerenciador = NULL);
        virtual ~Personagem();

        virtual void imprimir();
        virtual void executar();

        virtual void animar(Vector2f movimento);

    protected:
        float velocidade;

        bool atacando;
        float totalT;

        bool aDireita;
        short int lado;

        bool tomaDano;
        bool ferido;

        bool ataquePronto;
        Projetil* hitbox;

    };
}

