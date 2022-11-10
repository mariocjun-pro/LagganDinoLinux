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
#include "Galho.h"
#include "ChefeDino.h"

using namespace Abstratas;
using namespace Listas;
using namespace Jogadores;
using namespace GerenciadoresFases;
using namespace Inimigos;
using namespace Personagens;
using namespace Obstaculos;
using namespace Estados;
using namespace Controladoras;

namespace Fases {
    class Floresta : public Fase {
    public:
        Floresta(Jogo* jooj = NULL, const bool dois = false);
        ~Floresta();

        void executar();

    private:
    };
}
