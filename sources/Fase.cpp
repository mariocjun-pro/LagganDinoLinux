#include "Fase.h"

using namespace Fases;

Fase::Fase(Jogo *pJogo) : jogador1(nullptr), jogo(pJogo) {
    gerenciadorGrafico = pJogo->getGerenciador();
    id = -1;
}

Fase::~Fase() {
    delete listaEntidade;
    delete jogador1;
}

void Fase::executar() {}
