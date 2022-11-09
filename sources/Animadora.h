#ifndef GAME_ANIMADORA_H
#define GAME_ANIMADORA_H

#include "stdafx.h"
#include "CorpoGrafico.h"

namespace GerenciadoresEntidades {
    class CorpoGrafico;
}

using namespace GerenciadoresEntidades;

namespace GerenciadoresEntidades {
    class Animadora {
    private:
        CorpoGrafico *pCorpoGrafico;

        sf::IntRect quadro;
        sf::Texture *textura;

        int inicio;
        sf::Vector2u quadrosAtuais;
        sf::Vector2u qtsQuadros;
        sf::Vector2f margem;
        float tempoTroca;
        float tempoTotal;
    public:
        Animadora(CorpoGrafico *pCorpo = nullptr);

        ~Animadora();

        void inicializa(sf::Vector2f margemErro, sf::Vector2u qtsQuadros, sf::Vector2u totalQuadros);

        void atualizar(float dT, bool aDireita, unsigned int comecoP, unsigned int quantidadeQuadrosX, float troca,
                       unsigned int linha);

        void atualizarLinhasSequencial(float dT, bool aDireita, sf::Vector2u quantidadeQuadros,
                                       unsigned int quadrosUltimaLinha, float troca);
    };
}

#endif //GAME_ANIMADORA_H
