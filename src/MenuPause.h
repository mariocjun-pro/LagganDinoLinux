#pragma once

#include "stdafx.h"
#include "Menu.h"
#include "MenuPrincipal.h"

using namespace Controladoras;
using namespace Estados;

namespace Controladoras {
    class MenuPause : public Menu {
    public:
        MenuPause(Jogo *j);

        virtual ~MenuPause();

        void executar();
    };
}

