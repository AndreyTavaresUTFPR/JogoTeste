#include "FaseUm.h"

FaseUm::FaseUm(Lista<Jogador>* listaJog) :
	Fase(listaJog)
{
	setBody(sf::Vector2f(800.f, 800.f));
	atualizarTextura("../Imagens/Background1.1.png");
	for (int i = 0; i < listaJogadores->getLen(); i++)
	{
		Jogador* pJog = listaJogadores->getItem(i);
		pJog->getBody()->setPosition(sf::Vector2f(40.f, 40.f));
	}

	sf::FloatRect* aux = new sf::FloatRect(0.f, 0.f, 800.f, 800.f);
	salas.push_back(aux);
	aux = new sf::FloatRect(-800.f, 600.f, 800.f, 800.f);
	salas.push_back(aux);

	a1 = new Aranha();
	a1->getBody()->setPosition(sf::Vector2f(750.f, 345.f));

	obst3 = new Espinhos();
	obst3->getBody()->setPosition(sf::Vector2f(400.f, 180.f));

	obst4 = new Gelo();
	obst4->getBody()->setPosition(sf::Vector2f(150.f, 174.9f));

	//mago = new Chefe();
	//mago->getBody()->setPosition(sf::Vector2f(500.f, 500.f));

	inicializaElementos();
	//mago->setJogador(j1);
	//mago->setLProj(&listaProjetil);
}

FaseUm::~FaseUm()
{

}

void FaseUm::inicializaElementos()
{
	listaInimigos.push_back(static_cast<Inimigo*>(a1));
	criarMapa();
	criarInimigosFaceis();
	criarInimigosMedios();
	criarObstaculosFaceis();
	criarObstaculosMedios();
}

void FaseUm::criarInimigosFaceis()
{
	int n_inim = (rand() % 2 + 3); // Gera um número aleatório entre 3 e 4
	Esqueleto* aux = nullptr;
	
	aux = new Esqueleto(listaJogadores->getItem(0));
	aux->getBody()->setPosition(sf::Vector2f(300.f, 100.f));
	listaInimigos.push_back(static_cast<Inimigo*>(aux));

	vector<sf::Vector2f> posicoesPossiveis = { {200.f + (float)(rand() % 200), 300.f}, {200.f + (float)(rand() % 200), 500.f}, {200.f + (float)(rand() % 200), 675.f},
												{-600.f + (float)(rand() % 200), 675.f}, {-600.f + (float)(rand() % 200), 875.f}, {-600.f, 1075.f}, {-600.f + (float)(rand() % 200), 1150.f} };

	std::random_shuffle(posicoesPossiveis.begin(), posicoesPossiveis.end());
	vector<sf::Vector2f>::iterator it = posicoesPossiveis.begin();

	for(int i = 0; i < n_inim; i++)
	{
		aux = new Esqueleto(listaJogadores->getItem(0));
		aux->getBody()->setPosition(*it);
		listaInimigos.push_back(static_cast<Inimigo*>(aux));
		it++;
	}
}

void FaseUm::criarInimigosMedios()
{
	int n_inim = (rand() % 2 + 3); // Gera um número aleatório entre 3 e 4
	

	vector<sf::Vector2f> posicoesPossiveis = {	{200.f + (float)(rand()%200), 300.f}, {200.f + (float)(rand() % 200), 500.f}, {200.f + (float)(rand() % 200), 675.f},
												{-600.f + (float)(rand() % 200), 675.f}, {-600.f + (float)(rand() % 200), 875.f}, {-600.f, 1075.f}, {-600.f + (float)(rand() % 200), 1150.f} };

	std::random_shuffle(posicoesPossiveis.begin(), posicoesPossiveis.end());
	vector<sf::Vector2f>::iterator it = posicoesPossiveis.begin();

	for (int i = 0; i < n_inim; i++)
	{
		Aranha* aux = new Aranha();
		aux->getBody()->setPosition(*it);
		listaInimigos.push_back(static_cast<Inimigo*>(aux));
		it++;
	}
}

