#pragma once
#include "stdafx.h"
#include "Entidade.h"

class Obstaculo
		: public Entidade {
public:
	Obstaculo();
	virtual ~Obstaculo();

	void Colidindo(Vector2f direcao) { };

protected:

};


