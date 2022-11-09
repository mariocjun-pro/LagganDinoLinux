#ifndef GAME_FABRICAFASE_H
#define GAME_FABRICAFASE_H

#include "stdafx.h"
#include "Entidade.h"
#include "ListaEntidade.h"
#include "Jogador.h"
#include "Jogador1.h"
#include "Jogo.h"
#include "Fase.h"

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
    class FabricaFase {
    protected:
        void limpar();

        Jogo *pJogo;

        short idFase;

        Jogador1 *pJogador1;

        Fase *pFase;
    public:
        FabricaFase(Jogo *pJogo = nullptr);

        virtual ~FabricaFase();

        virtual Fase *criarFase() = 0;

        void setJogador1(Jogador1 *pJ1);
    };
}


#endif //GAME_FABRICAFASE_H
