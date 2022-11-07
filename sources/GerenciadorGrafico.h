#ifndef LAGGANDOGAME_GERENCIADORGRAFICO_H
#define LAGGANDOGAME_GERENCIADORGRAFICO_H

#include "stdafx.h"
#include "Entidade.h"
#include "Texto.h"

class Jogo;

class GerenciadorGrafico {
private:
    sf::RenderWindow window;
public:
    GerenciadorGrafico();

    ~GerenciadorGrafico();

    void loop();

};

#endif //LAGGANDOGAME_GERENCIADORGRAFICO_H
