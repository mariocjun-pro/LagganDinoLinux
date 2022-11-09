#include "GerenciadorGrafico.h"

using namespace Controladoras;

GerenciadorGrafico::GerenciadorGrafico()
        : janela(sf::VideoMode(1280, 960), "Laggando the Game", sf::Style::Default),
          visao(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1280, 960)),
          dT(0.0f), caracter(0), leitura(false), fonte(), texto() {
    instaciaTexto();
    leitura = false;
}

GerenciadorGrafico::~GerenciadorGrafico() {}

void GerenciadorGrafico::leEventos() {
    sf::Event evento{};
    while (janela.pollEvent(evento)) {
        switch (evento.type) {
            case sf::Event::Closed:
                janela.close();
                break;
            case sf::Event::Resized:
                break;
            case sf::Event::KeyPressed:
                if (evento.key.code == sf::Keyboard::Escape) {
                    janela.close();
                }
                break;
            case sf::Event::TextEntered:
                caracter = (char) evento.text.unicode;
                entraString(caracter);
                break;
            default:
                break;
        }
    }
}

void GerenciadorGrafico::limpar() {
    janela.clear(sf::Color::White);
    janela.setView(visao);
}

void GerenciadorGrafico::instaciaTexto() {
    if (!fonte.loadFromFile("../assets//fonts//Pixel.ttf")) { cout << "Erro ao carregar fonte" << endl; }
    texto.setFont(fonte);
    texto.setCharacterSize(50);
    texto.setOutlineThickness(0.5f);
    texto.setFillColor(sf::Color::Green);
    texto.setOutlineColor(sf::Color::Yellow);
}

void GerenciadorGrafico::imprimePontuacao(int p, int v) {

    // Desenha a pontuação do jogador 1
    string s1 = "Pontos: ";
    string s2 = "000000";

    if (p > 999999) p = 999999;

    s2 = to_string(p);

    texto.setString(s1 + s2);
    texto.setPosition(visao.getCenter().x - 600, 20);

    janela.draw(texto);

    // Desenha a vida do jogador 1
    s1 = "Vidas: ";
    s2 = to_string(v);

    texto.setString(s1 + s2);
    texto.setPosition(visao.getCenter().x - 600, 80);

    janela.draw(texto);
}

void GerenciadorGrafico::imprimePontuacao(int p, int v, int p2, int v2) {

    texto.setFillColor(sf::Color::Blue);
    texto.setOutlineColor(sf::Color::Yellow);

    // Desenha a pontuação do jogador 1
    string s1 = "Pontos: ";
    string s2 = "000000";

    if (p > 999999) p = 999999;

    s2 = to_string(p);

    texto.setString(s1 + s2);
    texto.setPosition(visao.getCenter().x - 600, 20);

    janela.draw(texto);

    // Desenha a vida do jogador 1
    s1 = "Vidas: ";
    s2 = to_string(v);

    texto.setString(s1 + s2);
    texto.setPosition(visao.getCenter().x - 600, 80);

    janela.draw(texto);

    texto.setFillColor(sf::Color::Red);
    texto.setOutlineColor(sf::Color::Yellow);

    // Desenha a pontuação do jogador 2
    s1 = "Pontos: ";
    s2 = "000000";

    if (p2 > 999999) p2 = 999999;

    s2 = to_string(p2);

    texto.setString(s1 + s2);
    texto.setPosition(visao.getCenter().x + 400, 20);

    janela.draw(texto);

    // Desenha a vida do jogador 2
    s1 = "Vidas: ";
    s2 = to_string(v2);

    texto.setString(s1 + s2);
    texto.setPosition(visao.getCenter().x + 400, 80);

    janela.draw(texto);
}

void GerenciadorGrafico::entraString(char c) {
    if (leitura) {
        if (isalnum(c)) {
            textoDigitado += c;
        } else if (c == 8) {
            if (!textoDigitado.empty()) {
                textoDigitado.erase(textoDigitado.size() - 1);
            }
        }
        if (textoDigitado.size() > 20) {
            textoDigitado.clear();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            textoDigitado = "!Mario";
        }
    }
}
