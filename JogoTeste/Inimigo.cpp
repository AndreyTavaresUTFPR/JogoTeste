#include "Inimigo.h"


Inimigo::Inimigo():
	Entidade(), vida(100)
{
	body.setFillColor(sf::Color::Magenta);
	body.setPosition(sf::Vector2f(400.f, 250.f));
}

Inimigo::~Inimigo()
{
}
