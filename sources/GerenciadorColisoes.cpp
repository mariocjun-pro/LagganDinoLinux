#include "GerenciadorColisoes.h"
#include "CorpoGrafico.h"
#include "Entidade.h"

using namespace GerenciadorFases;
using namespace Controladoras;
using namespace Abstratas;

GerenciadorColisoes::GerenciadorColisoes() {}

GerenciadorColisoes::~GerenciadorColisoes() {}

//Função VerificarColisão adaptada de um vídeo do canal no Youtube Hilze Vonck

bool GerenciadorColisoes::verificaColisao(CorpoGrafico *c1, CorpoGrafico *c2, sf::Vector2f &direcao, float f) {

    sf::Vector2f pos2 = c2->getHitbox()->getPosition();
    sf::Vector2f med2 = c2->getHitbox()->getSize() / 2.0f;

    sf::Vector2f pos = c1->getHitbox()->getPosition();
    sf::Vector2f met = c1->getHitbox()->getSize() / 2.0f;

    float deltaX = pos2.x - pos.x;
    float deltaY = pos2.y - pos.y;

    float interX = abs(deltaX) - med2.x - met.x;
    float interY = abs(deltaY) - med2.y - met.y;

    if (interX < 0 && interY < 0) {
        f = std::min(std::max(f, 0.0f), 1.0f);

        if (abs(interX) < abs(interY)) {
            if (deltaX > 0) {
                c1->mover(interX * (1 - f), 0);
                c2->mover(-interX * f, 0);

                direcao.x = 1;
                direcao.y = 0;
            }
            if (deltaX < 0) {
                c1->mover(-interX * (1 - f), 0);
                c2->mover(interX * f, 0);

                direcao.x = -1;
                direcao.y = 0;
            }
        } else {
            if (deltaY > 0) {
                c1->mover(0, interY * (1 - f));
                c2->mover(0, -interY * f);

                direcao.x = 0;
                direcao.y = 1;
            }
            if (deltaY < 0) {
                c1->mover(0, -interY * (1 - f));
                c2->mover(0, interY * f);

                direcao.x = 0;
                direcao.y = -1;
            }
        }

        return true;
    }


    return false;
}

void GerenciadorColisoes::colidindo(Entidade *e1, sf::Vector2f direcao) {
    if (direcao.x < 0) //Colidindo na esquerda
        e1->setMovimentacao(sf::Vector2f(0.0f, e1->getMovimentacao().y));

    else if (direcao.x > 0) //Colidindo na direita
        e1->setMovimentacao(sf::Vector2f(0.0f, e1->getMovimentacao().y));

    if (direcao.y > 0) //Colidindo em cima
    {
        e1->setMovimentacao(sf::Vector2f(e1->getMovimentacao().x, 0.0f));
    } else if (direcao.y < 0) //Colidindo em baixo
    {
        e1->setMovimentacao(sf::Vector2f(e1->getMovimentacao().x, 0.0f));
        e1->setNoChao(true);
    }
}

// E1 = quem chama, E2 = jogador;

bool GerenciadorColisoes::atacando(Entidade *e1, Entidade *e2, sf::Vector2f &direcao) {
    if (e1->getPodeMatar())
        if (verificaColisao(e1->getCorpoGrafico(), e2->getCorpoGrafico(), direcao, e1->getEmpurrao()))
            return false;

    return true;
}

bool GerenciadorColisoes::colidir(Entidade *e1, Entidade *e2, sf::Vector2f &direcao) {
    if (verificaColisao(e1->getCorpoGrafico(), e2->getCorpoGrafico(), direcao, e1->getEmpurrao())) {
        colidindo(e2, direcao);
    }
    return false;
}

bool GerenciadorColisoes::ataque(Entidade *e1, Entidade *e2, sf::Vector2f &direcao) {
    if (e1->getPodeMorrer())
        if (verificaColisao(e1->getCorpoGrafico(), e2->getCorpoGrafico(), direcao, e1->getEmpurrao()))
            return true;

    return false;
}
