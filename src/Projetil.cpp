#include "Projetil.h"

Projetil::Projetil(Gerenciador_Grafico *g) :
        Entidade(g) {
    podeMatar = true;
    podeMorrer = false;
    empurrao = 0.0f;
}

Projetil::~Projetil() {
}

