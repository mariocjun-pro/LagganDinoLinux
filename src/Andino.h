#pragma once
#include "stdafx.h"
#include "Inimigo.h"
#include "Plataforma.h"

using namespace Auxiliares;

namespace Inimigos {
    class Andino : public Inimigo {
    public:
        //Andino(Gerenciador_Grafico* g = NULL, Vector3f f = Vector3f(0.0f, 0.0f, 0.0f));
        Andino(Plataforma* plataforma);
        ~Andino();

        void mover();
        //void morrer();

        void randomiza() {
            srand(time(NULL));

        }
    private:
        float pulo;
    };
}