#include "GerenciadorColisao.h"

GerenciadorColisao::GerenciadorColisao(ListaEntidades* pPers, ListaEntidades* pObst) :
	lPersonagens(pPers), lObstaculos(pObst)
{
	
}

GerenciadorColisao::~GerenciadorColisao()
{

}

sf::Vector2f GerenciadorColisao::calcularColisao(Entidade* ent1, Entidade* ent2)
{
	sf::Vector2f ds(0.f, 0.f);
	sf::Vector2f centro1((ent1->getBody().getPosition().x + ent1->getBody().getSize().x / 2.f), (ent1->getBody().getPosition().y + ent1->getBody().getSize().y / 2));
	sf::Vector2f centro2((ent2->getBody().getPosition().x + ent2->getBody().getSize().x / 2.f), (ent2->getBody().getPosition().y + ent2->getBody().getSize().y / 2));
	return ds;
}

void GerenciadorColisao::executar()
{
	/*
	Entidade* ent1, *ent2;
	sf::Vector2f ds;
	int i, j;
	for (i = 0; i < lPersonagens->LEs.getLen(); i++)
	{
		ent1 = lPersonagens->LEs.getItem(i);
		for (j = i + 1; j < lPersonagens->LEs.getLen(); j++)
		{
			ent2 = lPersonagens->LEs.getItem(j);
			ds = calcularColisao(ent1, ent2);
			if (ds.x < 0.0)
				ent1->getBody().move((ent1->getBody().getPosition().x() + ds.x), 0.f);
			else if (ds.y < 0.0)
				ent1->getBody().move(0.f, (ent1->getBody().getPosition().y + ds.y));
			
		}
	}
	for (i = 0; i < lPersonagens->LEs.getLen(); i++)
	{
		ent1 = lPersonagens->LEs.getItem(i);
		for (j = 0; j < lObstaculos->LEs.getLen(); j++)
		{
			ent2 = lObstaculos->LEs.getItem(j);
			ds = calcularColisao(ent1, ent2);

			if (ds.x < 0.0)
				ent1->getBody().move(ds.x, 0.f);
			else if (ds.y < 0.0)
				ent1->getBody().move(0.f, ent1->getBody().getPosition().y+ds.y);
			
		}
	}
	*/
}