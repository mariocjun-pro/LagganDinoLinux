#include "FabricaFase.h"

using namespace Fabricas;

FabricaFase::FabricaFase(Jogo *pJogo) : pJogo(pJogo), pJogador1(nullptr), pFase(nullptr), idFase(0), carrega(false) {}

FabricaFase::~FabricaFase() { limpar(); }

void FabricaFase::limpar() { }

void FabricaFase::setJogador1(Jogador1 *pJ1) {
    pJogador1 = new Jogador1(pJogo->getGerenciador());
    pJogador1->setPosicao(sf::Vector2f(pJogador1->getPosicao().x, -1000.f));
}



