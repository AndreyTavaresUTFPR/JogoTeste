#pragma once
#include "Jogador.h"
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>


class Fase
{
protected:
	ListaEntidades* lPersonagens;
	ListaEntidades* lObstaculos;
	Jogador* j1;

	virtual void inicializaElementos() = 0;

public:
	Fase(Jogador* j1);
	virtual ~Fase();

	
	ListaEntidades* getListaPersonagens();
	ListaEntidades* getListaObstaculos();
};

