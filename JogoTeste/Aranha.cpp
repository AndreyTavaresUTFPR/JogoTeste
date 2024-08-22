#include "Aranha.h"

Aranha::Aranha():
	Inimigo(), pulo(VELOCIDADE_HORIZONTAL, VELOCIDADE_PULO)
{
	timer_gravidade.restart();
}

Aranha::~Aranha()
{
}


void Aranha::pular()
{
	float tempo = timer_gravidade.getElapsedTime().asSeconds();
	body.move(sf::Vector2f(pulo.x, pulo.y + (9.8f / 2.f * (tempo * tempo))));
}


void Aranha::move()
{
	pular();

	if (!cair) {
		timer_gravidade.restart();
	}
}

void Aranha::executar()
{
	if (body.getPosition().x > 800-body.getSize().x || body.getPosition().x < 0)
		pulo.x = -pulo.x;

	move();
}

void Aranha::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
	body.setFillColor(sf::Color::Yellow);
	body.setPosition(sf::Vector2f(700.f, 250.f));
}