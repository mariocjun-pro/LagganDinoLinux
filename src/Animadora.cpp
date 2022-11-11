#include "Animadora.h"


GerenciadoresEntidades::Animadora::Animadora(Corpo_Grafico *corpo) {
    pCorpo = corpo;
    textura = nullptr;

    inicializa(Vector2f(0, 0), Vector2u(0, 0), Vector2u(1, 1));
}

GerenciadoresEntidades::Animadora::~Animadora() {

}

void GerenciadoresEntidades::Animadora::inicializa(Vector2f margemErro, Vector2u quantidadeQuadros,
                                                   Vector2u TotalDeQuadros) {
    qtdQuadros = quantidadeQuadros;
    tempoTotal = 0;
    comeco = 0;
    quadrosAtuais.x = 0;
    quadrosAtuais.y = 0;
    margem = margemErro;

    if (pCorpo) { textura = pCorpo->getTextura(); }

    quadro.width = static_cast<int>(textura->getSize().x / (TotalDeQuadros.x));
    quadro.height = static_cast<int>(textura->getSize().y / (TotalDeQuadros.y));
}

void GerenciadoresEntidades::Animadora::atualizar(float dT, bool aDireita, unsigned int comecoP,
                                                  unsigned int quantidadeQuadrosX, float troca, unsigned int linha) {
    quadrosAtuais.y = linha;
    qtdQuadros.x = quantidadeQuadrosX;
    tempoTotal += dT;
    tempoTroca = troca;
    if (comeco != static_cast<int>(comecoP)) {
        comeco = static_cast<int>(comecoP);
        quadrosAtuais.x = comeco;
    }


    if (tempoTotal >= tempoTroca) {
        tempoTotal -= tempoTroca;
        (quadrosAtuais.x)++;

        if (quadrosAtuais.x >= (qtdQuadros.x + comeco)) {
            quadrosAtuais.x = comeco;
        }
    }

    if (aDireita) {
        quadro.left = static_cast<int>(quadrosAtuais.x * quadro.width);
        quadro.width = abs(quadro.width);
    } else {
        quadro.left = static_cast<int>((quadrosAtuais.x + 1) * abs(quadro.width));
        quadro.width = -abs(quadro.width);
    }

    quadro.top = static_cast<int>(quadrosAtuais.y * quadro.height);

    Vector2f aux(static_cast<float>(quadro.width), static_cast<float>(quadro.height));
    quadro.width += static_cast<int>(margem.x);
    quadro.height += static_cast<int>(margem.y);

    pCorpo->getCorpo()->setTextureRect(quadro);

    quadro.width = static_cast<int>(aux.x);
    quadro.height = static_cast<int>(aux.y);
}

void GerenciadoresEntidades::Animadora::atualizarLinhasSequencial(float dT, bool aDireita, Vector2u quantidadeQuadros,
                                                                  float troca) {
    qtdQuadros.x = quantidadeQuadros.x;
    qtdQuadros.y = quantidadeQuadros.y;
    tempoTotal += dT;
    tempoTroca = troca;


    if (tempoTotal >= tempoTroca) {
        tempoTotal -= tempoTroca;
        (quadrosAtuais.x)++;

        if (quadrosAtuais.x >= qtdQuadros.x) {
            quadrosAtuais.y++;
            quadrosAtuais.x = 0;
            if (quadrosAtuais.y >= (qtdQuadros.y - 1)) {
                quadrosAtuais.y = 0;
            }
        }
    }


    if (aDireita) {
        quadro.left = static_cast<int>(quadrosAtuais.x) * quadro.width;
        quadro.width = abs(quadro.width);
    } else {
        quadro.left = static_cast<int>(quadrosAtuais.x + 1) * abs(quadro.width);
        quadro.width = -abs(quadro.width);
    }

    quadro.top = static_cast<int>(quadrosAtuais.y * quadro.height);

    pCorpo->getCorpo()->setTextureRect(quadro);
}