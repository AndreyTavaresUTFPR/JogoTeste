#include "FaseUm.h"

FaseUm::FaseUm(Lista<Jogador>* listaJog) :
	Fase(listaJog)
{
	if (!textura.loadFromFile("../Imagens/Background.png"))
		cout << "Erro ao carregar Background" << endl;
	setBody(sf::Vector2f(800.f, 800.f));
	body.setTexture(&textura);

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

	mago = new Chefe();
	mago->getBody()->setPosition(sf::Vector2f(500.f, 500.f));

	inicializaElementos();
	mago->setJogador(j1);
	mago->setLProj(&listaProjetil);
}

FaseUm::~FaseUm()
{

}

void FaseUm::inicializaElementos()
{
	listaInimigos.push_back(static_cast<Inimigo*>(e1));
	if (listaJogadores->getLen() == 2)
		listaInimigos.push_back(static_cast<Inimigo*>(e2));
	listaInimigos.push_back(static_cast<Inimigo*>(a1));
	listaInimigos.push_back(static_cast<Inimigo*>(mago));
	listaObstaculos.push_back(static_cast<Obstaculo*>(obst1));
	listaObstaculos.push_back(static_cast<Obstaculo*>(obst2));
	listaObstaculos.push_back(static_cast<Obstaculo*>(obst3));
	criarMapa();
}

void FaseUm::criarMapa()
{
	Solo* temp = new Solo();

	//Criando as paredes
	sf::Vector2f tam(25.f, 800.f);
	sf::Vector2f pos(0.f, -150.f);
	sf::Texture texturaParede;
	texturaParede.loadFromFile("../Imagens/Parede.png");
	temp->setBody(tam); //Parede lateal esquerda
	temp->getBody()->setPosition(pos);
	temp->atualizarTextura(texturaParede);
	listaObstaculos.push_back(static_cast<Obstaculo*>(temp));

	temp = new Solo();
	pos = sf::Vector2f(775.f, 0.f);
	temp->setBody(tam);
	temp->atualizarTextura(texturaParede);
	temp->getBody()->setPosition(pos); //Parede da lateral direita
	listaObstaculos.push_back(static_cast<Obstaculo*>(temp));

	/*********************************************************************************/

	//Criando teto e chão
	temp = new Solo();
	tam = sf::Vector2f(800.f, 25.f);
	pos = sf::Vector2f(0.f, 0.f);
	temp->setBody(tam);
	temp->getBody()->setPosition(pos); //Teto
	listaObstaculos.push_back(static_cast<Obstaculo*>(temp));

	temp = new Solo();
	pos = sf::Vector2f(0.f, 775.f);
	temp->setBody(tam);
	temp->getBody()->setPosition(pos); //Chão
	listaObstaculos.push_back(static_cast<Obstaculo*>(temp));

	/*********************************************************************************/

	//Criando andares
	for (int i = 0; i < 3; i++)
	{
		temp = new Solo();
		tam = sf::Vector2f(600.f, 50.f);
		pos = sf::Vector2f(25.f + 150.f * (i % 2), 800.f / 4 * (i + 1));
		temp->setBody(tam);
		temp->getBody()->setPosition(pos);
		listaObstaculos.push_back(static_cast<Obstaculo*>(temp));
	}
}

void FaseUm::criarInimigosFaceis()
{
	int n_inim = (rand() % 2 + 3); // Gera um número aleatório entre 3 e 4
	
	
}

void FaseUm::criarInimigosMedios()
{
	int n_inim = (rand() % 2 + 3); // Gera um número aleatório entre 3 e 4
	
	for (int i = 0; i < n_inim; i++)
	{
		Aranha* aux = new Aranha();
	}
}

void FaseUm::criarObstaculosFaceis()
{
	int n_obst = (rand() % 2 + 3); // Gera um número aleatório entre 3 e 4
}

void FaseUm::criarObstaculosMedios()
{
	int n_obst = (rand() % 2 + 3); // Gera um número aleatório entre 3 e 4
}

void FaseUm::executar()
{
	pColisao->setListas(listaJogadores, &listaInimigos, &listaObstaculos);
	Personagem* pPers = nullptr;
	Obstaculo* pObst = nullptr;
	vector<Inimigo*>::iterator itInim;
	list<Obstaculo*>::iterator itObst;



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
		pGrafico->desenharElemento(body);
		for (i = 0; i < listaJogadores->getLen(); i++)
		{
			pPers = static_cast<Personagem*>(listaJogadores->getItem(i));
			pPers->executar();
			pGrafico->desenharElemento(*pPers->getBody());
		}
		for (itInim = listaInimigos.begin(); itInim != listaInimigos.end(); itInim++)
		{
			pPers = static_cast<Personagem*>(*itInim);
			if (pPers->getVivo())
			{
				pPers->executar();
				pGrafico->desenharElemento(*pPers->getBody());
			}
		}
		for (itObst = listaObstaculos.begin(); itObst != listaObstaculos.end(); itObst++)
		{
			pObst = static_cast<Obstaculo*>(*itObst);
			pObst->executar();
			pGrafico->desenharElemento(*pObst->getBody());
		}
		pColisao->executar();
		pGrafico->mostrarElementos();
	}
}