#pragma once
#include "stdafx.h"


namespace Listas {
    template <class TL>
    class Lista {
    public:

        template <class TE>
        class Elemento {
            public:
                Elemento() { atual = NULL; pProx = NULL; pAnt = NULL; }
                ~Elemento() { }

                //Sets e Gets

                void setAtual(TE* elem) { atual = elem; }
                TE* getAtual() const { return atual; }

                void setProx(Elemento<TE>* prox) { pProx = prox; }
                Elemento<TE>* getProx() const { return pProx; }

                void setAnt(Elemento<TE>* ant) { pAnt = ant; }
                Elemento<TE>* getAnt() const { return pAnt; }

            private:
                TE* atual;
                Elemento<TE>* pProx;
                Elemento<TE>* pAnt;
        };

        Lista();
        ~Lista();

        void incluir(TL* elemento);
        void limpar();

        //Sets e Gets

        void setPrimeiro(Elemento<TL>* primeiro) { pPrimeiro = primeiro; }
        Elemento<TL>* getPrimeiro () const { return pPrimeiro; }

        void setUltimo(Elemento<TL>* ultimo) { pUltimo = ultimo; }
        Elemento<TL>* getUltimo () const { return pUltimo; }

        int getTamanho () const { return tamanho; }

    private:
        int tamanho;
        Elemento<TL>* pPrimeiro;
        Elemento<TL>* pUltimo;

    };

    template <class TL>
    Lista<TL>::Lista() {
        pPrimeiro = NULL;
        pUltimo = NULL;
        tamanho = 0;
    }

    template <class TL>
    Lista<TL>::~Lista() {
    }

    template <class TL>
    void Lista<TL>::incluir(TL* elemento) {
        if(elemento) {
            if (!pPrimeiro) {
                pPrimeiro = new Elemento<TL>;
                pPrimeiro->setAtual(elemento);
                pUltimo = pPrimeiro;
            }
            else {
                pUltimo->setProx(new Elemento<TL>);
                pUltimo->getProx()->setAnt(pUltimo);
                pUltimo = pUltimo->getProx();
                pUltimo->setAtual(elemento);
            }
            tamanho++;
        }
    }

    template <class TL>
    void Lista<TL>::limpar() {
        Elemento<TL> *itr = pPrimeiro, *aux = NULL;

        while(itr) {

            aux = itr->getProx();
            delete itr->getAtual();
            delete itr;
            itr = aux;
        }
    }

}
