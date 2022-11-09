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

        void entraString(char c);
    };
}

#endif //LAGGANDOGAME_GERENCIADORGRAFICO_H
