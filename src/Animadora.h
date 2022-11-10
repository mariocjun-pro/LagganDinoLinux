#pragma once
#include "stdafx.h"
#include "Corpo_Grafico.h"


namespace GerenciadoresEntidades {
    class Corpo_Grafico;
}

using namespace GerenciadoresEntidades;

namespace GerenciadoresEntidades {
    class Animadora {
    public:
        Animadora(Corpo_Grafico* corpo = NULL);
        ~Animadora();

        void inicializa(Vector2f margemErro, Vector2u quantidadeQuadros, Vector2u TotalDeQuadros);
        void atualizar(float dT, bool aDireita, unsigned int comecoP, unsigned int quantidadeQuadrosX, float troca, unsigned int linha);
        void atualizarLinhasSequencial(float dT, bool aDireita, Vector2u quantidadeQuadros, unsigned int quadrosUltimaLinha, float troca);
    private:
        Corpo_Grafico* pCorpo;

        sf::IntRect quadro;
        Texture* textura;

        int comeco;
        Vector2u quadrosAtuais;
        Vector2u qtdQuadros;
        Vector2f margem;
        float tempoTroca;
        float tempoTotal;
    };
}

