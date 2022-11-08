#include "Animadora.h"

GerenciadoresEntidades::Animadora::Animadora(::CorpoGrafico *corpoGrafico) : pCorpoGrafico(corpoGrafico),
                                                                             textura(nullptr) {
    inicializa(sf::Vector2f(0.0f, 0.0f), sf::Vector2u(0, 0), sf::Vector2u(1, 1));
}

GerenciadoresEntidades::Animadora::~Animadora() {
    delete textura;
}

void GerenciadoresEntidades::Animadora::inicializa(sf::Vector2f margemErro, sf::Vector2u quantidadeQuadros,
                                                   sf::Vector2u totalQuadros) {
    quantidadeQuadros = qtsQuadros;
    tempoTroca = 0.3f;
    tempoTotal = 0.0f;
    inicio = 0;
    quadrosAtuais.x = 0;
    quadrosAtuais.y = 0;
    margem = margemErro;

    if (pCorpoGrafico) textura = pCorpoGrafico->getTextura();

    quadro.width = textura->getSize().x / totalQuadros.x;
    quadro.height = textura->getSize().y / totalQuadros.y;
}

void GerenciadoresEntidades::Animadora::atualizar(float dT, bool aDireita, unsigned int comecoP,
                                                  unsigned int quantidadeQuadrosX, float troca,
                                                  unsigned int linha) {
    quadrosAtuais.y = linha;
    qtsQuadros.x = quantidadeQuadrosX;
    tempoTotal += dT;
    tempoTroca = troca;

    if (inicio != comecoP) {
        inicio = comecoP;
        quadrosAtuais.x = 0;
    }

    if (tempoTotal >= tempoTroca) {
        tempoTotal -= tempoTroca;
        quadrosAtuais.x++;

        if (quadrosAtuais.x >= qtsQuadros.x) {
            quadrosAtuais.x = 0;
        }
    }

    if (aDireita) {
        quadro.left = (quadro.width * quadrosAtuais.x) + inicio;
        quadro.width = abs(quadro.width);
    } else {
        quadro.left = ((quadro.width * quadrosAtuais.x) + inicio) + quadro.width;
        quadro.width = -abs(quadro.width);
    }

    quadro.top = quadro.height * quadrosAtuais.y;

    sf::Vector2f aux(quadro.width, quadro.height);
    quadro.width += margem.x;
    quadro.height += margem.y;

    pCorpoGrafico->getCorpo()->setTextureRect(quadro);

    quadro.width = aux.x;
    quadro.height = aux.y;
}

void GerenciadoresEntidades::Animadora::atualizarLinhasSequencial(float dT, bool aDireita,
                                                                  sf::Vector2u quantidadeQuadros,
                                                                  unsigned int quadrosUltimaLinha,
                                                                  float troca) {
    qtsQuadros = quantidadeQuadros;
    tempoTotal += dT;
    tempoTroca = troca;

    if (tempoTotal >= tempoTroca) {
        tempoTotal -= tempoTroca;
        quadrosAtuais.x++;

        if (quadrosAtuais.x >= qtsQuadros.x) {
            quadrosAtuais.x = 0;
            quadrosAtuais.y++;

            if (quadrosAtuais.y >= qtsQuadros.y) {
                quadrosAtuais.y = 0;
            }
        }
    }

    if (aDireita) {
        quadro.left = quadro.width * quadrosAtuais.x;
        quadro.width = abs(quadro.width);
    } else {
        quadro.left = (quadro.width * quadrosAtuais.x) + quadro.width;
        quadro.width = -abs(quadro.width);
    }

    quadro.top = quadro.height * quadrosAtuais.y;

    pCorpoGrafico->getCorpo()->setTextureRect(quadro);
}