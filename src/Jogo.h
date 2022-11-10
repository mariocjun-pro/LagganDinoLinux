#pragma once
#include "stdafx.h"
#include "Gerenciador_Grafico.h"
#include "Estado.h"
#include "PilhaEstados.h"

using namespace Estados;
// Singleton
namespace Controladoras {
    class Jogo {        
    public:
        static Jogo* CriarJogo();
        ~Jogo();

        
        void executar();

        void tirarEstado(bool excluir = true) { pilha.tirarEstado(excluir); }
        void colocarEstado(Estado* est) { pilha.colocarEstado(est); }
        const bool pilhaVazia() { return pilha.pilhaVazia(); }
        const unsigned int pilhaTam() const { return pilha.pilhaTam(); }
        Estado* getTopo() const { return pilha.getTopo(); }

        PilhaEstados operator--() {
            this->tirarEstado(true);
        }
        //Sets e Gets

        Gerenciador_Grafico* getGerenciador() { return &GG; }
    private:
        Jogo();
        static Jogo* jogoUnico;

        PilhaEstados pilha;

        Gerenciador_Grafico GG;
    };
}