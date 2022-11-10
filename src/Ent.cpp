#include "Ent.h"

int Ent::cont(1);

Ent::Ent()
{
	id = cont++;
	srand(time(NULL));
}

Ent::~Ent()
{

}

