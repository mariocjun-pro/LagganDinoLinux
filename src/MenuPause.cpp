#include "MenuPause.h"
#include "Jogo.h"

MenuPause::MenuPause(Jogo* jogo):
Menu(jogo)
{
    texto[0].setString("Voltar");
    texto[1].setString("Salvar");
    texto[2].setString("Ranking");
    texto[3].setString("Carregar");
    texto[4].setString("Sair");
}

MenuPause::~MenuPause() {
    
}

void MenuPause::executar() {
    int i, k;
    fundo.setPosicao(pGG->getVisao()->getCenter());
    fundo.imprimir();
    
    posicionarTexto();
    exibeRanking();
    texto[selecionado].setFillColor(Color::Cyan);
    for(i = 0; i < 5; i++) {
        pGG->getJanela()->draw(texto[i]);
    }
    texto[selecionado].setFillColor(Color::Black);
    opcao = -1;

    leEntradas();

    switch (opcao) {
        case 0:
            pJogo->tirarEstado();
            break;
        case 1:
            pressionar = false;
            pJogo->tirarEstado(false);
            reinterpret_cast<Fase*>(pJogo->getTopo())->salvar();
            pJogo->colocarEstado(reinterpret_cast<Estado*>(this));
            //Salvar
            break;
        case 2:
            if(ranking)
                ranking = false;
            else
                ranking = true;
            pressionar = false;
            //Ranking
            break;
        case 3:
            limparEstados();
            carregar();
            //Carregar
            break;
        case 4:
            limparEstados();
            reinterpret_cast<MenuPrincipal*>(pJogo->getTopo())->setPressionar(false);
            
            //Sair
            break;
        default:
            break;

    }
}