#include "FaseUm.h"

FaseUm::FaseUm(Lista<Jogador>* listaJog) :
	Fase(listaJog)
{
	sf::Vector2f tamAranha(30.f, 30.f);
	this->j1 = listaJogadores->getItem(0);
	e1 = new Esqueleto(j1);
	e1->getBody()->setPosition(sf::Vector2f(200.f, 345.f));
	if (listaJogadores->getLen() == 2)
	{
		this->j2 = listaJogadores->getItem(1);
		e2 = new Esqueleto(j2);
		e2->getBody()->setPosition(sf::Vector2f(750.f, 100.f));
	}
	a1 = new Aranha();
	a1->setBody(tamAranha);
	obst1 = new Teia();
	obst1->getBody()->setPosition(sf::Vector2f(400.f, 350.f));
	obst2 = new Teia();
	obst2->getBody()->setPosition(sf::Vector2f(200.f, 150.f));
	obst3 = new Espinhos();
	obst3->getBody()->setPosition(sf::Vector2f(400.f, 180.f));

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
	if (listaJogadores->getLen() == 2)
		listaInimigos.push(static_cast<Inimigo*>(e2));
	listaInimigos.push(static_cast<Inimigo*>(a1));
	listaObstaculos.push(static_cast<Obstaculo*>(obst1));
	listaObstaculos.push(static_cast<Obstaculo*>(obst2));
	listaObstaculos.push(static_cast<Obstaculo*>(obst3));
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

	//Criando teto e ch�o
	temp = new Solo();
	tam = sf::Vector2f(800.f, 25.f);
	pos = sf::Vector2f(0.f, 0.f);
	temp->setBody(tam);
	temp->getBody()->setPosition(pos); //Teto
	listaObstaculos.push(static_cast<Obstaculo*>(temp));

	temp = new Solo();
	pos = sf::Vector2f(0.f, 775.f);
	temp->setBody(tam);
	temp->getBody()->setPosition(pos); //Ch�o
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