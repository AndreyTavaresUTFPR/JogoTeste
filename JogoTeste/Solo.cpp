#include "Solo.h"
#define DANO false
#define SOLIDEZ true

Solo::Solo() :
	Obstaculo(DANO, SOLIDEZ)
{

}

Solo::~Solo()
{

}

void Solo::setBody(sf::Vector2f tam, sf::Vector2f pos)
{
	sf::RectangleShape b(tam);
	body = b;
	body.setFillColor(sf::Color::Green);
	body.setPosition(pos);
}

void Solo::executar()
{

}
