#pragma once
#include "stdafx.h"
#include "Obstaculo.h"
#include "Plataforma.h"

using namespace Obstaculos;
using namespace Auxiliares;

namespace Obstaculos {
    class Pedra : public Obstaculo {
    public:
        Pedra(Plataforma* plat);
        ~Pedra();

        void executar();

    private:

    };
}


