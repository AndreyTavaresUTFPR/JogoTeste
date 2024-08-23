#pragma once
#include "Personagem.h"
class Inimigo : public Personagem
{
protected:
	int nivel_maldade;

public:
	Inimigo();
	~Inimigo();

	virtual void liberarGravidade() = 0;
	virtual void liberarMovimento() = 0;
	virtual void mudarVelocidade(float fator) = 0;
	virtual void move() = 0;
	virtual void executar() = 0;
};

