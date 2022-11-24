#pragma once

#include "stdafx.h"
#include "Entidade.h"

using namespace Abstratas;
using namespace Auxiliares;

namespace Auxiliares {
    class Projetil : public Entidade {
    public:
        Projetil(Gerenciador_Grafico *g = nullptr);

        ~Projetil();

        void executar() {}

        bool get_podeMatar() { return podeMatar; }

    private:
        bool projetil_podeMatar;
        float empurrao_projetil;
    };
}