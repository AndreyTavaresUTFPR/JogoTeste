#include "Fase.h"

void Fase::inicializaElementos()
{
	
}

Fase::Fase(Jogador* j1) :
	Ente()
{
	
}

Fase::~Fase()
{
}


ListaEntidades* Fase::getListaPersonagens() 
{ 
	return lPersonagens; 
}

ListaEntidades* Fase::getListaObstaculos() 
{ 
	return lObstaculos; 
}

void Fase::executar()
{

}
