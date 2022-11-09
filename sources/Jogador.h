#ifndef GAME_JOGADOR_H
#define GAME_JOGADOR_H

#include "stdafx.h"
#include "Personagem.h"

using namespace Personagens;
using namespace Auxiliares;

namespace Jogadores {
    class Jogador : public Personagem {
    public:
        Jogador(GerenciadorGrafico *gerenciador = nullptr);

        virtual ~Jogador();

        void imprimir();

        virtual void executar() = 0;

    protected:
        sf::Vector2f posInicial;

        float pulo;
    };
}

#endif //GAME_JOGADOR_H
