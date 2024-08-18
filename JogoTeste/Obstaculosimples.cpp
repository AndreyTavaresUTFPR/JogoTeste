#include "Obstaculosimples.h"

Obstaculosimples::Obstaculosimples() :
	Obstaculo(false)
{
	setBody();
}

Obstaculosimples::~Obstaculosimples()
{
}

void Obstaculosimples::setBody()
{
	//Cria um objeto Obstaculo que serve como "chão" da janela;
	sf::RectangleShape b(sf::Vector2f (800.f, 50.f)); 
	body = b;
	body.setFillColor(sf::Color::Green);
	body.move(sf::Vector2f (0.f, 750.f)); //Move para a parte inferior da jaenla;
}

void Obstaculosimples::executar()
{
}
