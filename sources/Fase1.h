#ifndef GAME_FASE1_H
#define GAME_FASE1_H

#include "stdafx.h"
#include "Fase.h"
#include "Jogador.h"
#include "Jogador1.h"
#include "GerenciadorGrafico.h"

using namespace Abstratas;
using namespace Listas;
using namespace Jogadores;
//using namespace GerenciadoresFases;
//using namespace Inimigos;
using namespace Personagens;
//using namespace Obstaculos;
using namespace Estados;
using namespace Controladoras;

namespace Fases {
    class Fase1 : public Fase {
    public:
        Fase1(Jogo *pJogo = nullptr);

        ~Fase1();

        void executar();
    };
}

#endif //GAME_FASE1_H
