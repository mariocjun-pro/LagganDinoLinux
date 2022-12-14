#pragma once

#include "stdafx.h"
#include "Inimigo.h"
#include "Projetil.h"
#include "Plataforma.h"
#include "Corpo_Grafico.h"
#include "Animadora.h"

using namespace Auxiliares;
using namespace GerenciadoresEntidades;

namespace Inimigos {
    class Atiradino : public Inimigo {
    public:
        Atiradino(Plataforma *p = nullptr);

        virtual ~Atiradino();

        virtual void executar();

        void imprimir();

        virtual void atirar();

        Projetil *getProjetil() { return hitbox; }

        void setVidas(const int v) { vidas = v; }
    private:
        int vidas_inimigo;
    };
}

