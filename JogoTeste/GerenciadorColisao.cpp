#include "GerenciadorColisao.h"

GerenciadorColisao* GerenciadorColisao::pColisao(nullptr);

GerenciadorColisao::GerenciadorColisao() :
	listaJogadores(nullptr), listaInimigos(nullptr), listaObstaculos(nullptr)
{
	
}

GerenciadorColisao::~GerenciadorColisao()
{

}

GerenciadorColisao* GerenciadorColisao::getGerenciadorColisao()
{
	if (pColisao == nullptr)
		pColisao = new GerenciadorColisao();
	return pColisao;
}

void GerenciadorColisao::setListas(Lista<Jogador>* listaJog, Lista<Inimigo>* listaInim, Lista<Obstaculo>* listaObst)
{
	listaJogadores = listaJog;
	listaInimigos = listaInim;
	listaObstaculos = listaObst;
}

//Confere Colisão entre Jogador e Inimigo
void GerenciadorColisao::conferirColisaoJogInim(Jogador* pJog, Inimigo* pInim)
{
	sf::Vector2f ds(fabsf(pJog->getCentro().x - pInim->getCentro().x), fabsf(pJog->getCentro().y - pInim->getCentro().y));

	sf::Vector2f colisao(	((pJog->getBody()->getSize().x / 2.f + pInim->getBody()->getSize().x / 2.f) - ds.x),
							((pJog->getBody()->getSize().y / 2.f + pInim->getBody()->getSize().y / 2.f) - ds.y));

	if (colisao.x > 0.f && colisao.y > 0.f)
	{
		pJog->conferirColisao(colisao, pInim->getCentro());
		pInim->conferirColisao(colisao, pJog->getCentro());
	}
}

//Confere Colisão entre Jogador e Obstaculo
void GerenciadorColisao::conferirColisaoJogObst(Jogador* pJog, Obstaculo* pObst)
{
	sf::Vector2f ds(fabsf(pJog->getCentro().x - pObst->getCentro().x), fabsf(pJog->getCentro().y - pObst->getCentro().y));

	sf::Vector2f colisao(	((pJog->getBody()->getSize().x / 2.f + pObst->getBody()->getSize().x / 2.f) - ds.x),
							((pJog->getBody()->getSize().y / 2.f + pObst->getBody()->getSize().y / 2.f) - ds.y));

	if (colisao.x > 0.f && colisao.y > 0.f)
	{
		if (pObst->ehSolido())
			pJog->conferirColisao(colisao, pObst->getCentro());
		pObst->afetarPersonagem(pJog);
	}
}

//Confere Colisão entre Inimigos
void GerenciadorColisao::conferirColisaoInimInim(Inimigo* pInim1, Inimigo* pInim2)
{
	sf::Vector2f ds(fabsf(pInim1->getCentro().x - pInim2->getCentro().x), fabsf(pInim1->getCentro().y - pInim2->getCentro().y));

	sf::Vector2f colisao(	((pInim1->getBody()->getSize().x / 2.f + pInim2->getBody()->getSize().x / 2.f) - ds.x),
							((pInim1->getBody()->getSize().y / 2.f + pInim2->getBody()->getSize().y / 2.f) - ds.y));

	if (colisao.x > 0.f && colisao.y > 0.f)
	{
		pInim1->conferirColisao(colisao, pInim2->getCentro());
		pInim2->conferirColisao(colisao, pInim1->getCentro());
	}
}

//Confere Colisão entre Inimigo e Obstaculo
void GerenciadorColisao::conferirColisaoInimObst(Inimigo* pInim, Obstaculo* pObst)
{
	sf::Vector2f ds(fabsf(pInim->getCentro().x - pObst->getCentro().x), fabsf(pInim->getCentro().y - pObst->getCentro().y));

	sf::Vector2f colisao(	((pInim->getBody()->getSize().x / 2.f + pObst->getBody()->getSize().x / 2.f) - ds.x),
							((pInim->getBody()->getSize().y / 2.f + pObst->getBody()->getSize().y / 2.f) - ds.y));

	if (pObst->ehSolido())
		if (colisao.x > 0.f && colisao.y > 0.f)
			pInim->conferirColisao(colisao, pObst->getCentro());
	pObst->afetarPersonagem(pInim);
}


void GerenciadorColisao::executar()
{
	Jogador* pJog = nullptr;
	Inimigo* pInim1 = nullptr;
	Inimigo* pInim2 = nullptr;
	Obstaculo* pObst = nullptr;

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
		pJog = listaJogadores->getItem(i);
		for (j = 0; j < listaInimigos->getLen(); j++)
		{
			pInim1 = listaInimigos->getItem(j);
			conferirColisaoJogInim(pJog, pInim1);
		}
		for (j = 0; j < listaObstaculos->getLen(); j++)
		{
			pObst = listaObstaculos->getItem(j);
			conferirColisaoJogObst(pJog, pObst);
		}
	}

	for (i = 0; i < listaInimigos->getLen(); i++)
	{
		pInim1 = listaInimigos->getItem(i);
		for (j = i + 1; j < listaInimigos->getLen(); j++)
		{
			pInim2 = listaInimigos->getItem(j);
			conferirColisaoInimInim(pInim1, pInim2);
		}
		for (j = 0; j < listaObstaculos->getLen(); j++)
		{
			pObst = listaObstaculos->getItem(j);
			conferirColisaoInimObst(pInim1, pObst);

		}
	}
}