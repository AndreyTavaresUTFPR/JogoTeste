#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"

class Jogo
{
private:	
	sf::RenderWindow window;
	Jogador jogador1;
	Inimigo inimigo1;

public:
	Jogo();
	~Jogo();

	void executar();
};

