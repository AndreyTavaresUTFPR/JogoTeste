#include "Obstaculo.h"
#define DANO false


Obstaculos::Obstaculo::Obstaculo(bool dano, bool solidez):
	Entidade(), danoso(dano), solido(solidez)
{
}

Obstaculos::Obstaculo::~Obstaculo() 
{
}

bool Obstaculo::ehSolido() const
{
	return solido;
}
