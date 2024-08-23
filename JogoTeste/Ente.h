#pragma once
#include "GerenciadorGrafico.h"

class Ente 
{
protected:
	GerenciadorGrafico* pGrafico;
	//int id;
	//figura* pFig;

public:
	Ente();
	~Ente();

	virtual void executar() = 0;
	//virtual void desenhar() = 0;
};