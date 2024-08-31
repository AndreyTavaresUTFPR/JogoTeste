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
	//Apenas Plataforma, n�o faz nada al�m de colidir
}

void Solo::obstacular(Inimigo* pInim)
{
	//Apenas Plataforma, n�o faz nada al�m de colidir
}

void Solo::executar()
{
	//Apenas Plataforma, n�o faz nada al�m de colidir
}
