#include "MenuPrincipal.h"
#include "Jogo.h"

MenuPrincipal::MenuPrincipal(Jogo* jogo):
Menu(jogo), fab1(pJogo), fab2(pJogo)
{
    texto[0].setString("Um Jogador");
    texto[1].setString("Dois Jogadores");
    texto[2].setString("Ranking");
    texto[3].setString("Carregar");
    texto[4].setString("Sair");
}

MenuPrincipal::~MenuPrincipal() {
}

void MenuPrincipal::executar() {
    int i;
    posicionarTexto();
    fundo.setPosicao(pGG->getVisao()->getCenter());
    fundo.imprimir();
    exibeRanking();

    texto[selecionado].setFillColor(Color::Cyan);
    for(i = 0; i < 5; i++) {
        pGG->getJanela()->draw(texto[i]);
    }
    texto[selecionado].setFillColor(Color::Black);
    opcao = -1;

    leEntradas();
    leTexto();
    switch (opcao) {
        case 0:
            fab1.setDoisJogadores(false);
            pJogo->colocarEstado( reinterpret_cast<Estado*>(fab1.criar()) );
            pressionar = false;
            totalT = 0.0f;
            //Um jogador
            break;
        case 1:
            fab1.setDoisJogadores(true);
            pJogo->colocarEstado( reinterpret_cast<Estado*>(fab1.criar()) );
            pressionar = false;
            totalT = 0.0f;
            //Dois jogadores
            break;
        case 2:
            if(ranking)
                ranking = false;
            else
                ranking = true;
            pressionar = false;
            totalT = 0.0f;
            //Ranking
            break;
        case 3:
            carregar();
            pressionar = false;
            totalT = 0.0f;
            //Carregar
            break;
        case 4:
            pJogo->tirarEstado();
            pGG->getJanela()->close();
            pressionar = false;
            totalT = 0.0f;
            //Sair
            break;

        default:
            break;

    }
}

