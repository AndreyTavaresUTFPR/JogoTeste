#pragma once
#include <SFML/Graphics.hpp>


class Entidade
{
protected:
	sf::RectangleShape body;
	sf::RenderWindow* window;

public:
	Entidade();
	virtual ~Entidade();

	void setWindow(sf::RenderWindow* w);
	void draw();
};

