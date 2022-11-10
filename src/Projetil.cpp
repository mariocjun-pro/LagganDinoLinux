#include "Projetil.h"

Projetil::Projetil(Gerenciador_Grafico* GG):
Entidade(GG)
{
    podeMatar = true;
    podeMorrer = false;
    empurrao = 0.0f;
}

Projetil::~Projetil() {
}

