#include "Teia.h"

Teia::Teia() :
	Obstaculo(false, false)
{
	setBody(sf::Vector2f(50.f, 50.f));
	lentidao = (float)(rand() % 3 + 1) * 0.2f; //Três possibilidades de valor para a lentidão da teia
}

Teia::~Teia()
{

}

void Teia::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
	if (!textura.loadFromFile("../Imagens/Teia.png"))
		cout << "Erro ao carregar Teia" << endl;
	body.setTexture(&textura);
}

void Teia::obstacular(Jogador* pJog)
{
	pJog->mudarVelocidade(lentidao);
}

void Teia::obstacular(Inimigo* pInim)
{
	pInim->mudarVelocidade(lentidao);
}

void Teia::executar()
{

}