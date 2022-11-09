#include "Fase1.h"
#include "Jogo.h"
#include "Menu.h"

using namespace Fases;

Fase1::Fase1(Controladoras::Jogo *pJogo) : Fase(pJogo) {
    id = 1;
    srand(unsigned(time(nullptr)));
}

Fase1::~Fase1() {}

void Fase1::executar() {
    listaEntidade.executar();
    listaEntidade.imprimir();
}