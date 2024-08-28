#pragma once
#include "GerenciadorGrafico.h"

class Ente 
{
protected:
	GerenciadorGrafico* pGrafico;
	sf::Texture textura;
	sf::Sprite figura;
	//int id;

public:
	Ente();
	~Ente();

	virtual void executar() = 0;
	//virtual void desenhar() = 0;
};