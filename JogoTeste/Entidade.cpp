#include "Entidade.h"


Entidade::Entidade()
	//body(sf::Vector2f(50.f, 50.f)) window(nullptr)
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

/*void Entidade::setWindow(sf::RenderWindow* w) { window = w; }

void Entidade::draw() { window->draw(body); }*/

