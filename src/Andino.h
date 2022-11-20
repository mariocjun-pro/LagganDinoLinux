#pragma once

#include "stdafx.h"
#include "Inimigo.h"
#include "Plataforma.h"

using namespace Auxiliares;

namespace Inimigos {
    class Andino : public Inimigo {
    public:
        Andino(Plataforma *plataforma);

        ~Andino();

        void mover();

        void randomiza() { srand(time(nullptr)); }

    private:
        float pulo;
    };
}