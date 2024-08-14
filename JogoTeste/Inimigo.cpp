#include "Inimigo.h"


Inimigo::Inimigo():
	Personagem(), vida(100)
{
	body.setFillColor(sf::Color::Magenta);
	body.setPosition(sf::Vector2f(400.f, 250.f));
}

Inimigo::~Inimigo()
{
}
