#include "CorpoGrafico.h"
#include "Animadora.h"

using namespace GerenciadoresEntidades;

CorpoGrafico::CorpoGrafico() : corpo(nullptr), textura(nullptr), animacao(nullptr) {}

CorpoGrafico::~CorpoGrafico() {
    if (corpo) { delete corpo; }
    if (textura) { delete textura; }
    if (animacao) { delete animacao; }
    corpo = nullptr;
    textura = nullptr;
    animacao = nullptr;
}

void CorpoGrafico::inicializa(sf::Vector2f tamanho, sf::Texture *pTexture, sf::Vector2f margemHitbox) {
    corpo = new sf::RectangleShape(tamanho);
    corpo->setOrigin(tamanho / 2.0f);
    corpo->setFillColor(sf::Color::Blue);

    corpo->setTexture(pTexture);
    textura = new sf::Texture();
    animacao = new Animadora(this);

    corpo->setTexture(textura);
}

void
CorpoGrafico::inicializaAnimadora(sf::Vector2f margem, sf::Vector2u quantidadeQuadros, sf::Vector2u TotalDeQuadros) {
    animacao->inicializa(margem, quantidadeQuadros, TotalDeQuadros);
}

void CorpoGrafico::atualizaAnimacao(float dT, bool aDireita, unsigned int comecoP, unsigned int quantidadeQuadrosX,
                                    float troca, unsigned int linha) {
    animacao->atualizar(dT, aDireita, comecoP, quantidadeQuadrosX, troca, linha);
}