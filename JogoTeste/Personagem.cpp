#include "Personagem.h"
#define VIDA_PADRAO 10


Personagem::Personagem() :
	Entidade(), vel(sf::Vector2f(0.f, 0.f)), alteracaoVel(1.f), vida(VIDA_PADRAO),
	cair(false), esquerda(false), direita(false)
{
	tempo_queda.restart();
}

Personagem::Personagem(int vida) :
	Entidade(), vel(sf::Vector2f(0.f, 0.f)), alteracaoVel(1.f), vida(vida),
	cair(false), esquerda(false), direita(false)
{
	tempo_queda.restart();
}

Personagens::Personagem::~Personagem()
{
	vida = -1;
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

void Personagem::operator--()
{
	vida--;
	if (vida <= 0)
		noJogo = false;
}

int Personagem::getVida() const
{
	return vida;
}
