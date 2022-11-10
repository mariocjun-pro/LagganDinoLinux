#pragma once

#include "stdafx.h"
#include "Ent.h"
#include "Gerenciador_Grafico.h"
#include "Corpo_Grafico.h"
#include "Colisora.h"

class Plataforma;

class Entidade
        : public Ent {
public:
    explicit Entidade(Gerenciador_Grafico *gerenciador = NULL);

    virtual ~Entidade();

    virtual void executar() = 0;

    virtual void mover() {}

    virtual void imprimir();

    virtual void Colidindo(Vector2f direcao) = 0;

    //Sets e gets

    Vector2f getPosicao() { return corpo.getCorpo()->getPosition(); }

    Vector2f getTamanho() { return corpo.getCorpo()->getSize(); }

    Colisora *getColisora() { return corpo.getColisora(); }

    Corpo_Grafico *getCorpoGraf() { return &corpo; }

    Plataforma *getPlataforma() { return plat; }

    void setPlataforma(Plataforma *p) { plat = p; }

    //virtual bool verificarColisao(Colisora* outro, Vector2f& direcao) { return corpo.getColisora()->verificarColisao(outro, direcao, f); }


    //Gerenciadoras de colisão

    virtual bool verificarAtacando(Colisora *outro, Vector2f &direcao) { return true; }
    //Retorna true se está havendo colisão e o outro está sobrevivendo à colisão

    virtual bool verificarColisao(Colisora *outro, Vector2f &direcao) {
        return corpo.getColisora()->verificarColisao(outro, direcao, 1.0f);
    }
    //Retorna true se está havendo colisão

    virtual bool verificarAtaque(Colisora *outro, Vector2f &direcao) { return false; }
    //Retorna true se está havendo colisão e se o jogador pode matar quem esta entidade

    void setGerenciador(Gerenciador_Grafico *gerenciador) { pGG = gerenciador; }

protected:
    Corpo_Grafico corpo;
    Gerenciador_Grafico *pGG;
    Plataforma *plat;
};


