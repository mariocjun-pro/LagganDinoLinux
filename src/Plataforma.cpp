#include "Plataforma.h"

Plataforma::Plataforma(Vector2f tam) {
    idPlataforma = contIdPlataforma++;
    podeMatar = false;
    podeMorrer = false;
    empurrao = 1.0f;

    corpo.inicializa(tam, NULL, Vector2f(tam.x - (tam.x / 9.5f), tam.y));

    if (tam.x < 500.0f)
        corpo.setTextura("../Texturas/Plataforma/PlatGramaP.png");

    else if (tam.x < 1000.0f)
        corpo.setTextura("../Texturas/Plataforma/PlatGramaM.png");

    else
        corpo.setTextura("../Texturas/Plataforma/PlatGramaG.png");

    corpo.inicializaAnimadora(Vector2f(0.0f, 0.0f), Vector2u(1, 1), Vector2u(1, 1));

}

Plataforma::~Plataforma() {

}

int Plataforma::contIdPlataforma = 0;