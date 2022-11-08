#ifndef LAGGANDOGAME_JOGO_H
#define LAGGANDOGAME_JOGO_H

#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "Estado.h"
#include "PilhaEstados.h"

// Singleton
namespace Controladoras {
    class Jogo {
    public:
        static Jogo *CriarJogo();

        ~Jogo();

        void executar();

        void tirarEstado(bool excluir = true) { pilha.tirarEstado(excluir); }

        void colocarEstado(Estado *est) { pilha.colocarEstado(est); }

        const bool pilhaVazia() { return pilha.pilhaVazia(); }

        const unsigned int pilhaTam() const { return pilha.pilhaTam(); }

        Estado *getTopo() const { return pilha.getTopo(); }

        PilhaEstados operator--() {
            this->tirarEstado(true);
            return PilhaEstados();
        }

        GerenciadorGrafico *getGerenciador() { return &GG; }

    private:
        Jogo();

        static Jogo *jogoUnico;

        PilhaEstados pilha;

        GerenciadorGrafico GG;
    };
}

#endif //LAGGANDOGAME_JOGO_H
