#ifndef LAGGANDOGAME_JOGO_H
#define LAGGANDOGAME_JOGO_H

#include "stdafx.h"
#include "GerenciadorGrafico.h"

// Singleton
namespace Controladoras {
    class Jogo {
    public:
        static Jogo *CriarJogo();

        ~Jogo();

        void executar();

        GerenciadorGrafico *getGerenciador() { return &GG; }

    private:
        Jogo();

        static Jogo *jogoUnico;

        GerenciadorGrafico GG;
    };
}

#endif //LAGGANDOGAME_JOGO_H
