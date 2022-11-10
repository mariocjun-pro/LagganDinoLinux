#include "Jogo.h"

Jogo::Jogo()
{
	montanha = new Montanha(this);
	j1 = montanha->getJogador();
	srand(time(NULL));
}

Jogo::~Jogo()
{

}

void Jogo::executar()
{
	while (GG.getAberto()) {
		dT = clock.restart().asSeconds();
		if (dT>1.0f/20.0f)
			dT = 1.0f/20.0f;

		GG.setDt(dT);

		GG.limpar();
		GG.leEventos();

		montanha->executar();

		GG.getVisao()->setCenter(Vector2f(j1->getPosicao().x+1280.0f/4.0f, 960.0f/2.0f));

		GG.getJanela()->display();
	}
}
