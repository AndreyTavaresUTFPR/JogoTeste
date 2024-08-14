#pragma once
#include <SFML/Graphics.hpp>


class Jogo
{
private:
	sf::RenderWindow window;
	sf::RectangleShape shape;

public:
	Jogo();

	void executar();
};

