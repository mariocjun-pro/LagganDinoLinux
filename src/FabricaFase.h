#pragma once

#include "stdafx.h"
#include "Entidade.h"
#include "ListaEntidade.h"
#include "Vita.h"
#include "Tard.h"
#include "Gerenciador_Persistencias.h"
#include "Andino.h"
#include "Atiradino.h"
#include "Espinho.h"
#include "ChefeDino.h"
#include "Galho.h"
#include "Pedra.h"
#include "Jogo.h"
#include "Fase.h"
#include "Jogador.h"

using namespace Abstratas;
using namespace Listas;
using namespace Jogadores;
using namespace GerenciadoresFases;
using namespace Inimigos;
using namespace Personagens;
using namespace Obstaculos;
using namespace Controladoras;
using namespace Fases;

namespace Fabricas {
    class FabricaFase {
    public:
        FabricaFase(Jogo *jogo = nullptr);

        virtual ~FabricaFase();

        virtual Fase *criar() = 0;

        void setCarregar(const bool c) { carrega = c; }

        void set2Jogadores(const bool dois) { doisJogadores = dois; }

        void setJogadores(Vita *j1, Tard *j2);

    protected:
        virtual void carregar();

        void limpar();

        Jogo *pJogo;

        bool carrega;

        bool doisJogadores;

        short idFase;

        Vita *j1;

        Tard *j2;

        Fase *fase;

        vector<Plataforma *> plataformas;
    };
}