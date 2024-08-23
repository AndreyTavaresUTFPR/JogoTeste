#include "FaseUm.h"

FaseUm::FaseUm(Jogador* j1, Jogador* j2) :
	Fase(j1, j2)
{
	sf::Vector2f tamEsqueleto(30.f, 60.f);
	sf::Vector2f tamAranha(30.f, 30.f);
	this->j1 = j1;
	this->j2 = j2;
	e1 = new Esqueleto(j1);
	e1->setBody(tamEsqueleto);
	e1->getBody()->setPosition(sf::Vector2f(200.f, 345.f));
	e2 = new Esqueleto(j2);
	e2->setBody(tamEsqueleto);
	e2->getBody()->setPosition(sf::Vector2f(750.f, 100.f));
	a1 = new Aranha();
	a1->setBody(tamAranha);
	obst1 = new Teia();
	obst1->getBody()->setPosition(sf::Vector2f(400.f, 350.f));
	obst2 = new Teia();
	obst2->getBody()->setPosition(sf::Vector2f(200.f, 150.f));
	

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
	listaInimigos.push(static_cast<Inimigo*>(e2));
	listaInimigos.push(static_cast<Inimigo*>(a1));
	listaObstaculos.push(static_cast<Obstaculo*>(obst1));
	listaObstaculos.push(static_cast<Obstaculo*>(obst2));
	criarMapa();
}

void FaseUm::executar()
{

}

void FaseUm::criarMapa()
{
	Solo* temp = new Solo();

	//Criando as paredes
	sf::Vector2f tam(25.f, 800.f);
	sf::Vector2f pos(0.f, 0.f);
	temp->setBody(tam); //Parede lateal esquerda
	temp->getBody()->setPosition(pos);
	listaObstaculos.push(static_cast<Obstaculo*>(temp));

	temp = new Solo();
	pos = sf::Vector2f(775.f, 0.f);
	temp->setBody(tam);
	temp->getBody()->setPosition(pos); //Parede da lateral direita
	listaObstaculos.push(static_cast<Obstaculo*>(temp));

	/*********************************************************************************/

	//Criando teto e chão
	temp = new Solo();
	tam = sf::Vector2f(800.f, 25.f);
	pos = sf::Vector2f(0.f, 0.f);
	temp->setBody(tam);
	temp->getBody()->setPosition(pos); //Teto
	listaObstaculos.push(static_cast<Obstaculo*>(temp));

	temp = new Solo();
	pos = sf::Vector2f(0.f, 775.f);
	temp->setBody(tam);
	temp->getBody()->setPosition(pos); //Chão
	listaObstaculos.push(static_cast<Obstaculo*>(temp));

	/*********************************************************************************/

	//Criando andares
	for (int i = 0; i < 3; i++)
	{
		temp = new Solo();
		tam = sf::Vector2f(600.f, 50.f);
		pos = sf::Vector2f(25.f + 150.f * (i % 2), 800.f / 4 * (i + 1));
		temp->setBody(tam);
		temp->getBody()->setPosition(pos);
		listaObstaculos.push(static_cast<Obstaculo*>(temp));
	}
}