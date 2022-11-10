#pragma once
#include "stdafx.h"
#include "Gerenciador_Grafico.h"

using namespace Controladoras;


namespace Controladoras {
    class Fundo {
    public:
        Fundo(unsigned int qtd = 1, Gerenciador_Grafico* GG = NULL);
        virtual ~Fundo();

        void imprimir();

        //Sets e Gets

        void setGerenciador(Gerenciador_Grafico* GG) { pGG = GG; }

        void setPosicao(const Vector2f pos);
        void setTextura(const string s, const int i=0) { textura[i].loadFromFile(s); corpo[i].setTexture(&textura[i]); }

        void setTamanho(const Vector2f tam);

    private:

        RectangleShape* corpo;
        Texture* textura;
        unsigned int qtdFundos;

        Gerenciador_Grafico* pGG;


    };
}