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
    private:
        string voltar_str;
        string salvar_str;
        string ranking_str;
        string carregar_str;
        string sair_str;
    };
}

