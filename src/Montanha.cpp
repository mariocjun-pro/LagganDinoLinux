#include "Montanha.h"
#include "Jogo.h"
#include "FabricaFloresta.h"

using namespace Fases;

Montanha::Montanha(Jogo* jooj, bool dois):
Fase(jooj, dois), fab(pJogo)
{
    id = 0;
    pGG = pJogo->getGerenciador();
    srand(time(NULL));
}

Montanha::~Montanha() {

}

void Montanha::executar() {
    trocaFase();
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
    }
    else {
        entidades.colidir(jogador1, colisora);

        if(jogador1->getPosicao().y > 2000.0f)
            jogador1->morrer();
    }

    reiniciar();
    pontuacao();

}

void Montanha::trocaFase() {
    
    if(jogador1->getPosicao().x < -200.0f && jogador1->getPosicao().y > 1000.0f) {
        fab.setDoisJogadores(doisJogadores);
        fab.setJogadores(jogador1, jogador2);
        pJogo->tirarEstado();
        pJogo->colocarEstado(reinterpret_cast<Estado*>(fab.criar()));
        return;
    }
    else if(jogador1->getPosicao().x > 4500.0f) {
        fab.setDoisJogadores(doisJogadores);
        fab.setJogadores(jogador1, jogador2);
        pJogo->tirarEstado();
        pJogo->colocarEstado(reinterpret_cast<Estado*>(fab.criar()));
        return;
    }
    
    if(doisJogadores) {
        if(jogador2->getPosicao().x < -200.0f && jogador2->getPosicao().y > 1000.0f) {
            fab.setDoisJogadores(doisJogadores);
            fab.setJogadores(jogador1, jogador2);
            pJogo->tirarEstado();
            pJogo->colocarEstado(reinterpret_cast<Estado*>(fab.criar()));
            return;
        }
        else if(jogador2->getPosicao().x > 4000.0f) {
            fab.setDoisJogadores(doisJogadores);
            fab.setJogadores(jogador1, jogador2);
            pJogo->tirarEstado();
            pJogo->colocarEstado(reinterpret_cast<Estado*>(fab.criar()));
            return;
        }
    }
}