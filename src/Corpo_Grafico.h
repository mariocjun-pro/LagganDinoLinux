#pragma once
#include "stdafx.h"
#include "Colisora.h"

namespace GerenciadoresEntidades {
    class Animadora;
}


using namespace GerenciadoresEntidades;
using namespace GerenciadoresFases;

namespace GerenciadoresEntidades {
    class Corpo_Grafico {
    public:
        Corpo_Grafico();
        virtual ~Corpo_Grafico();

        void inicializa(Vector2f tam, Texture* tex, Vector2f margemHitbox = Vector2f(0.0f, 0.0f));

        void operator=(const Vector2f pos) { setPosicao(pos); }

        void mover(Vector2f incr) { corpo->move(incr); hitbox->move(incr); }
        void mover(float x, float y) { corpo->move(x, y); hitbox->move(x, y); }

        void inicializaAnimadora (Vector2f margem, Vector2u quantidadeQuadros, Vector2u TotalDeQuadros);
        void atualizaAnimacao (float dT, bool aDireita, unsigned int comecoP=0, unsigned int quantidadeQuadrosX=4, float troca=0.3f, unsigned int linha=0);
        //Sets e Gets

        RectangleShape* getCorpo() { return corpo; }
        RectangleShape* getHitbox() { return hitbox; }

        Vector2f getPosicao() { return corpo->getPosition(); }
        Vector2f getTamanho() { return corpo->getSize(); }

        Texture* getTextura () { return textura; }
        void setTextura (string arquivo) { textura->loadFromFile(arquivo); }

        void setPosicao(Vector2f pos) { corpo->setPosition(pos); hitbox->setPosition(pos); }
        void setPosicao(float x, float y) { corpo->setPosition(x, y); hitbox->setPosition(x, y); }

        Animadora* getAnimadora () { return animacao; }

    private:
        RectangleShape* corpo;
        Animadora* animacao;
        Texture* textura;
        RectangleShape* hitbox;
    };
}

