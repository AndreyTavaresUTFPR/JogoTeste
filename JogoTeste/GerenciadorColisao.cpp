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

void GerenciadorColisao::repararColisao(Entidade* ent1, Entidade* ent2)
{
	sf::Vector2f centro1((ent1->getBody().getPosition().x + (ent1->getBody().getSize().x / 2)), (ent1->getBody().getPosition().y + (ent1->getBody().getSize().y / 2)));
	sf::Vector2f centro2((ent2->getBody().getPosition().x + (ent2->getBody().getSize().x / 2)), (ent2->getBody().getPosition().y + (ent2->getBody().getSize().y / 2)));

	sf::Vector2f ds(fabsf(centro1.x - centro2.x), fabsf(centro1.y - centro2.y));

	sf::Vector2f colisao(	((ent1->getBody().getSize().x / 2.f + ent2->getBody().getSize().x / 2.f) - ds.x),
							((ent1->getBody().getSize().y / 2.f + ent2->getBody().getSize().y / 2.f) - ds.y));	

	if (colisao.x > 0.f && colisao.y > 0.f)
	{
		// ent1->conferirColisao(colisao, ent2); #####   ESSA PARTE DEVERIA SER REALISADA PELOS OBJETOS ENTIDADE #####
		if (colisao.x > colisao.y)
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
			if (centro1.x < centro2.x) {
				ent1->getBody().setPosition((ent2->getBody().getPosition().x - ent1->getBody().getSize().x), ent1->getBody().getSize().y);
				ent1->direita = false;
				ent2->esquerda = false;
			}
			else {
				ent1->getBody().setPosition((ent2->getBody().getPosition().x + ent2->getBody().getSize().x), ent1->getBody().getSize().y);
				ent1->esquerda = false;
				ent2->direita = false;
			}
		}
	}
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
			ent1->esquerda = true;
			ent1->direita = true;
			ent2->esquerda = true;
			ent2->direita = true;
			repararColisao(ent1, ent2);
		}
	}
	for (i = 0; i < lPersonagens->LEs.getLen(); i++)
	{
		ent1 = lPersonagens->LEs.getItem(i);
		ent1->cair = true;
		for (j = 0; j < lObstaculos->LEs.getLen(); j++)
		{
			ent2 = lObstaculos->LEs.getItem(j);
			repararColisao(ent1, ent2);
		}
	}
	
}