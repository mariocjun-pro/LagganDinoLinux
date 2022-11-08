#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "Jogo.h"
#include "Fase1.h"
#include "FabricaFase1.h"
#include "MenuEstado.h"

using namespace Fabricas;
using namespace Estados;
using namespace Fases;

namespace Controladoras {
    class Menu : public MenuEstado {
    public:
        Menu(Jogo *jogo = NULL);

        ~Menu();

        void executar();

        void leEntradas();

        void posicionarTexto();

        void setPressionar(const bool press) { pressionar = press; }

        void setJogo(Jogo *jogo) { pJogo = jogo; }

        void setPontos(const int p) { pontos = p; }

    protected:
        Jogo *pJogo;
        GerenciadorGrafico *pGG;

        int opcao;
        int selecionado;
        bool pressionar;

        bool lendoTexto;
        bool ranking;
        bool lido;

        sf::Font fonte;
        vector<sf::Text> texto;

        sf::Text leitura;
        string sleitura;

        float totalT;

        int pontos;

        vector<pair<string, int>> rank;
        vector<sf::Text> textoRank;
    };

}

#endif //GAME_MENU_H
