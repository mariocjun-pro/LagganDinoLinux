#ifndef LAGGANDOGAME_JOGO_H
#define LAGGANDOGAME_JOGO_H

#include "stdafx.h"
#include "GerenciadorGrafico.h"

class Jogo {
private:
    GerenciadorGrafico gerenciador_grafico;
public:
    Jogo();

    ~Jogo();

    void Executar();

    void Loop();
};

#endif //LAGGANDOGAME_JOGO_H
