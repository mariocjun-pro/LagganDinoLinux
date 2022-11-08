#ifndef GAME_JOGADOR1_H
#define GAME_JOGADOR1_H

#include "stdafx.h"
#include "Jogador.h"
#include "Animadora.h"
#include "CorpoGrafico.h"

using namespace GerenciadoresEntidades;

namespace Jogadores {
    class Jogador1 : public Jogador {
    public:
        Jogador1(GerenciadorGrafico *g = nullptr);

        ~Jogador1();

        void mover();

        void executar();
    };
}

#endif //GAME_JOGADOR1_H
