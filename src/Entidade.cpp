#include "Entidade.h"
#include "Plataforma.h"

Entidade::Entidade(Gerenciador_Grafico* gerenciador) :
		Ent()
{
	plat = NULL;
	pGG = gerenciador;
}

Entidade::~Entidade()
{

}

void Entidade::executar()
{

}

void Entidade::imprimir()
{
	pGG->desenhar(corpo.getCorpo());
}
