#include "FaseUm.h"

FaseUm::FaseUm(Jogador* j1) :
	Fase(j1)
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
	obst1 = new Teia();

	inicializaElementos();
}

FaseUm::~FaseUm()
{

}

void FaseUm::inicializaElementos()
{
	lPersonagens->LEs.push(static_cast<Entidade*>(j1));
	lPersonagens->LEs.push(static_cast<Entidade*>(e1));
	lPersonagens->LEs.push(static_cast<Entidade*>(a1));
	lObstaculos->LEs.push(static_cast<Entidade*>(solo1));
	lObstaculos->LEs.push(static_cast<Entidade*>(obst1));
}