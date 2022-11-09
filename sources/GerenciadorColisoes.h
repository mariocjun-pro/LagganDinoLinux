#ifndef GAME_GERENCIADORCOLISOES_H
#define GAME_GERENCIADORCOLISOES_H

#include "stdafx.h"

namespace GerenciadoresEntidades {
    class CorpoGrafico;
}

using namespace GerenciadoresEntidades;

namespace Abstratas {
    class Entidade;
}

using namespace Abstratas;

namespace GerenciadorFases {
    class GerenciadorColisoes {
    public:
        GerenciadorColisoes() {}

        ~GerenciadorColisoes() {}
    };
}

#endif //GAME_GERENCIADORCOLISOES_H
