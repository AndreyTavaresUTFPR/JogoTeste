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

sf::Vector2f Entidade::getCentro()
{
	centro = sf::Vector2f((body.getPosition().x + body.getSize().x / 2.f), (body.getPosition().y + body.getSize().y / 2));
	return centro;
}


