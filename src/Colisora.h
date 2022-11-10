#pragma once

#include "stdafx.h"

class Colisora {
public:
    explicit Colisora(RectangleShape *crp);

    ~Colisora();

    bool verificarColisao(Colisora *outro, Vector2f &direcao, float f);

    void mover(float dx, float dy) { corpo->move(dx, dy); }

    //Sets e Gets

    Vector2f getPosicao() { return corpo->getPosition(); }

    Vector2f getTamanhoMetade() { return corpo->getSize() / 2.0f; }

private:
    RectangleShape *corpo;
};

