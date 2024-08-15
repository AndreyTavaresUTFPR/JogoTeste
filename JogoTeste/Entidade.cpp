#include "Entidade.h"


Entidade::Entidade():
	body(sf::Vector2f(50.f, 50.f)), window(nullptr)
{
}


Entidade::~Entidade()
{
}

const sf::RectangleShape Entidades::Entidade::getBody() { return body; }

void Entidade::setWindow(sf::RenderWindow* w) {window = w;}

void Entidade::draw() { window->draw(body); }

