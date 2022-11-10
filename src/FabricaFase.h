#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "ListaEntidade.h"
#include "Guigo.h"
#include "Titi.h"
#include "Persistidora.h"
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
        FabricaFase(Jogo* jogo = NULL);
        virtual ~FabricaFase();
        
        virtual Fase* criar() = 0;
        
        
        
        //Sets e Gets
        void setCarregar(const bool c) { carrega = c; }
        void setDoisJogadores(const bool dois) { doisJogadores = dois; }
        void setJogadores(Guigo* jog1, Titi* jog2);
        
    protected:
        
        virtual void carregar();
        void limpar();
        
        Jogo* pJogo;
        bool carrega;
        bool doisJogadores;
        
        short idFase;
        
        Guigo* j1;
        Titi* j2;
        
        
        Fase* fase;
        vector<Plataforma*> plataformas;
    };
}