#include "FabricaFase.h"

using namespace Fabricas;

FabricaFase::FabricaFase(Jogo *pJogo) : pJogo(pJogo), pJogador1(nullptr), pFase(nullptr), id(0) {}

FabricaFase::~FabricaFase() {
    limpar();
}

void FabricaFase::limpar() {
    delete pJogador1;
    delete pFase;
}

