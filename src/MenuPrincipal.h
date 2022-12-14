#pragma once

#include "stdafx.h"
#include "Menu.h"
#include "Estado.h"
#include "Montanha.h"
#include "Floresta.h"
#include "FabricaMontanha.h"
#include "FabricaFloresta.h"

using namespace Fabricas;
using namespace Controladoras;
using namespace Estados;
using namespace Fases;


namespace Controladoras {
    class MenuPrincipal : public Menu {
    public:
        MenuPrincipal(Jogo *j);

        ~MenuPrincipal();

        void executar();

    private:
        FabricaMontanha fab1;
        FabricaFloresta fab2;

    };
}
