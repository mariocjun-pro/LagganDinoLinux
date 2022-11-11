#pragma once

#include "stdafx.h"
#include "Entidade.h"

using namespace Abstratas;
using namespace Auxiliares;

namespace Auxiliares {
    class Projetil : public Entidade {
    public:
        explicit Projetil(Gerenciador_Grafico *GG = nullptr);

        ~Projetil();

        void executar() {}

    private:

    };
}