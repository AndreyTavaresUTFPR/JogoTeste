#include "Solo.h"
#define DANO false
#define SOLIDEZ true

Solo::Solo() :
	Obstaculo(DANO, SOLIDEZ)
{
	setBody();
}

Solo::~Solo()
{
}

void Solo::setBody()
{
	//Cria um objeto Obstaculo que serve como "ch�o" da janela;
	sf::RectangleShape b(sf::Vector2f (800.f, 50.f)); 
	body = b;
	body.setFillColor(sf::Color::Green);
	body.move(sf::Vector2f (0.f, 750.f)); //Move para a parte inferior da jaenla;
}

void Solo::executar()
{
}
