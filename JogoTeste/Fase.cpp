#include "Fase.h"

void Fase::inicializaElementos()
{
	
}

Fase::Fase(Jogador* j1, Jogador* j2) :
	Ente(), lPersonagens(nullptr), lObstaculos()
{
	lPersonagens = new ListaEntidades();
}

Fase::~Fase()
{
}


ListaEntidades* Fase::getListaPersonagens() 
{ 
	return lPersonagens; 
}

Lista<Obstaculo>* Fase::getListaObstaculos()
{ 
	return &lObstaculos; 
}

void Fase::executar()
{

}
