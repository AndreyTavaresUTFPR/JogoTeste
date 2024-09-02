#include "Solo.h"

Solo::Solo() :
	Obstaculo(false, true)
{

}

Solo::Solo(const char* tipo) :
	Obstaculo(false, true), tipo_plataforma(tipo)
{
	tipo_plataforma = tipo;
}

Solo::~Solo()
{

}

void Solo::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
	if (tipo_plataforma == "Teto1")
		atualizarTextura("../Imagens/Teto1.png");
	else if (tipo_plataforma == "Teto2")
		atualizarTextura("../Imagens/Teto2.png");
	else if (tipo_plataforma == "Parede1")
		atualizarTextura("../Imagens/Parede1.png");
	else if (tipo_plataforma == "Parede2")
		atualizarTextura("../Imagens/Parede2.png");
	else if (tipo_plataforma == "Andar1")
		atualizarTextura("../Imagens/Andar1.png");
	else if (tipo_plataforma == "Andar2")
		atualizarTextura("../Imagens/Andar2.png");
	else if (tipo_plataforma == "Escada")
	{
		if (tam.x > 0.f && tam.x < 100.f)
			atualizarTextura("../Imagens/Escada1.png");
		else if (tam.x >= 100.f && tam.x < 200.f)
			atualizarTextura("../Imagens/Escada2.png");
		else
			atualizarTextura("../Imagens/Escada3.png");
	}
}

void Solo::obstacular(Jogador* pJog)
{
	//Apenas Plataforma, não faz nada além de colidir
}

void Solo::obstacular(Inimigo* pInim)
{
	//Apenas Plataforma, não faz nada além de colidir
}

void Solo::executar()
{
	//Apenas Plataforma, não faz nada além de colidir
}
