#include "Teia.h"
#define DANO false
#define SOLIDEZ false
#define LENTIDAO_TEIA 0.05f

Teia::Teia() :
	Obstaculo(DANO, SOLIDEZ),
	lentidao(LENTIDAO_TEIA)
{
	setBody(sf::Vector2f(150.f, 725.f));
}

Teia::~Teia()
{

}

void Teia::setBody(sf::Vector2f pos)
{
	sf::RectangleShape b(sf::Vector2f(50.f, 50.f));
	body = b;
	body.setFillColor(sf::Color::Blue);
	body.move(pos); //Move para a parte inferior da jaenla;
}

void Teia::executar()
{

}