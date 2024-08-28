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

vector<Inimigo*>* Fase::getListaInimigos()
{
	return &listaInimigos;
}

list<Obstaculo*>* Fase::getListaObstaculos()
{
	return &listaObstaculos;
}

void Fase::executar()
{

}