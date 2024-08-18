#include "Entidade.h"


Entidade::Entidade() :
	cair(true), esquerda(true), direita(true)
{

}


Entidade::~Entidade()
{
}

sf::RectangleShape Entidades::Entidade::getBody() { return body; }

void Entidade::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
}

void Entidade::conferirColisao(sf::Vector2f colisao, Entidade* outraEnt)
{
	sf::Vector2f pos1 = body.getPosition();
	sf::Vector2f tam1 = body.getSize();
	sf::Vector2f pos2 = outraEnt->getBody().getPosition();
	sf::Vector2f tam2 = outraEnt->getBody().getSize();
	sf::Vector2f centro1((pos1.x + (tam1.x / 2.f)), (pos1.y + (tam1.y / 2)));
	sf::Vector2f centro2((pos2.x + (tam2.x / 2.f)), (pos2.y + (tam2.y / 2)));
	/*
	if (colisao.x > colisao.y)
	{
		if ((pos1.y + (tam1.y / 2.f))  < (pos2.y + (tam2.y / 2.f))) {
			body.setPosition(pos1.x, (pos1.x - colisao.x));
			cair = false;
		}
		else
			body.setPosition(pos1.x, (pos1.y + colisao.y));
	}
	else
	{
		if ((pos1.x + (tam1.x / 2.f)) < (pos2.x + (tam2.x / 2.f)))
			body.setPosition((pos1.x - colisao.x), pos1.y);
		else
			body.setPosition((pos1.x + colisao.x), pos1.y);
	}*/
	if (colisao.x > colisao.y)
	{
		if (centro1.y < centro2.y) {
			body.setPosition(body.getPosition().x, (outraEnt->getBody().getPosition().y - body.getSize().y));
			cair = false;
		}
		else
			body.setPosition(body.getPosition().x, (outraEnt->getBody().getPosition().y + outraEnt->getBody().getSize().y));
	}
	else
	{
		if (centro1.x < centro2.x)
			body.setPosition(body.getPosition().x - colisao.x, body.getPosition().y);
		else
			body.setPosition(body.getPosition().x + colisao.x, body.getPosition().y);
	}
}

