#ifndef GAME_JOGADOR_H
#define GAME_JOGADOR_H

#include "stdafx.h"
#include "Personagem.h"
#include "Projetil.h"

using namespace Personagens;
using namespace Auxiliares;

namespace Jogadores {
    class Jogador : public Personagem {
    public:
        Jogador(GerenciadorGrafico *gerenciador = NULL);

        virtual ~Jogador();

        void morrer();

        void morrer(sf::Vector2f pos);

        void imprimir();

        virtual void executar() = 0;

        //Sets e Gets

        void setAtacando(const bool atac) { atacando = atac; }

        bool getAtacando() const { return atacando; }

        CorpoGrafico *getHitbox() { return hitbox->getCorpoGrafico(); }

        Projetil *getProjetil() { return hitbox; }

        void setPontos(const int p) { pontos = p; }

        int getPontos() const { return pontos; }

    protected:
        sf::Vector2f posInicial;
        Projetil *hitbox;
        bool ataquePronto;
        short ladoAtaque;

        int pontos;
        float pulo;

        //Auxiliares
        float vJog;
    };
}

#endif //GAME_JOGADOR_H
