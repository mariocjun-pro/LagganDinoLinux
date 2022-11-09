#include "ListaEntidade.h"
#include "Jogador.h"

ListaEntidade::ListaEntidade() {}

ListaEntidade::~ListaEntidade() { limpar(); }

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

void ListaEntidade::incluir(Entidade *ent) { LEs.incluir(ent); }

void ListaEntidade::limpar() { LEs.limpar(); }







