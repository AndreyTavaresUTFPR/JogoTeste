#include "Personagem.h"
#define VIDA_PADRAO 100


Personagens::Personagem::Personagem() :
	Entidade(), vida(VIDA_PADRAO), vel(0.f, 0.f)
{
}

Personagens::Personagem::~Personagem()
{
	vida = -1;
}
