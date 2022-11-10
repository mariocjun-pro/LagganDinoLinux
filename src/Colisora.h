#pragma once
#include "stdafx.h"

namespace GerenciadoresEntidades {
    class Corpo_Grafico;
}
using namespace GerenciadoresEntidades;

namespace Abstratas {
    class Entidade;
}

using namespace Abstratas;

namespace GerenciadoresFases {
    class Colisora {
    public:
        Colisora();
        ~Colisora();

        bool verificarColisao(Corpo_Grafico* c1, Corpo_Grafico* c2, Vector2f& direcao, float f);

        void colidindo(Entidade* e1, Vector2f direcao);

        bool atacando(Entidade* e1, Entidade* e2, Vector2f& direcao);
        bool colidir(Entidade* e1, Entidade* e2, Vector2f& direcao);
        bool ataque(Entidade* e1, Entidade* e2, Vector2f& direcao);


        //Sets e Gets

    private:
    };

}