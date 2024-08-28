#include "FaseUm.h"

FaseUm::FaseUm(Lista<Jogador>* listaJog) :
	Fase(listaJog)
{
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
	obst1 = new Teia();
	obst1->getBody()->setPosition(sf::Vector2f(400.f, 350.f));
	obst2 = new Teia();
	obst2->getBody()->setPosition(sf::Vector2f(200.f, 150.f));
	obst3 = new Espinhos();
	obst3->getBody()->setPosition(sf::Vector2f(400.f, 180.f));

	mago = new Chefe(j1, &listaProjetil);
	mago->getBody()->setPosition(sf::Vector2f(500.f, 500.f));

	inicializaElementos();
}

FaseUm::~FaseUm()
{

}

void FaseUm::inicializaElementos()
{
	listaInimigos.push(static_cast<Inimigo*>(e1));
	if (listaJogadores->getLen() == 2)
		listaInimigos.push(static_cast<Inimigo*>(e2));
	listaInimigos.push(static_cast<Inimigo*>(a1));
	listaInimigos.push(static_cast<Inimigo*>(mago));
	listaObstaculos.push(static_cast<Obstaculo*>(obst1));
	listaObstaculos.push(static_cast<Obstaculo*>(obst2));
	listaObstaculos.push(static_cast<Obstaculo*>(obst3));
	criarMapa();
}

void FaseUm::criarMapa()
{
	Solo* temp = new Solo();

	//Criando as paredes
	sf::Vector2f tam(25.f, 800.f);
	sf::Vector2f pos(0.f, -150.f);
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

void FaseUm::executar()
{
	pColisao->setListas(listaJogadores, &listaInimigos, &listaObstaculos);
	Entidade* temp = nullptr;
	int i = 0;
	while (pGrafico->verificarJanela())
	{
		sf::Event event;
		while (pGrafico->getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				{
					menuPausa.executar();
					if (menuPausa.getVoltarInicio())
						return;
				}
			if (event.type == sf::Event::Closed)
				pGrafico->fecharJanela();
		}

		pGrafico->limparJanela();
		for (i = 0; i < listaJogadores->getLen(); i++)
		{
			temp = static_cast<Entidade*>(listaJogadores->getItem(i));
			temp->executar();
			pGrafico->desenharElemento(*temp->getBody());
		}
		for (i = 0; i < listaInimigos.getLen(); i++)
		{
			temp = static_cast<Entidade*>(listaInimigos.getItem(i));
			temp->executar();
			pGrafico->desenharElemento(*temp->getBody());
		}
		for (i = 0; i < listaObstaculos.getLen(); i++)
		{
			temp = static_cast<Entidade*>(listaObstaculos.getItem(i));
			temp->executar();
			pGrafico->desenharElemento(*temp->getBody());
		}
		pColisao->executar();
		pGrafico->mostrarElementos();
	}
}