#include "MenuPause.h"
#include "Jogo.h"

MenuPause::MenuPause(Jogo *j) :
        Menu(j),
        voltar_str("Voltar"),
        salvar_str("Salvar"),
        ranking_str("Ranking"),
        carregar_str("Carregar"),
        sair_str("Sair") {
    texto[0].setString(voltar_str);
    texto[1].setString(salvar_str);
    texto[2].setString(ranking_str);
    texto[3].setString(carregar_str);
    texto[4].setString(sair_str);
}

MenuPause::~MenuPause()
{
}

void MenuPause::executar() {
    int i, k;
    fundo.setPosicao(pGG->getVisao()->getCenter());
    fundo.imprimir();

    posicionarTexto();
    exibeRanking();
    texto[selecionado].setFillColor(Color::Cyan);
    for (i = 0; i < 5; i++) {
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
            reinterpret_cast<Fase *>(pJogo->getTopo())->salvar();
            pJogo->colocarEstado(reinterpret_cast<Estado *>(this));
            //Salvar
            break;
        case 2:
            if (ranking)
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
            reinterpret_cast<MenuPrincipal *>(pJogo->getTopo())->setPressionar(false);

            //Sair
            break;
        default:
            break;

    }
}