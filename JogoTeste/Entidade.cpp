#include "Entidade.h"


Entidade::Entidade() :
	Ente(), noJogo(true), tipo(0)
{

}


Entidade::~Entidade()
{
}

int Entidade::getTipo() const
{
	return tipo;
}

bool Entidade::getNoJogo() const
{
	return noJogo;
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

sf::Vector2f Entidade::getCentro() const
{
	sf::Vector2f centro((body.getPosition().x + body.getSize().x / 2.f), (body.getPosition().y + body.getSize().y / 2));
	return centro;
}


