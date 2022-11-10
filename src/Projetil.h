#pragma once
#include "stdafx.h"
#include "Entidade.h"

using namespace Abstratas;
using namespace Auxiliares;

namespace Auxiliares {
    class Projetil : public Entidade {
    public:
        Projetil(Gerenciador_Grafico* GG = NULL);
        ~Projetil();

        void executar() { }

    private:

    };
}