#include "Gelo.h"

Gelo::Gelo():
	Obstaculo(false, true)
{
	setBody(sf::Vector2f(100.f, 20.f));
	lisura = (float)(rand() % 3 + 1) * 0.2f + 1.f; //Tr�s possibilidades de valor para o qu�o liso � o gelo
}

Gelo::~Gelo()
{

}

void Gelo::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
	atualizarTextura("../Imagens/Gelo.png");

	
}

void Gelo::obstacular(Jogador* pJog)
{
	if (pJog->getCentro().x )
	pJog->mudarVelocidade(lisura);
}

void Gelo::obstacular(Inimigo* pInim)
{
	pInim->mudarVelocidade(lisura);
}

void Gelo::executar()
{

}