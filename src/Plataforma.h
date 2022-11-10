#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Corpo_Grafico.h"

class Plataforma
		: public Entidade {
public:
	Plataforma(Vector2f tam = Vector2f(100.0f, 100.0f), Texture* tex = NULL);
	~Plataforma();

	void executar() { corpo.atualizaAnimacao(0.1, true, 0, 0, 0, 0); };
	void Colidindo(Vector2f direcao) { };

	//Gerenciadoras de colis�o
	bool verificarAtacando(Colisora* outro, Vector2f& direcao)
	//Retorna true se est� havendo colisao e o outro est� sobrevivendo � colis�o
	{ return true; }

	bool verificarColisao(Colisora* outro, Vector2f& direcao);
	//Retorna true se est� havendo colis�o

	bool verificarAtaque(Colisora* outro, Vector2f& direcao)
	//Retorna true se est� havendo colis�o e se o jogador pode matar quem esta entidade
	{ return false; }

private:

};

