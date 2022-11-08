#ifndef GAME_FABRICAFASE1_H
#define GAME_FABRICAFASE1_H

#include "stdafx.h"
#include "Fase.h"
#include "Fase1.h"
#include "FabricaFase.h"
#include "Entidade.h"
#include "ListaEntidade.h"
#include "Jogador1.h"
#include "Jogo.h"

using namespace Abstratas;
using namespace Listas;
using namespace Jogadores;
//using namespace GerenciadoresFases;
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

        virtual ~FabricaFase1();

        virtual Fase *criarFase();
    };
}

#endif //GAME_FABRICAFASE1_H
