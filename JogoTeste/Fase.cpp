#include "Fase.h"

void Fase::inicializaElementos()
{
	
}

Fase::Fase(Jogador* j1, Jogador* j2) :
	Ente(), listaJogadores(), listaInimigos(), listaObstaculos()
{
	this->j1 = nullptr;
	this->j2 = nullptr;
}

Fase::~Fase()
{
}

ListaJogadores* Fase::getListaJogadores()
{
	return &listaJogadores;
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
