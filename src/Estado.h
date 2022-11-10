#pragma once
#include "stdafx.h"

namespace Fabricas {
    class FabricaFase;
}

using namespace Fabricas;

namespace Estados {
    class Estado {
    public:
        Estado();
        virtual ~Estado();

        virtual void executar() = 0;
    private:
      FabricaFase* fabrica; 

    };
}

