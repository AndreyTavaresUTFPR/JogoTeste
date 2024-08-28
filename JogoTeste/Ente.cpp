#include "Ente.h"

Ente::Ente() :
	pGrafico(pGrafico->getGerenciadorGrafico()), textura()
{

}

Ente::~Ente()
{

}

void Ente::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
}

sf::RectangleShape* Ente::getBody()
{
	return &body;
}

void Ente::atualizarTextura(sf::Texture texture)
{
	textura = texture;
	body.setTexture(&textura);
}