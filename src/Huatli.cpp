#include "Huatli.h"

Huatli::Huatli(Gerenciador_Grafico* g) :
		Jogador(g), pulo(700)
{
	corpo.inicializa(Vector2f(100.0f, 130.0f), NULL);
	corpo.setTextura("../Texturas//Dinos//doux.png");
	corpo.inicializaAnimadora(Vector2f(0.0f, -2.5f), Vector2u(4, 1), Vector2u(24, 1));

	hitbox.setTextura("../Texturas//Efeitos//sunburn.png");
	hitbox.inicializaAnimadora(Vector2f(0.0f, 0.0f), Vector2u(8, 8), Vector2u(8, 8));

	posInicial = Vector2f(corpo.getPosicao().x/2.0f, 710);
	corpo.getCorpo()->setPosition(posInicial);

}

Huatli::~Huatli()
{

}

void Huatli::mover()
{
	Vector2u animacao(0, 0);
	float tempoTrocaAnimacao = 0.3f;
	float dT = pGG->getDt();
	movimento.x = 0;

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		movimento.x += velocidade;
		lado = 1;
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		movimento.x -= velocidade;
		lado = -1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Space) && noChao) {
		noChao = false;
		movimento.y = -sqrtf(2.0*981.0*pulo);
	}

	movimento.y += 981.0*dT*2.5f;

	if (Keyboard::isKeyPressed(Keyboard::W)) {
		movimento.y -= 10.0f;
	}

	corpo.getCorpo()->move(movimento*dT);
	animar(movimento);
}
