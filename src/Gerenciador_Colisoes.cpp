#include "Gerenciador_Colisoes.h"
#include "Corpo_Grafico.h"
#include "Entidade.h"

using namespace Controladoras;
using namespace Abstratas;
using namespace GerenciadoresFases;

Gerenciador_Colisoes::Gerenciador_Colisoes()
{
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
}

//Função VerificarColisão adaptada de um vídeo do canal no Youtube Hilze Vonck 

bool Gerenciador_Colisoes::verificarColisao(Corpo_Grafico *c1, Corpo_Grafico *c2, Vector2f &direcao, float f) {

    Vector2f pos2 = c2->getHitbox()->getPosition();
    Vector2f med2 = c2->getHitbox()->getSize() / 2.0F;

    Vector2f pos = c1->getHitbox()->getPosition();
    Vector2f met = c1->getHitbox()->getSize() / 2.0F;

    float deltaX = pos2.x - pos.x;
    float deltaY = pos2.y - pos.y;

    float interX = abs(deltaX) - med2.x - met.x;
    float interY = abs(deltaY) - med2.y - met.y;

    if (interX < static_cast<float>(0) && interY < static_cast<float>(0)) {
        f = std::min(std::max(f, 0.0F), 1.0F);

        if (abs(interX) < abs(interY)) {
            if (deltaX > static_cast<float>(0)) {
                c1->mover(interX * (static_cast<float>(1) - f), static_cast<float>(0));
                c2->mover(-interX * f, static_cast<float>(0));

                direcao.x = static_cast<float>(1);
                direcao.y = static_cast<float>(0);
            }
            if (deltaX < static_cast<float>(0)) {
                c1->mover(-interX * (static_cast<float>(1) - f), static_cast<float>(0));
                c2->mover(interX * f, static_cast<float>(0));

                direcao.x = static_cast<float>(-1);
                direcao.y = static_cast<float>(0);
            }
        } else {
            if (deltaY > static_cast<float>(0)) {
                c1->mover(static_cast<float>(0), interY * (static_cast<float>(1) - f));
                c2->mover(static_cast<float>(0), -interY * f);

                direcao.x = static_cast<float>(0);
                direcao.y = static_cast<float>(1);
            }
            if (deltaY < static_cast<float>(0)) {
                c1->mover(static_cast<float>(0), -interY * (static_cast<float>(1) - f));
                c2->mover(static_cast<float>(0), interY * f);

                direcao.x = static_cast<float>(0);
                direcao.y = static_cast<float>(-1);
            }
        }
        return true;
    }
    return false;
}

void Gerenciador_Colisoes::colidindo(Entidade *e1, Vector2f direcao) {
    if (direcao.x < static_cast<float>(0)) //Colidindo na esquerda
        e1->setMovimento(Vector2f(0.0F, e1->getMovimento().y));

    else if (direcao.x > static_cast<float>(0)) //Colidindo na direita
        e1->setMovimento(Vector2f(0.0F, e1->getMovimento().y));

    if (direcao.y > static_cast<float>(0)) //Colidindo em cima
    {
        e1->setMovimento(Vector2f(e1->getMovimento().x, 0.0F));
    } else if (direcao.y < 0) //Colidindo em baixo
    {
        e1->setMovimento(Vector2f(e1->getMovimento().x, 0.0F));
        e1->setChao(true);
    }
}

// E1 = quem chama, E2 = jogador;

bool Gerenciador_Colisoes::atacando(Entidade *e1, Entidade *e2, Vector2f &direcao) {
    if (e1->getPodeMatar())
        if (verificarColisao(e1->getCorpoGraf(), e2->getCorpoGraf(), direcao, e1->getEmpurrao()))
            return false;

    return true;
}

bool Gerenciador_Colisoes::colidir(Entidade *e1, Entidade *e2, Vector2f &direcao) {
    if (verificarColisao(e1->getCorpoGraf(), e2->getCorpoGraf(), direcao, e1->getEmpurrao()))
        colidindo(e2, direcao);

}

bool Gerenciador_Colisoes::ataque(Entidade *e1, Entidade *e2, Vector2f &direcao) {
    if (e1->getPodeMorrer())
        if (verificarColisao(e1->getCorpoGraf(), e2->getCorpoGraf(), direcao, e1->getEmpurrao()))
            return true;

    return false;
}
