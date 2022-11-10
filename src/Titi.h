#pragma once
#include "stdafx.h"
#include "Jogador.h"
#include "Corpo_Grafico.h"
#include "Animadora.h"

using namespace Controladoras;
using namespace GerenciadoresEntidades;

namespace Jogadores {
    class Titi : public Jogador {
    public:
        Titi(Gerenciador_Grafico* g = NULL);
        ~Titi();

        void mover();
        void executar();

    private:
    };
}

