#include "Obstaculo.h"

Obstaculos::Obstaculo::Obstaculo() :
	Entidade(), danoso(false), solido(false)
{
	tipo = 3;
}

Obstaculos::Obstaculo::Obstaculo(bool dano, bool solidez):
	Entidade(), danoso(dano), solido(solidez)
{
	tipo = 3;
}

Obstaculos::Obstaculo::~Obstaculo() 
{
}

bool Obstaculo::ehSolido() const
{
	return solido;
}
