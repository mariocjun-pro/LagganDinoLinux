#include "Inimigo.h"
#include "Plataforma.h"
using namespace Inimigos;

Inimigo::Inimigo(Gerenciador_Grafico* g):
Personagem(g)
{
    podeMatar = true;
    podeMorrer = true;
    empurrao = 1.0f;

    noChao = true;
    aDireita = false;
    
    danoT = 0.0f;
}

Inimigo::~Inimigo() {
}

void Inimigo::executar()
{
    if(tomaDano == false) {
        danoT += pGG->getDt();
        if(danoT >= 0.5f) {
            danoT -= 0.5f;
            tomaDano = true;
            ferido = false;
        }
    }
    
    if(not ferido)
        mover();
    animar(movimento);
}

void Inimigo::imprimir(){
    pGG->desenhar(corpo.getCorpo());
}

bool Inimigo::tomarDano() {
    if(tomaDano) {
        vidas--;
        ferido = true;
        tomaDano = false;
        if(vidas < 0)
            return true;
    }
    
    
    return false;
}
