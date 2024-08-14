#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>


class Fase
{
private:
	ListaEntidades* listaEntidades;
	Inimigo* i1;
	Jogador* j1;
	sf::RenderWindow* window;

	void inicializaElementos();

public:
	Fase(Jogador* j1, sf::RenderWindow* window);
	~Fase();

	
	ListaEntidades* getListaEntidades();
};

