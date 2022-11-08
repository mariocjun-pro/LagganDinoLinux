#ifndef GAME_LISTAENTIDADE_H
#define GAME_LISTAENTIDADE_H

#include "stdafx.h"
#include "Entidade.h"
#include "Lista.h"
#include "Jogador.h"

using namespace Listas;
using namespace Abstratas;
//using namespace Jogadores;
//using namespace GerenciadoresFases;

namespace Listas {
    class ListaEntidade {
    public:
        ListaEntidade();

        ~ListaEntidade();

        void executar();

        void imprimir();

        void incluir(Entidade *ent);

        void limpar();

    private:
        Lista<Entidade> LEs;

        static void excluir(Lista<Entidade>::Elemento<Entidade> *no);

    };
}

#endif //GAME_LISTAENTIDADE_H
