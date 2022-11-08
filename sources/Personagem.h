#ifndef GAME_PERSONAGEM_H
#define GAME_PERSONAGEM_H

#include "stdafx.h"
#include "Entidade.h"

using namespace Abstratas;
using namespace Auxiliares;

namespace Personagens {
    class Personagem : public Entidade {
    protected:
        float velocidade;
        bool atacando;
        float totalT;
        bool aDireita;
        short int lado;
        bool tomarDano;
        bool ferido;
        bool ataquePronto;
    public:
        Personagem(GerenciadorGrafico *gerenciadorGrafico = nullptr);

        virtual ~Personagem();

        virtual void imprimir();

        virtual void executar();

        virtual void animar(sf::Vector2f movimento);
    };
}

#endif //GAME_PERSONAGEM_H
