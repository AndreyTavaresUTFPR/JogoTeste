#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "Fase.h"


#define WIDTH  800
#define HEIGHT 800


class Jogo
{
private:	
	sf::RenderWindow window;
	Jogador* jogador1;
	ListaEntidades* LEs;
	Fase* fase1;
	Entidade* temp; // Ponteiro temporario auxiliar
	int lenLEs;     // tamanho da lista de entidades

public:
	Jogo();
	~Jogo();

	void executar();
};

