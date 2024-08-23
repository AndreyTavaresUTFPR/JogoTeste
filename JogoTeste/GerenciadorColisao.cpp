#include "GerenciadorColisao.h"

GerenciadorColisao::GerenciadorColisao() :
	lPersonagens(nullptr), lObstaculos(nullptr)
{
	
}

GerenciadorColisao::~GerenciadorColisao()
{

}

void GerenciadorColisao::setListas(ListaEntidades* listaPers, Lista<Obstaculo>* listaObst)
{
	lPersonagens = listaPers;
	lObstaculos = listaObst;
}

void GerenciadorColisao::repararColisao(Entidade* ent1, Entidade* ent2) //Confere se houve colis�o entre as Entidades, caso o if seja true, corrige as posi��es das entidades e seus movimentos.
{
	sf::Vector2f ds(fabsf(ent1->getCentro().x - ent2->getCentro().x), fabsf(ent1->getCentro().y - ent2->getCentro().y));

	sf::Vector2f colisao(	((ent1->getBody().getSize().x / 2.f + ent2->getBody().getSize().x / 2.f) - ds.x),
							((ent1->getBody().getSize().y / 2.f + ent2->getBody().getSize().y / 2.f) - ds.y));

	if (colisao.x > 0.f && colisao.y > 0.f)
	{
		ent1->conferirColisao(colisao, ent2->getCentro());
		ent2->conferirColisao(colisao, ent1->getCentro());
	}
}

void GerenciadorColisao::executar()
{
	Entidade* ent1 = nullptr, *ent2 = nullptr;
	int i = 0, j = 0;

	for (i = 0; i < lPersonagens->LEs.getLen(); i++)
	{
		ent1 = lPersonagens->LEs.getItem(i);
		ent1->liberarGravidade();
		ent1->liberarMovimento();
	}

	for (i = 0; i < lPersonagens->LEs.getLen(); i++)
	{
		ent1 = lPersonagens->LEs.getItem(i);
		for (j = i + 1; j < lPersonagens->LEs.getLen(); j++)
		{
			ent2 = lPersonagens->LEs.getItem(j);
			repararColisao(ent1, ent2);
		}
		for (j = 0; j < lObstaculos->getLen(); j++)
		{
			ent2 = static_cast<Entidade*>(lObstaculos->getItem(j));
			repararColisao(ent1, ent2);
		}
	}
}