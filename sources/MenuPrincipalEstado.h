#ifndef GAME_MENUPRINCIPALESTADO_H
#define GAME_MENUPRINCIPALESTADO_H

#include "stdafx.h"
#include "MenuEstado.h"

class MenuPrincipalEstado : public MenuEstado {
public:
    MenuPrincipalEstado();

    virtual ~MenuPrincipalEstado();

    virtual void executar();
};


#endif //GAME_MENUPRINCIPALESTADO_H
