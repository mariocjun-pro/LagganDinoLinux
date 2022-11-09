#ifndef GAME_OBSTACULO_H
#define GAME_OBSTACULO_H

#include "stdafx.h"
#include "Entidade.h"

using namespace Abstratas;

namespace Obstaculos {
    class Obstaculo : public Entidade {
    public:
        Obstaculo(GerenciadorGrafico *g);

        virtual ~Obstaculo();

        virtual void executar() {}
    };
}

#endif //GAME_OBSTACULO_H
