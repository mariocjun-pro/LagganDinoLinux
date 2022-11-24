#include "Obstaculo.h"

using namespace Obstaculos;

Obstaculo::Obstaculo(Gerenciador_Grafico *g) :
Entidade(g), obstaculo_danoso(false) {
    podeMatar = obstaculo_danoso;
    podeMorrer = false;
    empurrao = 1.0F;
}

Obstaculo::~Obstaculo()
{
}

