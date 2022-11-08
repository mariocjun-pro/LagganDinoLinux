#ifndef GAME_MENUPRINCIPAL_H
#define GAME_MENUPRINCIPAL_H

#include "stdafx.h"
#include "Menu.h"
#include "Estado.h"
#include "FabricaFase1.h"

using namespace Fabricas;
using namespace Controladoras;
using namespace Estados;
using namespace Fases;

namespace Controladoras {
    class MenuPrincipal : public Menu {
    public:
        MenuPrincipal(Jogo *jogo);

        ~MenuPrincipal();

        void executar();

        void setSelecionado(const int s) { selecionado = s; }

    private:
        Fase1 *fase1;

        FabricaFase1 fabricaFase1;
    };
}

#endif //GAME_MENUPRINCIPAL_H
