#include "Entidade.h"
#include "GerenciadorGrafico.h"

int Entidade::idObjetoAtual = 0;

Entidade::Entidade() : Ente(), movimento_x(0), movimento_y(0), idObjeto(0) {}

Entidade::~Entidade() {}


