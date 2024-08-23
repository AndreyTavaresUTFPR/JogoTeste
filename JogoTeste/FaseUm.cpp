#include "FaseUm.h"

FaseUm::FaseUm(Jogador* j1, Jogador* j2) :
	Fase(j1, j2)
{
	sf::Vector2f tam(50.f, 50.f);
	this->j1 = j1;
	this->j2 = j2;
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
	lPersonagens->LEs.push(static_cast<Entidade*>(j2));
	lPersonagens->LEs.push(static_cast<Entidade*>(e1));
	lPersonagens->LEs.push(static_cast<Entidade*>(a1));
	lObstaculos.push(static_cast<Obstaculo*>(solo1));
	lObstaculos.push(static_cast<Obstaculo*>(obst1));
}