#include "Fase.h"

void Fase::inicializaElementos()
{
	listaEntidades->LEs.push(j1);
	listaEntidades->LEs.push(i1);
}

Fase::Fase(Jogador* j1, sf::RenderWindow* window)
{
	this->window = window;
	listaEntidades = new ListaEntidades();
	this->j1 = j1;
	i1 = new Inimigo(j1);
	i1->setWindow(window);

	inicializaElementos();
}

Fase::~Fase()
{
}


ListaEntidades* Fase::getListaEntidades() { return listaEntidades; }
