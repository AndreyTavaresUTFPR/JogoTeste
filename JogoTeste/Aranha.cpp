#include "Aranha.h"

Aranha::Aranha():
	Inimigo(), pulo(VELOCIDADE_HORIZONTAL, VELOCIDADE_PULO)
{
	timer_pulo.restart();
	timer_gravide.restart();
}

Aranha::~Aranha()
{
}

void Aranha::move()
{
	if (timer_pulo.getElapsedTime().asSeconds() >= 3.f) {
		body.move(pulo);
	}

	if (cair) {
		body.move(sf::Vector2f(0.f, 9.8f / 2.f * timer_pulo.getElapsedTime().asSeconds() * timer_pulo.getElapsedTime().asSeconds()));
	}
	else {
		timer_gravide.restart();
		// timer_pulo.restart();
		cair = false;
	}

}

void Aranha::executar()
{
	move();
}

void Aranha::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
	body.setFillColor(sf::Color::Yellow);
	body.setPosition(sf::Vector2f(700.f, 250.f));
}