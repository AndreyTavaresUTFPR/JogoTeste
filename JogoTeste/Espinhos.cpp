#include "Espinhos.h"

Espinhos::Espinhos() :
	Obstaculo(DANO_ESPINHOS, SOLIDEZ_ESPINHOS)
{
	setBody(sf::Vector2f(0.f, 0.f));
}

Espinhos::~Espinhos()
{

}

void Espinhos::setBody(sf::Vector2f pos)
{
	sf::RectangleShape b(sf::Vector2f(75.f, 20.f));
	body = b;
	body.setFillColor(sf::Color::Red);
	body.move(pos); //Move para a parte inferior da jaenla;
}

void Espinhos::obstacular(Jogador* pJog)
{

}

void Espinhos::obstacular(Inimigo* pInim)
{

}

void Espinhos::executar()
{

}