#include "Solo.h"
#define DANO false
#define SOLIDEZ true

Solo::Solo() :
	Obstaculo(DANO, SOLIDEZ)
{

}

Solo::~Solo()
{

}

void Solo::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
}

void Solo::obstacular(Jogador* pJog)
{

}

void Solo::obstacular(Inimigo* pInim)
{

}

void Solo::executar()
{

}
