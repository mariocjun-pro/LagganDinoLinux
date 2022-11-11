#pragma once

#include "stdafx.h"
#include "Gerenciador_Grafico.h"
#include "Corpo_Grafico.h"
#include "Colisora.h"

namespace Auxiliares {
    class Plataforma;
}

using namespace Auxiliares;
using namespace Controladoras;
using namespace GerenciadoresEntidades;
using namespace GerenciadoresFases;


namespace Abstratas {
    class Entidade {
    public:
        explicit Entidade(Gerenciador_Grafico *gerenciador = NULL);

        virtual ~Entidade();

        virtual void executar() = 0;

        virtual void mover() {}

        virtual void imprimir();

        //Sets e gets

        int getId() const { return id; }

        Vector2f getPosicao() { return corpo.getCorpo()->getPosition(); }

        void setPosicao(const Vector2f pos) { corpo = pos; }

        Vector2f getTamanho() { return corpo.getCorpo()->getSize(); }

        Corpo_Grafico *getCorpoGraf() { return &corpo; }

        Plataforma *getPlataforma() { return plat; }

        void setGerenciador(Gerenciador_Grafico *gerenciador) { pGG = gerenciador; }

        void setMovimento(Vector2f mov) { movimento = mov; }

        Vector2f getMovimento() { return movimento; }

        void setChao(bool chao) { noChao = chao; }

        bool getPodeMorrer() const { return podeMorrer; }

        bool getPodeMatar() const { return podeMatar; }

        float getEmpurrao() const { return empurrao; }

        int getVidas() const { return vidas; }

        void setVidas(int v) { vidas = v; }

        virtual bool tomarDano();

        Gerenciador_Grafico *getGerenciador() { return pGG; }

        bool getMorto() const { return morto; }

        void setMorto() { morto = true; }

        pair<Entidade *, int> gravar() {
            pair<Entidade *, int> p;
            p.first = this;
            p.second = id;
            return p;
        }

    protected:
        int id;

        Corpo_Grafico corpo;
        Gerenciador_Grafico *pGG;
        Plataforma *plat;

        Vector2f movimento;

        int vidas;

        bool noChao;

        bool podeMatar;
        bool podeMorrer;
        float empurrao;

        bool morto;
    };

}
