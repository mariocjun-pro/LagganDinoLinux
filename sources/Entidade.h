#ifndef LAGGANDOGAME_ENTIDADE_H
#define LAGGANDOGAME_ENTIDADE_H

#include "stdafx.h"
#include "Ente.h"
#include "GerenciadorGrafico.h"
#include "CorpoGrafico.h"
#include "GerenciadorColisoes.h"

namespace Auxiliares {
    class __attribute__((unused)) Plataforma;
}

using namespace Auxiliares;
using namespace Controladoras;
using namespace GerenciadoresEntidades;
using namespace GerenciadorFases;

namespace Abstratas {
    class Entidade : public Ente {
    protected:
        CorpoGrafico corpoGrafico;
        GerenciadorGrafico *gerenciadorGrafico;
        sf::Vector2f movimentacao;
    public:
        explicit Entidade(GerenciadorGrafico *gerenciadorGrafico = nullptr);

        virtual ~Entidade();

        virtual void executar() = 0;

        virtual void mover() {}

        virtual void imprimir();

        sf::Vector2f getPosicao() { return corpoGrafico.getPosicao(); }

        void setPosicao(sf::Vector2f posicao) { corpoGrafico.setPosicao(posicao); }

        CorpoGrafico *getCorpoGrafico() { return &corpoGrafico; }

        void setMovimentacao(sf::Vector2f f) { this->movimentacao = f; }

        sf::Vector2f getMovimentacao() { return movimentacao; }
    };

}

#endif //LAGGANDOGAME_ENTIDADE_H
