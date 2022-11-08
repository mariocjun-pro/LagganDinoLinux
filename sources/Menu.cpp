#include "Menu.h"

using namespace Controladoras;

Menu::Menu(Jogo *jogo) :
        pJogo(jogo) {
    lido = false;
    pontos = 0;
    ranking = false;
    lendoTexto = false;
    texto.resize(5);
    pGG = pJogo->getGerenciador();

    pressionar = false;

    selecionado = 0;

    fonte.loadFromFile("../assets//fonts//Pixel.ttf");
    int i;
    for (i = 0; i < 2; i++) {
        texto[i].setFont(fonte);
        texto[i].setCharacterSize(50);
        texto[i].setOutlineThickness(0.5);
        texto[i].setFillColor(sf::Color::Black);
    }

    texto[0].setPosition(pGG->getVisao()->getCenter().x, pGG->getVisao()->getCenter().y - 400);
    texto[1].setPosition(pGG->getVisao()->getCenter().x, pGG->getVisao()->getCenter().y - 300);


    leitura.setFont(fonte);
    leitura.setCharacterSize(50);
    leitura.setOutlineThickness(0.5);
    leitura.setFillColor(sf::Color::Black);
    leitura.setPosition(pGG->getVisao()->getCenter().x - 600.0f, pGG->getVisao()->getCenter().y - 300.0f);

    texto[0].setString("Um Jogador");
    texto[1].setString("Sair");

    totalT = 0;
}

Menu::~Menu() {

}

void Menu::executar() {
}

void Menu::leEntradas() {
    if (!pressionar) {
        totalT += pGG->getDT();
    }
    if (totalT >= 0.2f) {
        totalT -= 0.2f;
        pressionar = true;
    }
    if (pressionar) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            selecionado--;
            if (selecionado < 0)
                selecionado = 4;
            pressionar = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            selecionado++;
            if (selecionado >= 5)
                selecionado = 0;
            pressionar = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            opcao = selecionado;
        }
    }
}

void Menu::posicionarTexto() {
    texto[0].setPosition(pGG->getVisao()->getCenter().x, pGG->getVisao()->getCenter().y - 400);
    texto[1].setPosition(pGG->getVisao()->getCenter().x, pGG->getVisao()->getCenter().y - 300);
}