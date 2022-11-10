#pragma once
#include "stdafx.h"
#include "FabricaFase.h"
#include "Montanha.h"
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
#include "AtiradinoThread.h"

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
    class FabricaMontanha : public FabricaFase {
    public:
        FabricaMontanha(Jogo* jogo = NULL);
        ~FabricaMontanha();
        
        Fase* criar();
        
    private:
        void instanciaJogadores();
        void instanciaPlataformas();
        void instanciaInimigos(Plataforma* plat);
        void instanciaObstaculos(Plataforma* plat);
        void instanciaFundo();

    };
}

