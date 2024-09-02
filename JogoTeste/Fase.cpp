#include "Fase.h"

Fase::Fase() :
	Ente(), listaEntidades(), listaJogadores(nullptr), pColisao(pColisao->getGerenciadorColisao()), sala_Atual(0)
{
}

Fase::Fase(Lista<Jogador>* listaJog) :
	Ente(), listaEntidades(), listaJogadores(listaJog), pColisao(pColisao->getGerenciadorColisao()), sala_Atual(0)
{
	for (int i = 0; i < listaJogadores->getLen(); i++)
	{
		Jogador* pJog = listaJogadores->getItem(i);
		listaEntidades.LEs.push(static_cast<Entidade*>(pJog));
	}
}

Fase::~Fase()
{
}

//Verifica se algum dos jogadores morreu
bool Fase::verificaGameOver()
{
	int nJog = 0; //Contador de jogadores vivos
	for (int i = 0; i < listaJogadores->getLen(); i++)
		if (listaJogadores->getItem(i)->getNoJogo())
			nJog++;
	return (nJog < listaJogadores->getLen()); //Retorna true se ao menos um dos jogadores morreu
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