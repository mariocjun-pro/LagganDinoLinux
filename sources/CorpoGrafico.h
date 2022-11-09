#ifndef GAME_CORPOGRAFICO_H
#define GAME_CORPOGRAFICO_H

#include "stdafx.h"
#include "GerenciadorColisoes.h"

namespace GerenciadoresEntidades {
    class Animadora;
}

using namespace GerenciadoresEntidades;
using namespace GerenciadoresEntidades;

namespace GerenciadoresEntidades {
    class CorpoGrafico {
    private:
        sf::RectangleShape *corpo;
        sf::Texture *textura;
        Animadora *animacao;
    public:
        CorpoGrafico();

        virtual ~CorpoGrafico();

        void inicializa(sf::Vector2f tamanho, sf::Texture *pTexture,
                        sf::Vector2f margemHitbox = sf::Vector2f(0.0f, 0.0f));

        void operator=(const sf::Vector2f posicao) { setPosicao(posicao); }

        void mover(sf::Vector2f incr) {
            corpo->move(incr);
        }

        void mover(float x, float y) {
            corpo->move(x, y);
        }

        void inicializaAnimadora(sf::Vector2f margem, sf::Vector2u quantidadeQuadros, sf::Vector2u TotalDeQuadros);

        void atualizaAnimacao(float dT, bool aDireita, unsigned int comecoP = 0, unsigned int quantidadeQuadrosX = 4,
                              float troca = 0.3f, unsigned int linha = 0);

        sf::RectangleShape *getCorpo() { return corpo; }

        sf::Vector2f getPosicao() { return corpo->getPosition(); }

        sf::Texture *getTextura() { return textura; }

        void setTextura(string arquivo) { textura->loadFromFile(arquivo); }

        void setPosicao(sf::Vector2f pos) {
            corpo->setPosition(pos);
        }
    };
}

#endif //GAME_CORPOGRAFICO_H
