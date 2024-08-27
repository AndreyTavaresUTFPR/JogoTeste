#include "Fase.h"

void Fase::inicializaElementos()
{

}

Fase::Fase(Lista<Jogador>* listaJog) :
	Ente(), listaJogadores(listaJog), listaInimigos(), listaObstaculos(), pColisao(pColisao->getGerenciadorColisao())
{

}

Fase::~Fase()
{
}

Lista<Jogador>* Fase::getListaJogadores()
{
	return listaJogadores;
}

Lista<Inimigo>* Fase::getListaInimigos()
{
	return &listaInimigos;
}

Lista<Obstaculo>* Fase::getListaObstaculos()
{
	return &listaObstaculos;
}

void Fase::executar()
{

}