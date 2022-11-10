#include "Floresta.h"
#include "Jogo.h"
#include "Menu.h"

using namespace Fases;

Floresta::Floresta(Jogo* jooj, const bool dois):
Fase(jooj, dois)
{
    id = 1;
    srand(time(NULL));
    
}

Floresta::~Floresta() {

}

void Floresta::executar() {

    menuPause();
    fundo->setPosicao(pJogo->getGerenciador()->getVisao()->getCenter());
    fundo->imprimir();

    entidades.executar();
    entidades.imprimir();

    if(doisJogadores) {
        entidades.colidir(jogador1, jogador2, colisora);
        if(jogador1->getPosicao().y > 2000.0f)
            jogador1->morrer(Vector2f(jogador2->getPosicao().x, -1000));
        if(jogador2->getPosicao().y > 2000.0f)
            jogador2->morrer(Vector2f(jogador1->getPosicao().x, -1000));
        
        if(jogador1->getPosicao().x > 6000.0f || jogador2->getPosicao().x > 6000.0f) {
            pJogo->tirarEstado();
            Menu* menu = reinterpret_cast<Menu*>(pJogo->getTopo());
            menu->setLendoTexto(true);
            menu->setPontos((jogador1->getPontos()) + (jogador2->getPontos()));
        }
    }
    else {
        entidades.colidir(jogador1, colisora);

        if(jogador1->getPosicao().y > 2000.0f)
            jogador1->morrer();
        
        if(jogador1->getPosicao().x > 6000.0f) {
            pJogo->tirarEstado();
            Menu* menu = reinterpret_cast<Menu*>(pJogo->getTopo());
            menu->setLendoTexto(true);
            menu->setPontos(jogador1->getPontos());
        }
            
    }
    
    reiniciar();
    pontuacao();
}
