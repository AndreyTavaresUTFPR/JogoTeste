#include "Espinhos.h"

Espinhos::Espinhos() :
	Obstaculo(true, true)
{
	muitosEspinhos = (bool)(rand() % 2);
	setBody(sf::Vector2f(40.f, 20.f));
}

Espinhos::~Espinhos()
{

}

void Espinhos::setBody(sf::Vector2f tam)
{
	if (muitosEspinhos)
	{
		tam.x *= 2.f; //Dobra a quantidade dos espinhos
		sf::RectangleShape b(tam);
		body = b;
		textura.loadFromFile("../Imagens/Espinhos2.png");
		body.setTexture(&textura);
	}
	else
	{
		sf::RectangleShape b(tam);
		body = b;
		textura.loadFromFile("../Imagens/Espinhos.png");
		body.setTexture(&textura);
	}
}

void Espinhos::obstacular(Jogador* pJog)
{
	pJog->operator--();
	pJog->setPulando();
}

void Espinhos::obstacular(Inimigo* pInim)
{
	//Não faz nada com o Inimigo além de colidir...
}

void Espinhos::executar()
{
	//TO DO: Talvez mudar a aparencia com o tempo...
}