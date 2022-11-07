#ifndef LAGGANDOGAME_ENTE_H
#define LAGGANDOGAME_ENTE_H

#include "stdafx.h"

class GerenciadorGrafico;

class Ente {
protected:
    GerenciadorGrafico *gerenciador_grafico;
public:
    Ente();

    virtual ~Ente();

    void setGerenciadorGrafico(GerenciadorGrafico *gerenciador_grafico);
};

#endif //LAGGANDOGAME_ENTE_H
