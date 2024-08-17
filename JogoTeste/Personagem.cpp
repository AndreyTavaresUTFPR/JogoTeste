#include "Personagem.h"
#define VIDA_PADRAO 100


Personagens::Personagem::Personagem() :
	Entidade(), vida(VIDA_PADRAO)
{
}

Personagens::Personagem::~Personagem()
{
	vida = -1;
}
