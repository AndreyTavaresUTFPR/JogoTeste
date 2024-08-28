#include "Teia.h"

Teia::Teia() :
	Obstaculo(DANO, SOLIDEZ),
	lentidao(LENTIDAO_TEIA)
{
	setBody(sf::Vector2f(150.f, 150.f));
}

Teia::~Teia()
{

}

void Teia::setBody(sf::Vector2f pos)
{
	sf::RectangleShape b(sf::Vector2f(50.f, 50.f));
	body = b;
	if (!textura.loadFromFile("../Imagens/Teia.png"))
		cout << "Erro ao carregar Teia" << endl;
	body.setTexture(&textura);
}

void Teia::obstacular(Jogador* pJog)
{
	pJog->mudarVelocidade(LENTIDAO_TEIA);
}

void Teia::obstacular(Inimigo* pInim)
{
	pInim->mudarVelocidade(LENTIDAO_TEIA);
}

void Teia::executar()
{

}