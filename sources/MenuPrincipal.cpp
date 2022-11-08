#include "MenuPrincipal.h"
#include "Jogo.h"

MenuPrincipal::MenuPrincipal(Jogo *jogo) : Menu(jogo), fabricaFase1(pJogo) {
    texto[0].setString("Um Jogador");
    texto[1].setString("Sair");
}

MenuPrincipal::~MenuPrincipal() {}

void MenuPrincipal::executar() {
    int i;
    posicionarTexto();

    texto[selecionado].setFillColor(sf::Color::Cyan);
    for (i = 0; i < 2; i++) { pGG->getJanela()->draw(texto[i]); }
    texto[selecionado].setFillColor(sf::Color::Black);
    opcao = -1;

    leEntradas();
    switch (opcao) {
        case 0:
            pJogo->colocarEstado(reinterpret_cast<Estado *>(fabricaFase1.criarFase()));
            pressionar = false;
            totalT = 0.0f;
            //Um jogador
            break;
        default:
            break;

    }
}