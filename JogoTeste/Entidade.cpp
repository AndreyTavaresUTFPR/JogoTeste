#include "Entidade.h"


Entidade::Entidade() :
	Ente()
{

}


Entidade::~Entidade()
{
}


sf::RectangleShape* Entidades::Entidade::getBody() 
{ 
	return &body; 
}

void Entidade::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
}

sf::Vector2f Entidade::getCentro()
{
	sf::Vector2f centro((body.getPosition().x + body.getSize().x / 2.f), (body.getPosition().y + body.getSize().y / 2));
	return centro;
}


