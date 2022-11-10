#include "Plataforma.h"

Plataforma::Plataforma(Vector2f tam, Texture *tex) {
    corpo.inicializa(tam, tex);
    corpo.setTextura("../Texturas//Plataforma//plat3.png");
    corpo.inicializaAnimadora(Vector2f(0.0f, 0.0f), Vector2u(1, 1), Vector2u(1, 1));

}

Plataforma::~Plataforma() {
}

bool Plataforma::verificarColisao(Colisora *outro, Vector2f &direcao) {
    return corpo.getColisora()->verificarColisao(outro, direcao, 1.0f);
}
