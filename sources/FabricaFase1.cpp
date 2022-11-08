#include "FabricaFase1.h"

using namespace Fabricas;

FabricaFase1::FabricaFase1(Jogo *jogo) : FabricaFase(jogo) {
    id = 1;
}

FabricaFase1::~FabricaFase1() {}

Fase *FabricaFase1::criarFase() {
    pFase = static_cast<Fase *>(new Fase1(pJogo));
    limpar();
    return pFase;
}

void FabricaFase1::instanciaJogador() {
    pJogador1 = new Jogador1(pJogo->getGerenciador());
    pFase->incluirEntidade(static_cast<Entidade *>(pJogador1));
    pFase->setJogador1(pJogador1);
}
