#include "Fase.h"

void Fase::inicializaElementos()
{
	lPersonagens->LEs.push(static_cast<Entidade*>(j1));
	lPersonagens->LEs.push(static_cast<Entidade*>(e1));
	lPersonagens->LEs.push(static_cast<Entidade*>(a1));
	lObstaculos->LEs.push(static_cast<Entidade*>(solo1));
	lObstaculos->LEs.push(static_cast<Entidade*>(obst1));
}

Fase::Fase(Jogador* j1)
{
	sf::Vector2f tam(50.f, 50.f);
	lPersonagens = new ListaEntidades();
	lObstaculos = new ListaEntidades();
	this->j1 = j1;
	e1 = new Esqueleto(j1);
	e1->setBody(tam);
	a1 = new Aranha();
	a1->setBody(tam);
	solo1 = new Solo();
	obst1 = new Obstaculodiferente();

	inicializaElementos();
}

Fase::~Fase()
{
}


ListaEntidades* Fase::getListaPersonagens() { return lPersonagens; }

ListaEntidades* Fase::getListaObstaculos() { return lObstaculos; }
