#pragma once

#include "stdafx.h"
#include "Entidade.h"

class Personagem
        : public Entidade {
public:
    explicit Personagem(Gerenciador_Grafico *gerenciador = NULL);

    virtual ~Personagem();

    virtual void imprimir();

    virtual void Colidindo(Vector2f direcao);

    virtual void executar();

    //virtual void morrer() = 0;
    virtual bool verificarColisao(Colisora *outro, Vector2f &direcao, float f);

    //Gerenciadoras de colisão

    virtual bool verificarAtacando(Colisora *outro, Vector2f &direcao) { return false; }
    //Retorna true se está havendo colisao e o outro está sobrevivendo à colisão

    virtual bool verificarColisao(Colisora *outro, Vector2f &direcao) {
        return corpo.getColisora()->verificarColisao(outro, direcao, 0.0f);
    }
    //Retorna true se está havendo colisão

    virtual bool verificarAtaque(Colisora *outro) { return false; }
    //Retorna true se está havendo colisão e se o jogador pode matar quem esta entidade


    virtual void animar(Vector2f movimento);

protected:
    int vidas;
    float velocidade;
    float totalT;
    bool noChao;
    short int lado;
    Vector2f movimento;
    bool aDireita;
    bool atacando;
};


