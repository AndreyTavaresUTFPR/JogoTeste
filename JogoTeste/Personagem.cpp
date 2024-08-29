#include "Personagem.h"
#define VIDA_PADRAO 100


Personagens::Personagem::Personagem() :
	Entidade(), vida(VIDA_PADRAO), vel(0.f, 0.f),
	cair(false), esquerda(false), direita(false), vivo(true)
{
}

Personagens::Personagem::~Personagem()
{
	vida = -1;
}

void Personagem::liberarGravidade()
{
	cair = true;
	vel.y = 0.15f;
}

void Personagem::liberarMovimento()
{
	esquerda = true;
	direita = true;
	vel.x = 0.15f;
}

void Personagem::conferirColisao(sf::Vector2f colisao, sf::Vector2f centroOutraEnt) //Colisão diz o quanto um corpo entrou no outro, e centroOutraEnt é o centro do corpo da entidade comparada
{
	sf::Vector2f centro1 = getCentro(); //Centro da entidadade que chamou a função
	sf::Vector2f centro2 = centroOutraEnt; //Centro da entidade a ser comparada

	if (colisao.x > colisao.y) // Colisao vertical
	{
		if (centro1.y < centro2.y) //Centro1 acima do Centro2
		{
			body.setPosition(body.getPosition().x, body.getPosition().y - colisao.y); // Move a distancia da sua altura para cima da outra entidade;
			cair = false; //Está encima de outra entidade, não está caindo
		}
		else // Entidade que chamou a função está abaixo da outra entidade
			body.setPosition(body.getPosition().x, body.getPosition().y + colisao.y);
	}
	else // Colisao horizontal
	{
		if (centro1.x < centro2.x) {
			body.setPosition(body.getPosition().x - colisao.x, body.getPosition().y);
			direita = false;
		}
		else {
			body.setPosition(body.getPosition().x + colisao.x, body.getPosition().y);
			esquerda = false;
		}
	}

}

void Personagem::receberDano()
{
	vida--;
	if (vida <= 0)
		vivo = false;
}

void Personagem::operator--()
{
	vida--;
	if (vida <= 0)
		vivo = false;
}

int Personagem::getVida() const
{
	return vida;
}

bool Personagem::getVivo() const
{
	return vivo;
}