#pragma once

#include "stdafx.h"
#include "Jogador.h"
#include "Animadora.h"
#include "Corpo_Grafico.h"

using namespace GerenciadoresEntidades;

namespace Jogadores {
    class Vita : public Jogador {
    public:
        Vita(Gerenciador_Grafico *g = nullptr);

        ~Vita();

        void mover();

        void executar();

    private:
    };
}
