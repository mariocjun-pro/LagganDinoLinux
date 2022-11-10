#pragma once
#include "stdafx.h"
#include "Fase.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "Guigo.h"
#include "Andino.h"
#include "Espinho.h"
#include "Colisora.h"
#include "Pedra.h"
#include "Fundo.h"
#include "Gerenciador_Grafico.h"
#include "Atiradino.h"
#include "Floresta.h"
#include "FabricaFloresta.h"

using namespace Abstratas;
using namespace Listas;
using namespace Jogadores;
using namespace GerenciadoresFases;
using namespace Inimigos;
using namespace Personagens;
using namespace Obstaculos;
using namespace Estados;
using namespace Fabricas;

namespace Fases {
    class Montanha : public Fase {
    public:
        Montanha(Jogo* jooAj = NULL, bool dois = false);
        ~Montanha();

        void executar();
        void trocaFase();

    private:
        FabricaFloresta fab;
        
    };
}

