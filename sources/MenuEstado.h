#ifndef GAME_MENUESTADO_H
#define GAME_MENUESTADO_H

#include "stdafx.h"
#include "Estado.h"

using namespace Estados;

namespace Estados {
    class MenuEstado : public Estado {
    public:
        MenuEstado();

        virtual ~MenuEstado();
    };
}

#endif //GAME_MENUESTADO_H
