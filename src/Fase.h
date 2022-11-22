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
#include "FaseEstado.h"
#include "Fundo.h"

using namespace Abstratas;
using namespace Listas;
using namespace Jogadores;
using namespace GerenciadoresFases;
using namespace Inimigos;
using namespace Personagens;
using namespace Obstaculos;
using namespace Controladoras;
using namespace Estados;


namespace Fases {
    class Fase : public FaseEstado {
    public:
        Fase(Jogo *jooj = nullptr, bool dois = false);

        virtual ~Fase();

        //virtual void instanciaFundo() = 0;
        virtual void executar();

        virtual void gerenciar_colisoes();

        virtual void reiniciar();

        void pontuacao();

        void salvar(string nome = "SemNome");

        void menuPause();

        void incluirEntidade(Entidade *ent) { entidades.incluir(ent); }

        //Sets e Gets
        Vita *getJogador1() { return jogador1; }

        Tard *getJogador2() { return jogador2; }

        void setJogador1(Vita *j1) { jogador1 = j1; }

        void setJogador2(Tard *j2) { jogador2 = j2; }

        void setFundo(Fundo *f) { fundo = f; }

        void setJogo(Jogo *jooj) { pJogo = jooj; }

    protected:
        ListaEntidade entidades;

        Vita *jogador1;
        Tard *jogador2;

        Jogo *pJogo;
        Gerenciador_Persistencias pers;
        Gerenciador_Colisoes *colisora;
        Fundo *fundo;

        bool doisJogadores;

        unsigned short id;

        Gerenciador_Grafico *pGG;
    };
}

