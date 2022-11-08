#ifndef GAME_GERENCIADORCOLISOES_H
#define GAME_GERENCIADORCOLISOES_H

#include "stdafx.h"

namespace GerenciadoresEntidades {
    class CorpoGrafico;
}

using namespace GerenciadoresEntidades;

namespace Abstratas {
    class Entidade;
}

using namespace Abstratas;

namespace GerenciadorFases {
    class GerenciadorColisoes {
    public:
        GerenciadorColisoes();

        ~GerenciadorColisoes();

        bool verificaColisao(CorpoGrafico *c1, CorpoGrafico *c2, sf::Vector2f &direcao, float f);

        void colidindo(Entidade *e1, sf::Vector2f direcao);

        bool atacando(Entidade *e1, Entidade *e2, sf::Vector2f &direcao);

        bool colidir(Entidade *e1, Entidade *e2, sf::Vector2f &direcao);

        bool ataque(Entidade *e1, Entidade *e2, sf::Vector2f &direcao);
    };
}

#endif //GAME_GERENCIADORCOLISOES_H
