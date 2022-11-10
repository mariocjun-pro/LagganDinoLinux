#pragma once

#include "stdafx.h"
#include "Entidade.h"

class Personagem
        : public Entidade {
public:
    Personagem(Gerenciador_Grafico *gerenciador = NULL);

    virtual ~Personagem();

    virtual void imprimir();

    virtual void Colidindo(Vector2f direcao);

    virtual void executar();

    //virtual void morrer() = 0;
    virtual bool verificarColisao(Colisora *outro, Vector2f &direcao, float f);

    //Gerenciadoras de colis�o

    virtual bool verificarAtacando(Colisora *outro, Vector2f &direcao) {}
    //Retorna true se est� havendo colisao e o outro est� sobrevivendo � colis�o

    virtual bool verificarColisao(Colisora *outro, Vector2f &direcao) {
        return corpo.getColisora()->verificarColisao(outro, direcao, 0.0f);
    }
    //Retorna true se est� havendo colis�o

    virtual bool verificarAtaque(Colisora *outro) {}
    //Retorna true se est� havendo colis�o e se o jogador pode matar quem esta entidade

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


