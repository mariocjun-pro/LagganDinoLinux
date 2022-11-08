#ifndef LAGGANDOGAME_ENTIDADE_H
#define LAGGANDOGAME_ENTIDADE_H

#include "stdafx.h"
#include "Ente.h"
#include "GerenciadorGrafico.h"
#include "CorpoGrafico.h"

namespace Auxiliares {
    class Plataforma;
}

using namespace Auxiliares;
using namespace Controladoras;
using namespace GerenciadoresEntidades;

namespace Abstratas {
    class Entidade : public Ente {
    protected:
        int id;
        CorpoGrafico corpoGrafico;
        GerenciadorGrafico *gerenciadorGrafico;
        Plataforma *plataforma;
        sf::Vector2f movimentacao;
        int vida;
        float empurrao;
        bool noChao;
        bool podeMatar;
        bool podeMorrer;
        bool morto;
    public:
        explicit Entidade(GerenciadorGrafico *gerenciadorGrafico = nullptr);

        virtual ~Entidade();

        virtual void executar() = 0;

        virtual void mover() {}

        virtual void imprimir();

        virtual bool tomarDano();

        int getId() const { return id; }

        sf::Vector2f getPosicao() { return corpoGrafico.getPosicao(); }

        void setPosicao(sf::Vector2f posicao) { corpoGrafico.setPosicao(posicao); }

        sf::Vector2f getTamanho() { return corpoGrafico.getTamanho(); }

        CorpoGrafico *getCorpoGrafico() { return &corpoGrafico; }

        Plataforma *getPlataforma() { return plataforma; }

        void setPlataforma(Plataforma *pPlataforma) { this->plataforma = pPlataforma; }

        void setGerenciadorGrafico(
                GerenciadorGrafico *pGerenciadorGrafico) { this->gerenciadorGrafico = pGerenciadorGrafico; }

        void setMovimentacao(sf::Vector2f f) { this->movimentacao = f; }

        sf::Vector2f getMovimentacao() { return movimentacao; }

        void setVida(int i) { this->vida = i; }

        int getVida() const { return vida; }

        void setNoChao(bool chao) { this->noChao = chao; }

        bool getNoChao() const { return noChao; }

        void setPodeMatar(bool matar) { this->podeMatar = matar; }

        bool getPodeMatar() const { return podeMatar; }

        void setPodeMorrer(bool morrer) { this->podeMorrer = morrer; }

        bool getPodeMorrer() const { return podeMorrer; }

        void setMorto(bool mort) { this->morto = mort; }

        bool getMorto() const { return morto; }

        pair<Entidade*, int> gravar() {
            pair<Entidade*, int> p;
            p.first = this;
            p.second = id;
            return p;
        }
    };

}

#endif //LAGGANDOGAME_ENTIDADE_H
