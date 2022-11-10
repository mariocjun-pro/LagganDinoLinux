#include "AtiradinoThread.h"

using namespace Inimigos;
using namespace GerenciadoresEntidades;

AtiradinoThread::AtiradinoThread(Plataforma* p):
Atiradino(p)
{
    threadFechada = false;
    id = 3;
}

AtiradinoThread::~AtiradinoThread() {
    if(threadFechada)
        abrirThread();
}

void AtiradinoThread::executar() {
    if(tomaDano == false) {
        danoT += pGG->getDt();
        if(danoT >= 0.5f) {
            danoT -= 0.5f;
            tomaDano = true;
            ferido = false;
        }
    }
  
    if(ferido)
        ataquePronto = false;
    
    iniciarThread(); 
    juntarThread();
        
    if(ataquePronto == false)
        totalT += pGG->getDt();
    
    if(atacando && totalT >= 0.5f) {
        atacando = false;
        totalT = 0.0f;
        ataquePronto = true;
        //hitbox->getCorpoGraf()->setPosicao(corpo.getPosicao().x + (100.0f * -1), corpo.getPosicao().y);
    }
    
    hitbox->getCorpoGraf()->mover(298.0f  * pGG->getDt() * -1, 0.0f);
    if(atacando)
        hitbox->getCorpoGraf()->getAnimadora()->atualizarLinhasSequencial(pGG->getDt(), aDireita, Vector2u(8, 8), 5, 0.1f);

    
    animar(movimento);
}

void AtiradinoThread::funcaoThread() {
    fecharThread();
    tempoAtirar += pGG->getDt();
    if(tempoAtirar >= 3.0f) {
        tempoAtirar = 0.0f;
        atirar();
    }
    abrirThread();
    liberarThread();
}

void AtiradinoThread::atirar() {    
    if(ataquePronto) {
        atacando = true;
        totalT -= 0.5f;
        hitbox->getCorpoGraf()->setPosicao(corpo.getPosicao().x + (100.0f * -1), corpo.getPosicao().y);
        ataquePronto = false;

    }
    
}

float AtiradinoThread::tempoAtirar = 0.0f;