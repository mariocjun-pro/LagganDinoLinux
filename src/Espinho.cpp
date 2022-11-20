#include "Espinho.h"

using namespace Obstaculos;

Espinho::Espinho(Gerenciador_Grafico *g) :
        Obstaculo(g) {
    podeMatar = true;
    podeMorrer = false;
    empurrao = 1.0f;

    corpo.inicializa(Vector2f(60.0f, 60.0f), nullptr, Vector2f(1.0f, 1.0f));
    corpo.getCorpo()->setFillColor(Color::White);
    corpo.setTextura("../arquivos/texturas/obstaculos/Espinho.png");
    corpo.inicializaAnimadora(Vector2f(0.0f, 0.0f), Vector2u(1, 1), Vector2u(1, 1));
    corpo.atualizaAnimacao(0.0f, false, 0, 0, 1, 0);

    id = 4;
}

Espinho::~Espinho() {
}