void FaseUm::criarObstaculosFaceis()
{
	int n_obst = (rand() % 2 + 3); // Gera um número aleatório entre 3 e 4
	Teia* aux = nullptr;

	vector<sf::Vector2f> posicoesPossiveis = {	{200.f + (float)(rand() % 400), 325.f}, {200.f + (float)(rand() % 400), 525.f}, {200.f + (float)(rand() % 400), 725.f},
												{-600.f + (float)(rand() % 400), 725.f}, {-600.f + (float)(rand() % 400), 925.f}, {-600.f + (float)(rand() % 400), 1125.f}, {-600.f + (float)(rand() % 300), 1325.f} };

	std::random_shuffle(posicoesPossiveis.begin(), posicoesPossiveis.end());

	vector<sf::Vector2f>::iterator it = posicoesPossiveis.begin();
	for(int i = 1; i < n_obst; i++)
	{
		aux = new Teia();
		aux->getBody()->setPosition(*it);
		listaObstaculos.push_back(static_cast<Obstaculo*>(aux));
		it++;

	}
}

void FaseUm::criarObstaculosMedios()
{
	int n_obst = (rand() % 2 + 3); // Gera um número aleatório entre 3 e 4
	Gelo* aux = nullptr;


	vector<sf::Vector2f> posicoesPossiveis = { {200.f + (float)(rand() % 400), 174.9f}, {200.f + (float)(rand() % 400), 374.9f}, {200.f + (float)(rand() % 400), 574.9f}, {200.f + (float)(rand() % 400), 774.9f},
												{-600.f + (float)(rand() % 400), 774.9f}, {-600.f + (float)(rand() % 400), 974.9f}, {-600.f + (float)(rand() % 400), 1174.9f}, {-600.f + (float)(rand() % 300), 1374.9f} };

	std::random_shuffle(posicoesPossiveis.begin(), posicoesPossiveis.end());

	vector<sf::Vector2f>::iterator it = posicoesPossiveis.begin();
	for (int i = 1; i < n_obst; i++)
	{
		aux = new Gelo();
		aux->getBody()->setPosition(*it);
		listaObstaculos.push_back(static_cast<Obstaculo*>(aux));
		it++;
	}
}

void FaseUm::criarTerreno1()
{
	Solo* temp = new Solo();

	//Criando as paredes
	sf::Vector2f tam(25.f, 600.f);
	sf::Vector2f pos(0.f, 25.f);
	temp->setBody(tam); //Parede lateal esquerda
	temp->getBody()->setPosition(pos);
	temp->atualizarTextura("../Imagens/Parede.png");
	listaObstaculos.push_back(static_cast<Obstaculo*>(temp));

	temp = new Solo();
	tam.y = 750.f;
	pos.x = 775.f;
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Parede.png");
	temp->getBody()->setPosition(pos); //Parede da lateral direita
	listaObstaculos.push_back(static_cast<Obstaculo*>(temp));

	/*********************************************************************************/

	//Criando teto e chão
	temp = new Solo();
	tam = sf::Vector2f(800.f, 25.f);
	pos = sf::Vector2f(0.f, 0.f);
	temp->setBody(tam);
	temp->getBody()->setPosition(pos); //Teto
	temp->atualizarTextura("../Imagens/Teto.png");
	listaObstaculos.push_back(static_cast<Obstaculo*>(temp));

	temp = new Solo();
	pos = sf::Vector2f(0.f, 775.f);
	temp->setBody(tam);
	temp->getBody()->setPosition(pos); //Chão
	temp->atualizarTextura("../Imagens/Teto.png");
	listaObstaculos.push_back(static_cast<Obstaculo*>(temp));

	/*********************************************************************************/


	//Criando andares
	for (int i = 0; i < 3; i++)
	{
		temp = new Solo();
		tam = sf::Vector2f(600.f, 50.f);
		pos = sf::Vector2f(25.f + 150.f * (i % 2), 200.f * (i + 1) - 25.f);
		temp->setBody(tam);
		temp->getBody()->setPosition(pos);
		temp->atualizarTextura("../Imagens/Andar.png");
		listaObstaculos.push_back(static_cast<Obstaculo*>(temp));
	}
}

