#include "Entidade.h"


Entidade::Entidade() :
	Ente(),	cair(false), esquerda(false), direita(false)
{

}


Entidade::~Entidade()
{
}

void Entidade::liberarGravidade()
{
	cair = true;
}

void Entidade::liberarMovimento()
{
	esquerda = true;
	direita = true;
}

sf::RectangleShape Entidades::Entidade::getBody() 
{ 
	return body; 
}

void Entidade::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
}

sf::Vector2f Entidade::getCentro()
{
	sf::Vector2f centro((body.getPosition().x + body.getSize().x / 2.f), (body.getPosition().y + body.getSize().y / 2));
	return centro;
}

void Entidade::conferirColisao(sf::Vector2f colisao, sf::Vector2f centroOutraEnt) //Colisão diz o quanto um corpo entrou no outro, e centroOutraEnt é o centro do corpo da entidade comparada
{
	sf::Vector2f centro1 = getCentro(); //Centro da entidadade que chamou a função
	sf::Vector2f centro2 = centroOutraEnt; //Centro da entidade a ser comparada

		if (colisao.x > colisao.y) // Colisao vertical
		{
			if (centro1.y < centro2.y) //Centro1 acima do Centro2
			{
				getBody().setPosition(getBody().getPosition().x, (getBody().getPosition().y - colisao.y - 0.01f)); // Move a distancia da sua altura para cima da outra entidade;
				cair = false; //Está encima de outra entidade, não está caindo
			}
			else // Entidade que chamou a função está abaixo da outra entidade
				getBody().setPosition(getBody().getPosition().x, (getBody().getPosition().y + colisao.y + 0.01f));
		}
		else // Colisao horizontal
		{
			if (centro1.x < centro2.x) {
				getBody().setPosition((getBody().getPosition().x - colisao.x - 0.01f), getBody().getSize().y);
				direita = false;
			}
			else {
				getBody().setPosition((getBody().getPosition().x + getBody().getSize().x + 0.01f), getBody().getSize().y);
				esquerda = false;
			}
		}
	
}

