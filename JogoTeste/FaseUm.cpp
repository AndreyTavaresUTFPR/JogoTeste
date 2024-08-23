#include "FaseUm.h"

FaseUm::FaseUm(Jogador* j1, Jogador* j2) :
	Fase(j1, j2)
{
	sf::Vector2f tamEsqueleto(30.f, 50.f);
	sf::Vector2f tamAranha(50.f, 50.f);
	this->j1 = j1;
	this->j2 = j2;
	e1 = new Esqueleto(j1);
	e1->setBody(tamEsqueleto);
	a1 = new Aranha();
	a1->setBody(tamAranha);
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
	listaObstaculos.push(static_cast<Obstaculo*>(obst1));
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
	temp->setBody(tam, pos); //Parede lateal esquerda
	listaObstaculos.push(static_cast<Obstaculo*>(temp));

	temp = new Solo();
	pos = sf::Vector2f(775.f, 0.f);
	temp->setBody(tam, pos);
	temp->getBody().setPosition(750.f, 0.f); //Parede da lateral direita
	listaObstaculos.push(static_cast<Obstaculo*>(temp));

	/*********************************************************************************/

	//Criando teto e chão
	temp = new Solo();
	tam = sf::Vector2f(800.f, 25.f);
	temp->setBody(tam, sf::Vector2f(0.f, 0.f));
	temp->getBody().setPosition(0.f, 0.f); //Teto
	listaObstaculos.push(static_cast<Obstaculo*>(temp));

	temp = new Solo();
	temp->setBody(tam, sf::Vector2f(0.f, 775.f));
	temp->getBody().setPosition(0.f, 750.f); //Chão
	listaObstaculos.push(static_cast<Obstaculo*>(temp));

	/*********************************************************************************/

	//Criando andares
	for (int i = 0; i < (int) 800.f / 200.f; i++)
	{
		temp = new Solo();
		tam = sf::Vector2f(600.f, 50.f);
		pos = sf::Vector2f(25.f + 150.f * (i % 2), 800.f / 4 * (i + 1));
		temp->setBody(tam, pos);
		listaObstaculos.push(static_cast<Obstaculo*>(temp));
	}
}