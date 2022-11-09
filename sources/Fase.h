#ifndef GAME_FASE_H
#define GAME_FASE_H

#include "stdafx.h"
#include "Entidade.h"
#include "ListaEntidade.h"
#include "Jogador1.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Jogo.h"
#include "FaseEstado.h"

using namespace Abstratas;
using namespace Listas;
using namespace Jogadores;
using namespace GerenciadorFases;
//using namespace Inimigos;
using namespace Personagens;
//using namespace Obstaculos;
using namespace Controladoras;
using namespace Estados;

namespace Fases {
    class Fase : FaseEstado {
    protected:
        ListaEntidade listaEntidade;
        Jogador1 *jogador1;
        GerenciadorGrafico *gerenciadorGrafico;
        Jogo *jogo;
        unsigned int id;
    public:
        Fase(Jogo *jogo = nullptr);

        virtual ~Fase();

        virtual void executar();

        void incluirEntidade(Entidade *entidade) { listaEntidade.incluir(entidade); }

        Jogador1 *getJogador1() { return jogador1; }

        void setJogador1(Jogador1 *pJogador1) { this->jogador1 = pJogador1; }

        void setJogo(Jogo *pJogo) { this->jogo = pJogo; }
    };
}

#endif //GAME_FASE_H
