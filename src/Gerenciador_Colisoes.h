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
    class Gerenciador_Colisoes {
    public:
        Gerenciador_Colisoes();

        ~Gerenciador_Colisoes();

        bool verificarColisao(Corpo_Grafico *c1, Corpo_Grafico *c2, Vector2f &direcao, float f);

        void colidindo(Entidade *e1, Vector2f direcao);

        bool atacando(Entidade *e1, Entidade *e2, Vector2f &direcao);

        bool colidir(Entidade *e1, Entidade *e2, Vector2f &direcao);

        bool ataque(Entidade *e1, Entidade *e2, Vector2f &direcao);
    };
}