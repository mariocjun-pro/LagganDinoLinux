#include "Projetil.h"

Projetil::Projetil(Gerenciador_Grafico *g) :
Entidade(g), projetil_podeMatar(true), empurrao_projetil(0.0F) {
    podeMatar = projetil_podeMatar;
    podeMorrer = false;
    empurrao = empurrao_projetil;
}

Projetil::~Projetil()
{
}

