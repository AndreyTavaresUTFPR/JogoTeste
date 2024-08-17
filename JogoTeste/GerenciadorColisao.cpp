#include "GerenciadorColisao.h"

GerenciadorColisao::GerenciadorColisao() :
	lPersonagens(nullptr), lObstaculos(nullptr)
{
	
}

GerenciadorColisao::~GerenciadorColisao()
{

}

void GerenciadorColisao::setListas(ListaEntidades* pPers, ListaEntidades* pObst)
{
	lPersonagens = pPers;
	lObstaculos = pObst;
}

sf::Vector2f GerenciadorColisao::calcularColisao(Entidade* ent1, Entidade* ent2)
{
	sf::Vector2f centro1((ent1->getBody().getPosition().x + (ent1->getBody().getSize().x / 2)), (ent1->getBody().getPosition().y + (ent1->getBody().getSize().y / 2)));
	sf::Vector2f centro2((ent2->getBody().getPosition().x + (ent2->getBody().getSize().x / 2)), (ent2->getBody().getPosition().y + (ent2->getBody().getSize().y / 2)));

	sf::Vector2f ds(fabsf(centro1.x - centro2.x), fabsf(centro1.y - centro2.y));
	//sf::Vector2f ds(fabsf(/* ent1->getBody().getPosition().x + ent1->getBody().getSize().x - */ent2->getBody().getPosition().x - ent1->getBody().getPosition().x),
		//			fabsf(/*ent1->getBody().getPosition().y + ent1->getBody().getSize().y - */ent2->getBody().getPosition().y - ent1->getBody().getPosition().y));
	return ds;
}

void GerenciadorColisao::repararColisao(Entidade* ent1, Entidade* ent2)
{
	sf::Vector2f centro1((ent1->getBody().getPosition().x + (ent1->getBody().getSize().x / 2)), (ent1->getBody().getPosition().y + (ent1->getBody().getSize().y / 2)));
	sf::Vector2f centro2((ent2->getBody().getPosition().x + (ent2->getBody().getSize().x / 2)), (ent2->getBody().getPosition().y + (ent2->getBody().getSize().y / 2)));

	sf::Vector2f ds(fabsf(centro1.x - centro2.x), fabsf(centro1.y - centro2.y));

	float colisaoX = ((ent1->getBody().getSize().x/2.f + ent2->getBody().getSize().x/2.f) - ds.x);
	float colisaoY = ((ent1->getBody().getSize().y/2.f + ent2->getBody().getSize().y / 2.f) - ds.y);
	ent1->cair = true;
	if (colisaoX > 0.f && colisaoY > 0.f)
	{
		if (colisaoX > colisaoY)
		{
			if (centro1.y < centro2.y) {
				ent1->getBody().setPosition(ent1->getBody().getPosition().x, (ent2->getBody().getPosition().y - ent1->getBody().getSize().y));
				ent1->cair = false;
			}
			else
				ent1->getBody().setPosition(ent1->getBody().getPosition().x, (ent2->getBody().getPosition().y + ent2->getBody().getSize().y));
		}
		else
		{
			if (centro1.y < centro2.y)
				ent1->getBody().setPosition(ent1->getBody().getPosition().x, (ent1->getBody().getPosition().y - colisaoY));
			else
				ent1->getBody().setPosition(ent1->getBody().getPosition().x, (ent1->getBody().getPosition().y + colisaoY));
		}
	}
}

bool GerenciadorColisao::verificarColisao(Entidade* ent1, Entidade* ent2)
{
	/*sf::Vector2f ds((ent1->getBody().getPosition().x + ent1->getBody().getSize().x - ent2->getBody().getPosition().x),
					(ent1->getBody().getPosition().y + ent1->getBody().getSize().y - ent2->getBody().getPosition().x))
	if ((ent1->getBody().getPosition().x + ent1->getBody().getSize().x) -)
	return (ent1->getBody().getPosition().x)*/
	sf::Vector2f centro1((ent1->getBody().getPosition().x + (ent1->getBody().getSize().x / 2)), (ent1->getBody().getPosition().y + (ent1->getBody().getSize().y / 2)));
	sf::Vector2f centro2((ent2->getBody().getPosition().x + (ent2->getBody().getSize().x / 2)), (ent2->getBody().getPosition().y + (ent2->getBody().getSize().y / 2)));

	sf::Vector2f ds(fabsf(centro1.x - centro2.x), fabsf(centro1.y - centro2.y));

	return (ds.x < (ent1->getBody().getSize().x / 2 + ent2->getBody().getSize().x / 2) && ds.y < (ent1->getBody().getSize().y / 2 + ent2->getBody().getSize().y / 2));
}

void GerenciadorColisao::executar()
{
	
	Entidade* ent1, *ent2;
	int i, j;
	for (i = 0; i < lPersonagens->LEs.getLen(); i++)
	{
		ent1 = lPersonagens->LEs.getItem(i);
		for (j = i + 1; j < lPersonagens->LEs.getLen(); j++)
		{
			ent2 = lPersonagens->LEs.getItem(j);
			//repararColisao(ent1, ent2);
		}
	}
	for (i = 0; i < lPersonagens->LEs.getLen(); i++)
	{
		ent1 = lPersonagens->LEs.getItem(i);
		for (j = 0; j < lObstaculos->LEs.getLen(); j++)
		{
			ent2 = lObstaculos->LEs.getItem(j);
			repararColisao(ent1, ent2);
		}
	}
	
}