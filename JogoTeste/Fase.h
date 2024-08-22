#pragma once
#include "Jogador.h"
#include "Esqueleto.h"
#include "Aranha.h"
#include "Obstaculosimples.h"
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
	Obstaculosimples* os1;
	Obstaculodiferente* os2;
	sf::RenderWindow* window;

	void inicializaElementos();

public:
	Fase(Jogador* j1, sf::RenderWindow* window);
	~Fase();

	
	ListaEntidades* getListaPersonagens();
	ListaEntidades* getListaObstaculos();
};

