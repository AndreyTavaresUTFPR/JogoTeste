#include "Personagem.h"

Personagens::Personagem::Personagem():
	Entidade(), vida(5)
{
}

Personagens::Personagem::~Personagem()
{
	vida = 0;
}
