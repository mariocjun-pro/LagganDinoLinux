#ifndef GAME_ESTADO_H
#define GAME_ESTADO_H

#include "stdafx.h"

namespace Fabricas {
    class FabricaFase;
}

using namespace Fabricas;

namespace Estados {
    class Estado {
    private:
        FabricaFase *fabricaFase;
    public:
        Estado();

        virtual ~Estado();

        virtual void executar() = 0;
    };
}

#endif //GAME_ESTADO_H
