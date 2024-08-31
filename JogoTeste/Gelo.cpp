#include "Gelo.h"

Gelo::Gelo():
	Obstaculo(false, true)
{
	setBody(sf::Vector2f(100.f, 20.f));
	lisura = (float)(rand() % 3 + 2); //Três possibilidades de valor para o quão liso é o gelo
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
	//TO DO: Talvez mudar a textura com o tempo...
}