#include "Fase.h"

void Fase::inicializaElementos()
{
	lPersonagens->LEs.push(static_cast<Entidade*>(j1));
	lPersonagens->LEs.push(static_cast<Entidade*>(i1));
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
	i1 = new Inimigo(j1);
	i1->setBody(tam);
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
