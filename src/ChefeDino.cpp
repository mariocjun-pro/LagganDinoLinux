#include "ChefeDino.h"

using namespace Inimigos;

ChefeDino::ChefeDino(Plataforma* p):
Inimigo(p->getGerenciador())
{
    float aux, aux2;

    plat = p;

    vidas = 4;
    pulo = 380.0f;

    aux = (plat->getTamanho().x / 2.0f) - 50.0f;
    aux2 = (plat->getTamanho().y / 2.0f) + 50.0f;
    fronteira = Vector3f(plat->getPosicao().x - aux, plat->getPosicao().x + aux, plat->getPosicao().y - aux2);

    velocidade = 350.0f;

    corpo.inicializa(Vector2f(200.0f, 260.0f), NULL);
    corpo.setTextura("../Texturas/Dinos/mort.png");
    corpo.inicializaAnimadora(Vector2f(0.0f, -2.5f), Vector2u(4, 1), Vector2u(24, 1));

    posicaoInicial = fronteira.x + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(fronteira.y-fronteira.x)));
    if(rand() % 2)
        lado = 1;

    corpo = Vector2f(posicaoInicial, fronteira.z);
    corpo.getCorpo()->setFillColor(Color::White);
    totalT = 0;
    
    hitbox = new Projetil(plat->getGerenciador());
    hitbox->getCorpoGraf()->inicializa(Vector2f(100.0f, 100.0f), NULL);
    hitbox->getCorpoGraf()->setTextura("../Texturas/Efeitos/sunburn.png");
    hitbox->getCorpoGraf()->inicializaAnimadora(Vector2f(0.0f, 0.0f), Vector2u(8, 8), Vector2u(8, 8));
    
    id = 5;
}

ChefeDino::~ChefeDino() {
    hitbox->setMorto();
}

void ChefeDino::mover() {
    int chancePulo;
    float dT = pGG->getDt();
    totalT += dT;
    movimento.x = velocidade * lado;

    chancePulo = rand() % 700;

    if(!chancePulo && noChao)
    {
        noChao = false;

        movimento.y = -sqrtf(2.0 * 981.0 * pulo);
    }

    movimento.y += 981.0 * dT;

    float tempoTroca = 0.2f;

    if((corpo.getCorpo()->getPosition().x < fronteira.x || corpo.getCorpo()->getPosition().x > fronteira.y) && totalT >= tempoTroca) {
        lado *= -1;
        totalT -= tempoTroca;
    }

    corpo.mover(movimento * dT);
    animar(movimento);
}

void ChefeDino::executar() {
    if(ataquePronto == false)
        totalT += pGG->getDt();

    if(tomaDano == false) {
        danoT += pGG->getDt();
        if(danoT >= 0.5f) {
            danoT -= 0.5f;
            tomaDano = true;
            ferido = false;
        }
    }
    
    
    if(ataquePronto && rand()%400 == 0) {
        atacando = true;
        totalT -= 0.5f;
        hitbox->getCorpoGraf()->setPosicao(corpo.getPosicao().x + (300.0f * -1), corpo.getPosicao().y);
        ataquePronto = false;

    }
    if(atacando && totalT >= 0.5f) {
        atacando = false;
        totalT = 0.0f;
        ataquePronto = true;
        hitbox->getCorpoGraf()->setPosicao(corpo.getPosicao().x + (100.0f * -1), corpo.getPosicao().y);
    }

    hitbox->getCorpoGraf()->mover(298.0f  * pGG->getDt() * -1, 0.0f);
    if(atacando)
        hitbox->getCorpoGraf()->getAnimadora()->atualizarLinhasSequencial(pGG->getDt(), aDireita, Vector2u(8, 8), 5, 0.1f);

    if(not ferido)
        mover();
    animar(movimento);
}

void ChefeDino::imprimir()
{
    if(atacando)
        pGG->desenhar(hitbox->getCorpoGraf()->getCorpo());

    pGG->desenhar(corpo.getCorpo());
}
