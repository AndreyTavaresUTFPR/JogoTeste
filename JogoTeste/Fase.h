#pragma once
#include "Jogador.h"
#include "Esqueleto.h"
#include "Aranha.h"
#include "Solo.h"
#include "Obstaculodiferente.h"
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>


class Fase
{
private:
	ListaEntidades* lPersonagens;
	ListaEntidades* lObstaculos;
	Esqueleto* e1;
	Aranha* a1;
	Jogador* j1;
	Solo* solo1;
	Obstaculodiferente* obst1;

	void inicializaElementos();

public:
	Fase(Jogador* j1);
	~Fase();

	
	ListaEntidades* getListaPersonagens();
	ListaEntidades* getListaObstaculos();
};

