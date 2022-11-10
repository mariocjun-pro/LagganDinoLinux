#include "Colisora.h"
#include "Corpo_Grafico.h"
#include "Entidade.h"
using namespace Controladoras;
using namespace Abstratas;
using namespace GerenciadoresFases;

Colisora::Colisora() {

}

Colisora::~Colisora() {
}

//Função VerificarColisão adaptada de um vídeo do canal no Youtube Hilze Vonck 

bool Colisora::verificarColisao(Corpo_Grafico* c1, Corpo_Grafico* c2, Vector2f& direcao, float f) {

    Vector2f pos2 = c2->getHitbox()->getPosition();
    Vector2f med2 = c2->getHitbox()->getSize() / 2.0f;

    Vector2f pos = c1->getHitbox()->getPosition();
    Vector2f met = c1->getHitbox()->getSize() / 2.0f;

    float deltaX = pos2.x - pos.x;
    float deltaY = pos2.y - pos.y;

    float interX = abs(deltaX) - med2.x - met.x;
    float interY = abs(deltaY) - med2.y - met.y;

    if(interX < 0 && interY < 0)
    {
        f = std::min(std::max(f,0.0f),1.0f);

        if(abs(interX) < abs(interY))
        {
            if(deltaX > 0)
            {
                c1->mover(interX * (1 - f), 0);
                c2->mover(-interX * f,0);

                direcao.x = 1;
                direcao.y = 0;
            }
            if(deltaX < 0)
            {
                c1->mover(-interX * (1 - f), 0);
                c2->mover(interX * f, 0);

                direcao.x = -1;
                direcao.y = 0;
            }
        }
        else
        {
            if(deltaY > 0)
            {
                c1->mover(0, interY * (1 - f));
                c2->mover(0, -interY * f);

                direcao.x = 0;
                direcao.y = 1;
            }
            if(deltaY < 0)
            {
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

void Colisora::colidindo(Entidade* e1, Vector2f direcao)
{
    if(direcao.x < 0) //Colidindo na esquerda
        e1->setMovimento(Vector2f(0.0f, e1->getMovimento().y));

    else if(direcao.x > 0) //Colidindo na direita
        e1->setMovimento(Vector2f(0.0f, e1->getMovimento().y));

    if(direcao.y > 0) //Colidindo em cima
    {
        e1->setMovimento(Vector2f(e1->getMovimento().x, 0.0f));
    }

    else if(direcao.y < 0) //Colidindo em baixo
    {
        e1->setMovimento(Vector2f(e1->getMovimento().x, 0.0f));
        e1->setChao(true);
    }
}

// E1 = quem chama, E2 = jogador;


bool Colisora::atacando(Entidade* e1, Entidade* e2, Vector2f& direcao) {
    if(e1->getPodeMatar())
        if(verificarColisao(e1->getCorpoGraf(), e2->getCorpoGraf(), direcao, e1->getEmpurrao()))
            return false;

    return true;
}
bool Colisora::colidir(Entidade* e1, Entidade* e2, Vector2f& direcao) {
    if(verificarColisao(e1->getCorpoGraf(), e2->getCorpoGraf(), direcao, e1->getEmpurrao()))
        colidindo(e2, direcao);

}
bool Colisora::ataque(Entidade* e1, Entidade* e2, Vector2f& direcao) {
    if(e1->getPodeMorrer())
        if( verificarColisao( e1->getCorpoGraf(), e2->getCorpoGraf(), direcao, e1->getEmpurrao() ) )
            return true;

    return false;
}
