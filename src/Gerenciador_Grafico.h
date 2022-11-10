#pragma once
#include "stdafx.h"



namespace Controladoras {
    class Gerenciador_Grafico {
    public:
        Gerenciador_Grafico();
        virtual ~Gerenciador_Grafico();

        RenderWindow* getJanela() { return &janela; }
        bool getAberto () const { return janela.isOpen(); }
        View* getVisao () { return &visao; }

        void setDt(float delta) {dT = delta;}
        const float getDt () const {return dT;}

        void limpar ();
        void leEventos ();
        void desenhar (RectangleShape* elem) { janela.draw(*elem); }

        void instanciaTexto();
        void imprimePontuacao(int p, int v);
        void imprimePontuacao(int p, int v, int p2, int v2);
        
        const char getCaracter() const { return caracter; }
        
        void setLeitura(const bool l) { leitura = l; }
        void entraString(char c);
        void limpaEntradas() { entrada = ""; }
        
        string getEntrada() const { return entrada; }
        
    private:
        RenderWindow janela;
        View visao;
        float dT;

        Font fonte;
        Text texto;
        
        char caracter;
        string entrada;
        
        bool leitura;
    };
}


