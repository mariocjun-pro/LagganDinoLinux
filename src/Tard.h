#pragma once

#include "stdafx.h"
#include "Jogador.h"
#include "Corpo_Grafico.h"
#include "Animadora.h"

using namespace Controladoras;
using namespace GerenciadoresEntidades;

namespace Jogadores {
    class Tard : public Jogador {
    public:
        Tard(Gerenciador_Grafico *g = nullptr);

        ~Tard();

        void mover();

        void executar();

        float getPulo_Tard() { return pulo_Tard; }

    private:
        float pulo_Tard;
    };
}

