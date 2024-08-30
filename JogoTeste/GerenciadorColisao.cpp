#include "GerenciadorColisao.h"

GerenciadorColisao* GerenciadorColisao::pColisao(nullptr);

GerenciadorColisao::GerenciadorColisao() :
	listaJogadores(nullptr), listaInimigos(), listaObstaculos()
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

void GerenciadorColisao::setListas(Lista<Jogador>* listaJog, vector<Inimigo*>* listaInim, list<Obstaculo*>* listaObst)
{
	listaJogadores = listaJog;
	listaInimigos = listaInim;
	listaObstaculos = listaObst;
}

//Confere Colisão entre Jogador e Inimigo
void GerenciadorColisao::conferirColisaoJogInim(Jogador* pJog, Inimigo* pInim)
{
	sf::Vector2f ds(fabsf(pJog->getCentro().x - pInim->getCentro().x), fabsf(pJog->getCentro().y - pInim->getCentro().y));

	sf::Vector2f colisao(	((pJog->getBody()->getSize().x / 2.f + pInim->getBody()->getSize().x / 2.f) - ds.x + 0.2f),
							((pJog->getBody()->getSize().y / 2.f + pInim->getBody()->getSize().y / 2.f) - ds.y + 0.2f));

	if (colisao.x > 0.f && colisao.y > 0.f)
	{
		if (colisao.x > colisao.y && pJog->getCentro().y < pInim->getCentro().y)
		{
			pInim->operator--();
		}
		else
			pInim->danificar(pJog);
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
		pObst->obstacular(pJog);
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

	if (colisao.x > 0.f && colisao.y > 0.f)
	{
		if (pObst->ehSolido())
			pInim->conferirColisao(colisao, pObst->getCentro());
		pObst->obstacular(pInim);
	}
}


void GerenciadorColisao::executar()
{
	Jogador* pJog = nullptr;
	Inimigo* pInim1 = nullptr;
	Inimigo* pInim2 = nullptr;
	Obstaculo* pObst = nullptr;
	vector<Inimigo*>::iterator itInim;
	vector<Inimigo*>::iterator itInim2;
	list<Obstaculo*>::iterator itObst;

	int i = 0;

	for (i = 0; i < listaJogadores->getLen(); i++)
	{
		pJog = listaJogadores->getItem(i);
		for (itInim = listaInimigos->begin(); itInim != listaInimigos->end(); itInim++)
		{
			pInim1 = (*itInim);
			if (pInim1->getVivo())
			conferirColisaoJogInim(pJog, pInim1);
		}
		for (itObst = listaObstaculos->begin(); itObst != listaObstaculos->end(); itObst++)
		{
			pObst = (*itObst);
			conferirColisaoJogObst(pJog, pObst);
		}
	}

	for (itInim = listaInimigos->begin(); itInim != listaInimigos->end(); itInim++)
	{
		pInim1 = (*itInim);
		if (pInim1->getVivo()) {
			for (itInim2 = listaInimigos->begin(); itInim2 != listaInimigos->end(); itInim2++)
			{
				pInim2 = (*itInim2);
				if (pInim2->getVivo())
					if (pInim1 != pInim2)
						conferirColisaoInimInim(pInim1, pInim2);
			}
			for (itObst = listaObstaculos->begin(); itObst != listaObstaculos->end(); itObst++)
			{
				pObst = (*itObst);
				conferirColisaoInimObst(pInim1, pObst);

			}
		}
	}
}