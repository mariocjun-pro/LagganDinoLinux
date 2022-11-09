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
    protected:
        Jogo *pJogo;
        GerenciadorGrafico *pGG;

        int opcao;
        int selecionado;
        bool pressionar;
        bool lendoTexto;

        sf::Font fonte;
        vector<sf::Text> texto;

        sf::Text leitura;
        string sleitura;

        float totalT;

        vector<pair<string, int>> rank;
        vector<sf::Text> textoRank;
    public:
        Menu(Jogo *jogo = nullptr);

        ~Menu();

        void executar();

        void leEntradas();

        void leTexto();

        void posicionarTexto();

        void limparEstados();

        void setPressionar(const bool press) { pressionar = press; }

        void setJogo(Jogo *jogo) { pJogo = jogo; }

        void setLendoTexto(const bool l);
    };

}

#endif //GAME_MENU_H
