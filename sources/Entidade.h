#ifndef LAGGANDOGAME_ENTIDADE_H
#define LAGGANDOGAME_ENTIDADE_H

#include "stdafx.h"
#include "Ente.h"

class Entidade
        : public Ente {
protected:
    float movimento_x;
    float movimento_y;

    int idObjeto;
    static int idObjetoAtual;

public:
    Entidade();

    virtual ~Entidade();

    void setDimensoes(float x, float y);

    float getDimensoesX() const;

    float getDimensoesY() const;

    void setPosicao(float x, float y);

    float getPosicaoX() const;

    float getPosicaoY() const;

    void setMovimento(float x, float y);

    float getMovimentoX() const;

    float getMovimentoY() const;

    void setIdObjeto(int id);

    int getIdObjeto() const;

    void incrementarIdObjetoAtual();

    int getIdObjetoAtual() const;

    void mover(float movimento_x, float movimento_y);

    void desenhar();
};

#endif //LAGGANDOGAME_ENTIDADE_H
