#pragma once

#include "stdafx.h"
#include "Inimigo.h"
#include "Plataforma.h"

using namespace Auxiliares;

namespace Inimigos {
    class Andino : public Inimigo {
    public:
        Andino(Plataforma *p);

        ~Andino();

        void mover();

    private:
        float pulo;
    };
}