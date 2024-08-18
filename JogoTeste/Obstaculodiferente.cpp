#include "Obstaculodiferente.h"

Obstaculodiferente::Obstaculodiferente() :
	Obstaculo(false)
{
	setBody();
}

Obstaculodiferente::~Obstaculodiferente()
{

}

void Obstaculodiferente::setBody()
{
	sf::RectangleShape b(sf::Vector2f(50.f, 50.f));
	body = b;
	body.setFillColor(sf::Color::Blue);
	body.move(sf::Vector2f(100.f, 700.f)); //Move para a parte inferior da jaenla;
}

void Obstaculodiferente::executar()
{

}