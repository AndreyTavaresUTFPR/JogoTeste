#include "Fase.h"

void Fase::inicializaElementos()
{
	lPersonagens->LEs.push(static_cast<Entidade*>(j1));
	lPersonagens->LEs.push(static_cast<Entidade*>(e1));
	lPersonagens->LEs.push(static_cast<Entidade*>(a1));
	lObstaculos->LEs.push(static_cast<Entidade*>(os1));
	lObstaculos->LEs.push(static_cast<Entidade*>(os2));
}

Fase::Fase(Jogador* j1, sf::RenderWindow* window)
{
	sf::Vector2f tam(50.f, 50.f);
	this->window = window;
	lPersonagens = new ListaEntidades();
	lObstaculos = new ListaEntidades();
	this->j1 = j1;
	e1 = new Esqueleto(j1);
	e1->setBody(tam);
	a1 = new Aranha();
	a1->setBody(tam);
	os1 = new Obstaculosimples();
	os2 = new Obstaculodiferente();

	//i1->setWindow(window);

	inicializaElementos();
}

Fase::~Fase()
{
}


ListaEntidades* Fase::getListaPersonagens() { return lPersonagens; }

ListaEntidades* Fase::getListaObstaculos() { return lObstaculos; }
