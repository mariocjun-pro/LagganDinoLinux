#ifndef LAGGANDOGAME_GERENCIADORGRAFICO_H
#define LAGGANDOGAME_GERENCIADORGRAFICO_H

#include "stdafx.h"

namespace Controladoras {
    class GerenciadorGrafico {
    private:
        sf::RenderWindow janela;
        sf::View visao;
        sf::Font fonte;
        sf::Text texto;
        string textoDigitado;
        float dT;
        char caracter;
        bool leitura;
    public:
        GerenciadorGrafico();

        virtual ~GerenciadorGrafico();

        sf::RenderWindow *getJanela() { return &janela; }

        bool getAberto() { return janela.isOpen(); }

        sf::View *getVisao() { return &visao; }

        void setDT(float d) { this->dT = d; }

        float getDT() const { return dT; }

        void limpar();

        void leEventos();

        void desenhar(sf::RectangleShape *forma) { janela.draw(*forma); }

        void instaciaTexto();

        void imprimePontuacao(int p, int v);

        void imprimePontuacao(int p, int v, int p2, int v2);

        char getCaracter() const { return caracter; }

        void setLeitura(const bool l) { this->leitura = l; }

        void entraString(char c);

        void limpaTextoDigitado() { textoDigitado = ""; }

        string getTextoDigitado() const { return textoDigitado; }

    };
}

#endif //LAGGANDOGAME_GERENCIADORGRAFICO_H
