#ifndef GAME_FABRICAFASE1_H
#define GAME_FABRICAFASE1_H

#include "stdafx.h"
#include "FabricaFase.h"
#include "Fase.h"
#include "Fase1.h"
#include "Entidade.h"
#include "ListaEntidade.h"
#include "Jogador1.h"
#include "Jogo.h"


using namespace Abstratas;
using namespace Listas;
using namespace Jogadores;
using namespace GerenciadorFases;
//using namespace Inimigos;
using namespace Personagens;
//using namespace Obstaculos;
using namespace Controladoras;
using namespace Fases;

namespace Fabricas {
    class FabricaFase1 : FabricaFase {
    private:
        void instanciaJogador();

    public:
        FabricaFase1(Jogo *jogo = nullptr);

        ~FabricaFase1();

        Fase *criarFase();
    };
}

#endif //GAME_FABRICAFASE1_H
