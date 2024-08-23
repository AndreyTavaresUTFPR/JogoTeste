#include "GerenciadorColisao.h"

GerenciadorColisao::GerenciadorColisao() :
	listaJogadores(nullptr), listaInimigos(nullptr), listaObstaculos(nullptr)
{
	
}

GerenciadorColisao::~GerenciadorColisao()
{

}

void GerenciadorColisao::setListas(Lista<Jogador>* listaJog, Lista<Inimigo>* listaInim, Lista<Obstaculo>* listaObst)
{
	listaJogadores = listaJog;
	listaInimigos = listaInim;
	listaObstaculos = listaObst;
}

void GerenciadorColisao::repararColisao(Entidade* ent1, Entidade* ent2) //Confere se houve colisão entre as Entidades, caso o if seja true, corrige as posições das entidades e seus movimentos.
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
	Jogador* pJog = nullptr;
	Inimigo* pInim1 = nullptr;
	Inimigo* pInim2 = nullptr;
	Obstaculo* pObst = nullptr;

	Entidade* ent1 = nullptr;
	Entidade* ent2 = nullptr;

	int i = 0, j = 0;

	for (i = 0; i < listaJogadores->getLen(); i++)
	{
		pJog = listaJogadores->getItem(i);
		pJog->liberarGravidade();
		pJog->liberarMovimento();
	}

	for (i = 0; i < listaInimigos->getLen(); i++)
	{
		pInim1 = listaInimigos->getItem(i);
		pInim1->liberarGravidade();
		pInim1->liberarMovimento();
	}

	for (i = 0; i < listaJogadores->getLen(); i++)
	{
		ent1 = static_cast<Entidade*>(listaJogadores->getItem(i));
		for (j = 0; j < listaInimigos->getLen(); j++)
		{
			ent2 = static_cast<Entidade*>(listaInimigos->getItem(j));
			repararColisao(ent1, ent2);
		}
		for (j = 0; j < listaObstaculos->getLen(); j++)
		{
			ent2 = static_cast<Entidade*>(listaObstaculos->getItem(j));
			repararColisao(ent1, ent2);
		}
	}

	for (i = 0; i < listaInimigos->getLen(); i++)
	{
		ent1 = static_cast<Entidade*>(listaInimigos->getItem(i));
		for (j = i + 1; j < listaInimigos->getLen(); j++)
		{
			ent2 = static_cast<Entidade*>(listaInimigos->getItem(j));
			repararColisao(ent1, ent2);
		}
		for (j = 0; j < listaObstaculos->getLen(); j++)
		{
			ent2 = static_cast<Entidade*>(listaObstaculos->getItem(j));
			repararColisao(ent1, ent2);
		}
	}
}