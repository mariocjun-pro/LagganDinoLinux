#include "Corpo_Grafico.h"

Corpo_Grafico::Corpo_Grafico()
{
	corpo = NULL;
	animacao = NULL;
	colisor = NULL;
	textura = NULL;
}

Corpo_Grafico::~Corpo_Grafico()
{
	delete corpo;
	delete animacao;
	delete colisor;
	delete textura;
}

void Corpo_Grafico::inicializa(Vector2f tam, Texture* tex)
{
	corpo = new RectangleShape(tam);
	corpo->setOrigin(tam/2.0f);
	corpo->setFillColor(Color::White);

	corpo->setTexture(tex);

	colisor = new Colisora(corpo);
	textura = new Texture();
	animacao = new Animadora(this);

	corpo->setTexture(textura);

}

void Corpo_Grafico::inicializaAnimadora(Vector2f margem, Vector2u quantidadeQuadros, Vector2u TotalDeQuadros)
{
	animacao->inicializa(margem, quantidadeQuadros, TotalDeQuadros);
}

void Corpo_Grafico::atualizaAnimacao(float dT, bool aDireita, unsigned int comecoP, unsigned int quantidadeQuadrosX,
		float troca, unsigned int linha)
{
	animacao->atualizar(dT, aDireita, comecoP, quantidadeQuadrosX, troca, linha);
}

