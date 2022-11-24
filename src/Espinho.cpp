#include "Espinho.h"

using namespace Obstaculos;

Espinho::Espinho(Gerenciador_Grafico *g) :
Obstaculo(g), danoso(true) {
    podeMatar = danoso;
    podeMorrer = false;
    empurrao = 1.0F;

    corpo.inicializa(Vector2f(60.0F, 60.0F), nullptr, Vector2f(1.0F, 1.0F));
    corpo.getCorpo()->setFillColor(Color::White);
    corpo.setTextura("../arquivos/texturas/obstaculos/Espinho.png");
    corpo.inicializaAnimadora(Vector2f(0.0F, 0.0F), Vector2u(1, 1), Vector2u(1, 1));
    corpo.atualizaAnimacao(0.0F, false, 0, 0, 1, 0);

    id = 4;
}

Espinho::~Espinho() {
}
