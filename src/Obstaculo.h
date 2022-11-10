#pragma once
#include "stdafx.h"
#include "Entidade.h"

using namespace Abstratas;

namespace Obstaculos {
    class Obstaculo : public Entidade {
    public:
        Obstaculo(Gerenciador_Grafico* g);
        virtual ~Obstaculo();

        virtual void executar() {}
    protected:

    };
}


