#pragma once
#include "stdafx.h"
#include "Gerenciador_Grafico.h"
#include "Fundo.h"
#include "Jogo.h"
#include "Montanha.h"
#include "Floresta.h"
#include "MenuEstado.h"
#include "FabricaFloresta.h"
#include "FabricaMontanha.h"

using namespace Fabricas;
using namespace Estados;
using namespace Fases;


namespace Controladoras {
    class Menu : public MenuEstado {
    public:
        Menu(Jogo* jogo = NULL);
        ~Menu();

        void executar();

        void leEntradas();
        void posicionarTexto();
        void carregar(string nome = "SemNome");
        void limparEstados();
        void exibeRanking();
        void leTexto();
        void salvaPontuacao();

        //Sets e gets
        void setPressionar(const bool press) { pressionar = press; }
        void setJogo(Jogo* jogo) { pJogo = jogo; }
        void setPontos(const int p) { pontos = p; }
        void setLendoTexto(const bool l);
    protected:
        Jogo* pJogo;
        Gerenciador_Grafico* pGG;

        int opcao;
        int selecionado;
        bool pressionar;
        
        bool lendoTexto;
        bool ranking;
        bool lido;

        Fundo fundo;

        Font fonte;
        vector<Text> texto;
        
        Text leitura;
        string sleitura;

        float totalT;
        
        int pontos;
        
        vector<pair<string, int>> rank;
        vector<Text> textoRank;
    };

}
