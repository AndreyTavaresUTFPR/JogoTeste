#include "Fase.h"

Fase::Fase(Lista<Jogador>* listaJog) :
	Ente(), listaEntidades(), listaJogadores(listaJog), pColisao(pColisao->getGerenciadorColisao()), sala_Atual(0)
{
	for (int i = 0; i < listaJog->getLen(); i++)
	{
		Jogador* pJog = listaJog->getItem(i);
		listaEntidades.LEs.push(static_cast<Entidade*>(pJog));
	}

}

Fase::~Fase()
{
}

void Fase::incluirElementosColisao()
{
	for (int i = 0; i < listaEntidades.LEs.getLen(); i++)
	{
		Entidade* aux = listaEntidades.LEs.getItem(i);
		if (aux->getTipo() == 1)
			pColisao->incluirJogador(static_cast<Jogador*>(aux));
		else if (aux->getTipo() == 2)
			pColisao->incluirInimigo(static_cast<Inimigo*>(aux));
		else if (aux->getTipo() == 3)
			pColisao->incluirObstaculo(static_cast<Obstaculo*>(aux));
	}
}