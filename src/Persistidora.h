#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "Inimigo.h"

using namespace Controladoras;
using namespace Abstratas;
using namespace Auxiliares;
using namespace Jogadores;
using namespace Inimigos;

namespace Controladoras {
    class Persistidora {
    public:
        Persistidora();
        virtual ~Persistidora();

        void gravar(pair<Entidade*, int> p);
        void gravarFase(const unsigned int id);

        //Sets e gets
        void setNome(string n) { nome = n; criarArquivos(); }
    private:
        void gravarJogadores(Jogador* j, int id);
        void gravarObjetos(Entidade* ent, int id);
        void criarArquivos();

        int pontosTotais;
        short doisJogadores;
        string nome;
        string arq[3];
    };
}