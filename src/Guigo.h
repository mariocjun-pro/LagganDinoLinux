#pragma once
#include "stdafx.h"
#include "Jogador.h"
#include "Animadora.h"
#include "Corpo_Grafico.h"

using namespace GerenciadoresEntidades;

namespace Jogadores {
    class Guigo : public Jogador {
    public:
        Guigo(Gerenciador_Grafico* g = NULL);
        ~Guigo();

        void mover();
        void executar();

    private:
    };
}
