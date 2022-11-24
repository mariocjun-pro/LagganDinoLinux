#pragma once

#include "stdafx.h"
#include "Entidade.h"
#include "Lista.h"
#include "Jogador.h"
#include "Gerenciador_Persistencias.h"

using namespace Listas;
using namespace Abstratas;
using namespace Jogadores;
using namespace GerenciadoresFases;

namespace Listas {
    class ListaEntidade {
    public:
        ListaEntidade();

        ~ListaEntidade();

        void executar();

        void imprimir();

        void colidir(Jogador *j, Gerenciador_Colisoes *colisora);

        void colidir(Jogador *j, Jogador *j2, Gerenciador_Colisoes *colisora);

        void incluir(Entidade *ent);

        void gravar(Gerenciador_Persistencias *pers);

        void limpar();

    private:
        Lista<Entidade> LEs;

        void excluir(Lista<Entidade>::Elemento<Entidade> *no);

    };
}


