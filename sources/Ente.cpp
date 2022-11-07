#include "Ente.h"

Ente::Ente() {
    gerenciador_grafico = nullptr;
}

Ente::~Ente() {}

void Ente::setGerenciadorGrafico(GerenciadorGrafico *_gerenciador_grafico) {
    this->gerenciador_grafico = _gerenciador_grafico;
}