void FaseUm::criarTerreno2()
{
	Solo* temp = new Solo();

	//Criando as paredes
	sf::Vector2f tam(25.f, 750.f);
	sf::Vector2f pos(-800.f, 625.f);
	temp->setBody(tam); //Parede lateal esquerda
	temp->getBody()->setPosition(pos);
	temp->atualizarTextura("../Imagens/Parede.png");
	listaObstaculos.push_back(static_cast<Obstaculo*>(temp));

	temp = new Solo();
	tam.y = 650.f;
	pos.x = -25.f;
	pos.y = 775.f;
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Parede.png");
	temp->getBody()->setPosition(pos); //Parede da lateral direita
	listaObstaculos.push_back(static_cast<Obstaculo*>(temp));

	/*********************************************************************************/

	//Criando teto e chão
	temp = new Solo();
	tam = sf::Vector2f(800.f, 25.f);
	pos = sf::Vector2f(-800.f, 600.f);
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Teto.png");
	temp->getBody()->setPosition(pos); //Teto
	listaObstaculos.push_back(static_cast<Obstaculo*>(temp));

	temp = new Solo();
	pos.y = 1375.f;
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Teto.png");
	temp->getBody()->setPosition(pos); //Chão
	listaObstaculos.push_back(static_cast<Obstaculo*>(temp));

	/*********************************************************************************/

	//Criando andares
	for (int i = 0; i < 3; i++)
	{
		temp = new Solo();
		tam = sf::Vector2f(600.f, 50.f);
		pos = sf::Vector2f(-775.f + 150.f * ((i+1) % 2), 200.f * (i + 1) + 575.f);
		temp->setBody(tam);
		temp->atualizarTextura("../Imagens/Andar.png");
		temp->getBody()->setPosition(pos);
		listaObstaculos.push_back(static_cast<Obstaculo*>(temp));
	}
}

void FaseUm::criarMapa()
{
	criarTerreno1();
	criarTerreno2();
	
}

void FaseUm::apagarMapa()
{

}

void FaseUm::atualizarFundo()
{
	if (sala_Atual == 1)
		atualizarTextura("../Imagens/Background1.2.png");
	else
		atualizarTextura("../Imagens/Background1.1.png");
}

bool FaseUm::verificarFim()
{
	sf::FloatRect saida(-150.f, 1275.f, 100.f, 100.f);
	for (int i = 0; i < listaJogadores->getLen(); i++)
	{
		if (saida.contains(listaJogadores->getItem(i)->getCentro()))
			return true;
	}
	return false;
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
					break;
				}
			if (event.type == sf::Event::Closed)
				pGrafico->fecharJanela();
		}
		bool mudouSala = false;
		pGrafico->limparJanela();
		pColisao->executar();
		desenhar();
		for (i = 0; i < listaJogadores->getLen(); i++)
		{
			pPers = static_cast<Personagem*>(listaJogadores->getItem(i));
			pPers->executar();
			pPers->desenhar();
		}
		for (itInim = listaInimigos.begin(); itInim != listaInimigos.end(); itInim++)
		{
			pPers = static_cast<Personagem*>(*itInim);
			if (pPers->getVivo())
			{
				pPers->executar();
				pPers->desenhar();
			}
		}
		for (itObst = listaObstaculos.begin(); itObst != listaObstaculos.end(); itObst++)
		{
			pObst = static_cast<Obstaculo*>(*itObst);
			pObst->executar();
			pObst->desenhar();
		}
		for (i = 0; i < salas.size(); i++)
		{
			if (salas[i]->contains(listaJogadores->getItem(0)->getCentro()) && sala_Atual != i)
			{
				mudouSala = true;
				sala_Atual = i;
				body.setPosition((salas[i]->getPosition()));
				if (listaJogadores->getLen() == 2)
					listaJogadores->getItem(1)->getBody()->setPosition(listaJogadores->getItem(0)->getBody()->getPosition());
			}
			else if (listaJogadores->getLen() == 2)
				if (salas[i]->contains(listaJogadores->getItem(1)->getCentro()) && sala_Atual != i)
				{
					mudouSala = true;
					sala_Atual = i;
					body.setPosition((salas[i]->getPosition()));
					listaJogadores->getItem(0)->getBody()->setPosition(listaJogadores->getItem(1)->getBody()->getPosition());
				}
		}
		if (mudouSala)
			atualizarFundo();
		pGrafico->getWindow()->setView(sf::View(*salas[sala_Atual]));
		pGrafico->mostrarElementos();
		if (verificarFim())
			return;
	}
}