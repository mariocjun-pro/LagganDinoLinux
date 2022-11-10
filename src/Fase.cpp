#include "Fase.h"
#include "MenuPause.h"

using namespace Fases;

Fase::Fase(Jogo* jooj, bool dois):
jogador1(NULL), jogador2(NULL)
{
    Plataforma::setContIdPlat(0);
    doisJogadores = dois;
    pJogo = jooj;
    id = -1;
    colisora = new Colisora();
    fundo = NULL;
    
    pGG = pJogo->getGerenciador();
}

Fase::~Fase() {
    if(colisora)
        delete colisora;
    if(fundo)
        delete fundo;
}

void Fase::executar() {

}
void Fase::gerenciar_colisoes() {

}

void Fase::reiniciar() {
    if(doisJogadores) {
        if(jogador2->getVidas() <= 0)
            pJogo->tirarEstado();
    }
    if(jogador1->getVidas() <= 0)
        pJogo->tirarEstado();
}

void Fase::menuPause() {
    if(Keyboard::isKeyPressed(Keyboard::Escape)) {
        pJogo->colocarEstado( reinterpret_cast<Estado*>(new MenuPause(pJogo)) );
    }
}

void Fase::salvar(string nome) {
    pers.setNome(nome);
    entidades.gravar(&pers);
    pers.gravarFase(id);
}

void Fase::pontuacao() {
    if(doisJogadores)
        {
            pGG->imprimePontuacao(jogador1->getPontos(), jogador1->getVidas(), jogador2->getPontos(), jogador2->getVidas());
            pGG->getVisao()->setCenter(Vector2f((jogador1->getPosicao().x + jogador2->getPosicao().x) / 2.0f, 960.0f / 2.0f));
        }

        else
        {
            pGG->imprimePontuacao(jogador1->getPontos(), jogador1->getVidas());
            pGG->getVisao()->setCenter(Vector2f(jogador1->getPosicao().x + 1280.0f / 4.0f, 960.0f / 2.0f));
        }
}