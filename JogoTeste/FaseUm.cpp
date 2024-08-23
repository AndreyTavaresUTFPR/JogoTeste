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
	listaJogadores.push(j1);
	listaJogadores.push(j2);
	listaInimigos.push(static_cast<Inimigo*>(e1));
	listaInimigos.push(static_cast<Inimigo*>(a1));
	listaObstaculos.push(static_cast<Obstaculo*>(solo1));
	listaObstaculos.push(static_cast<Obstaculo*>(obst1));
}

void FaseUm::executar()
{

}