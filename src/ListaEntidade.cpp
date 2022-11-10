#include "ListaEntidade.h"
#include "Jogador.h"


ListaEntidade::ListaEntidade() {

}

ListaEntidade::~ListaEntidade() {
    limpar();
}

void ListaEntidade::executar() {
    Lista<Entidade>::Elemento<Entidade>* itr = LEs.getPrimeiro();
    
    while(itr) {
        itr->getAtual()->executar();
        itr = itr->getProx();
    }
    
}

void ListaEntidade::imprimir() {
    Lista<Entidade>::Elemento<Entidade>* itr = LEs.getPrimeiro();

    while(itr) {
        itr->getAtual()->imprimir();
        itr = itr->getProx();
    }
}

void ListaEntidade::colidir(Jogador* j, Colisora* colisora) {
    Lista<Entidade>::Elemento<Entidade>* itr = LEs.getPrimeiro(), *aux = NULL;
    Vector2f direcao(0.0f, 0.0f);
    Entidade* jog = static_cast<Entidade*>(j);

    itr = itr->getProx();

    // 0 empurra
    // 1 n�o empurra



    while(itr)
    {
        aux = itr->getProx();

        if(itr->getAtual()->getMorto())
        {
            excluir(itr);
            itr = aux;
        }

        if(colisora->atacando(itr->getAtual(), jog, direcao))
        {
            if(itr->getAtual()->getPlataforma()) {
                colisora->colidir(reinterpret_cast<Entidade*>(itr->getAtual()->getPlataforma()),itr->getAtual(), direcao);
            }
            colisora->colidir(itr->getAtual(), jog, direcao);
            if(j->getAtacando())
                if(colisora->ataque(itr->getAtual(), static_cast<Entidade*>(j->getProjetil()), direcao)) {
                    if(itr->getAtual()->tomarDano())
                    {
                        j->setPontos(j->getPontos() + 15);
                        excluir(itr);
                    }
                }

            itr = aux;
        }
        else{
            j->morrer();
        }
    }
}

void ListaEntidade::colidir(Jogador* j, Jogador* j2, Colisora* colisora) {
    Lista<Entidade>::Elemento<Entidade>* itr = LEs.getPrimeiro(), *aux = NULL;
    Vector2f direcao(0.0f, 0.0f);

    Entidade* jog = static_cast<Entidade*>(j);
    Entidade* jog2 = static_cast<Entidade*>(j2);

    itr = itr->getProx()->getProx();

    // 0 empurra
    // 1 n�o empurra

    while(itr)
    {
        aux = itr->getProx();

        if(itr->getAtual()->getMorto())
        {
            excluir(itr);
            itr = aux;
            if(aux == NULL)
                break;
        }

        if(colisora->atacando(itr->getAtual(), jog, direcao))
        {
            if(itr->getAtual()->getPlataforma())
            {
                colisora->colidir(reinterpret_cast<Entidade*>(itr->getAtual()->getPlataforma()),itr->getAtual(), direcao);
            }

            colisora->colidir(itr->getAtual(), jog, direcao);
            if(j->getAtacando())
                if(colisora->ataque(itr->getAtual(), static_cast<Entidade*>(j->getProjetil()), direcao)) {
                    if(itr->getAtual()->tomarDano())
                    {
                        j->setPontos(j->getPontos() + 15);
                        excluir(itr);
                        itr = aux;
                        if(aux == NULL)
                            break;
                    }
                }
        }

        else{
            j->morrer(Vector2f(j2->getPosicao().x, -1000));
        }

        if(colisora->atacando(itr->getAtual(), jog2, direcao))
        {
            if(itr->getAtual()->getPlataforma())
                colisora->colidir(reinterpret_cast<Entidade*>(itr->getAtual()->getPlataforma()),itr->getAtual(), direcao);

            colisora->colidir(itr->getAtual(), jog2, direcao);
            if(j2->getAtacando())
                if(colisora->ataque(itr->getAtual(), static_cast<Entidade*>(j2->getProjetil()), direcao)) {
                    if(itr->getAtual()->tomarDano())
                    {
                        j2->setPontos(j->getPontos() + 15);
                        excluir(itr);
                    }
                }
        }
        else{
            j2->morrer(Vector2f(j->getPosicao().x, -1000));
        }
                itr = aux;
    }
}

void ListaEntidade::incluir(Entidade* ent) {
    LEs.incluir(ent);
}

void ListaEntidade::limpar() {
    LEs.limpar();
}

void ListaEntidade::excluir(Lista<Entidade>::Elemento<Entidade>* no) {
    Lista<Entidade>::Elemento<Entidade> *aux = NULL;

    if(no->getProx()) {
        if(no->getAnt()) {
            no->getAnt()->setProx(no->getProx());
            no->getProx()->setAnt(no->getAnt());
        }
        else {
            no->getProx()->setAnt(NULL);
        }
    }
    else {
        no->getAnt()->setProx(NULL);
    }
    delete no->getAtual();
    delete no;
}

void ListaEntidade::gravar(Persistidora* pers) {
    Lista<Entidade>::Elemento<Entidade>* itr = LEs.getPrimeiro(), *aux = NULL;

    while(itr) {
        pers->gravar(itr->getAtual()->gravar());
        itr = itr->getProx();
    }
}

