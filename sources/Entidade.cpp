#include "Entidade.h"

using namespace Abstratas;

Entidade::Entidade(Controladoras::GerenciadorGrafico *gerenciadorGrafico)
        : Ente(), gerenciadorGrafico(gerenciadorGrafico),
          movimentacao(0.0f, 0.0f), vida(10), noChao(true), podeMatar(true),
          podeMorrer(true), empurrao(1.0f) {}

Entidade::~Entidade() {}

void Entidade::imprimir() { gerenciadorGrafico->desenhar(corpoGrafico.getCorpo()); }

