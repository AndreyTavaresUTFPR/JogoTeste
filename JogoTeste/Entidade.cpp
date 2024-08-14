#include "Entidade.h"


Entidade::Entidade():
	body(sf::Vector2f(100.f, 100.f)), window(NULL)
{
}


Entidade::~Entidade()
{
}

void Entidade::setWindow(sf::RenderWindow* w) {window = w;}

void Entidade::draw() {window->draw(body);}

