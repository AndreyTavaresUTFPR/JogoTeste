#pragma once
#include "Personagem.h"
#include "Jogador.h"

class Inimigo : public Personagem
{
protected:
	int nivel_maldade;
	sf::Clock relogio;

public:
	Inimigo();
	Inimigo(int vida);
	virtual ~Inimigo();

	virtual void mudarVelocidade(float fator) = 0;
	virtual void danificar(Jogador* pJog) = 0;
	virtual void move() = 0;
	virtual void executar() = 0;
};

