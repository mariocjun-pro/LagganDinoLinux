#include "ListaEntidade.h"
#include "Jogador.h"


ListaEntidade::ListaEntidade() {

}

ListaEntidade::~ListaEntidade() {
    limpar();
}

void ListaEntidade::executar() {
    Lista<Entidade>::Elemento<Entidade> *itr = LEs.getPrimeiro();

    while (itr) {
        itr->getAtual()->executar();
        itr = itr->getProx();
    }

}

void ListaEntidade::imprimir() {
    Lista<Entidade>::Elemento<Entidade> *itr = LEs.getPrimeiro();

    while (itr) {
        itr->getAtual()->imprimir();
        itr = itr->getProx();
    }
}

void ListaEntidade::incluir(Entidade *ent) {
    LEs.incluir(ent);
}

void ListaEntidade::limpar() {
    LEs.limpar();
}

void ListaEntidade::excluir(Lista<Entidade>::Elemento<Entidade> *no) {
    Lista<Entidade>::Elemento<Entidade> *aux = NULL;

    if (no->getProx()) {
        if (no->getAnt()) {
            no->getAnt()->setProx(no->getProx());
            no->getProx()->setAnt(no->getAnt());
        } else {
            no->getProx()->setAnt(NULL);
        }
    } else {
        no->getAnt()->setProx(NULL);
    }
    delete no->getAtual();
    delete no;
}







