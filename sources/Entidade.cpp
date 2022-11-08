#include "Entidade.h"
#include "Plataforma.h"

using namespace Abstratas;

Entidade::Entidade(Controladoras::GerenciadorGrafico *gerenciadorGrafico)
        : Ente(), gerenciadorGrafico(gerenciadorGrafico), plataforma(nullptr),
          movimentacao(0.0f, 0.0f), vida(10), noChao(true), podeMatar(true),
          podeMorrer(true), morto(false), empurrao(1.0f), id(-1) {}

Entidade::~Entidade() {}

void Entidade::imprimir() { gerenciadorGrafico->desenhar(corpoGrafico.getCorpo()); }

bool Entidade::tomarDano() {
    if (podeMorrer) {
        vida--;
        if (vida <= 0) {
            morto = true;
            return true;
        }
    }
    return false;
}

