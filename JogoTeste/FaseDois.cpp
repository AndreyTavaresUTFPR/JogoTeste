#include "FaseDois.h"

FaseDois::FaseDois() :
	Fase()
{
}

FaseDois::FaseDois(Lista<Jogador>* listaJog) :
	Fase(listaJog)
{
	setBody(sf::Vector2f(800.f, 800.f));
	atualizarTextura("../Imagens/Background2.1.png");
	menuPausa.atualizarTextura("../Imagens/Background2.1.png");

	sf::FloatRect* aux = new sf::FloatRect(0.f, 0.f, 800.f, 800.f);
	salas.push_back(aux);
	aux = new sf::FloatRect(800.f, 0.f, 800.f, 800.f);
	salas.push_back(aux);

	n_esqueletos = rand() % 2 + 3;
	n_aranhas = rand() % 2 + 3;
	n_gelos = rand() % 2 + 3;
	n_espinhos = rand() % 2 + 3;

	criarFase();
}

FaseDois::~FaseDois()
{
	apagarFase();
	listaJogadores = nullptr;
	pColisao->limparListas();
}

//Cria Esqueleto na fase e distribui de forma aleatoria
void FaseDois::criarInimigosFaceis()
{
	vector<sf::Vector2f> posicoesPossiveis = { {200.f, 125.f}, {50.f + (float)(rand() % 200), 325.f }, {200.f + (float)(rand() % 500), 525.f}, {50.f + (float)(rand() % 600), 725.f},
												{800.f + (float)(rand() % 100), 725.f}, {800 + (float)(rand() % 700), 125.f} };

	std::random_shuffle(posicoesPossiveis.begin(), posicoesPossiveis.end());
	vector<sf::Vector2f>::iterator it = posicoesPossiveis.begin();

	for (int i = 0; i < n_esqueletos; i++)
	{
		Esqueleto* aux = nullptr;
		aux = new Esqueleto(listaJogadores);
		if (aux != nullptr)
		{
			aux->getBody()->setPosition(*it);
			listaEntidades.LEs.push(static_cast<Entidade*>(aux));
			it++;
		}
	}
}

//Cria Aranhha na fase e distribui de forma aleatoria
void FaseDois::criarInimigosMedios()
{
	vector<sf::Vector2f> posicoesPossiveis = { {200.f, 125.f}, {50.f + (float)(rand() % 200), 325.f }, {200.f + (float)(rand() % 500), 525.f}, {50.f + (float)(rand() % 600), 725.f},
												{800.f + (float)(rand() % 100), 725.f}, {800 + (float)(rand() % 700), 125.f},  {1150.f + (float)(rand() % 100), 325.f} };

	std::random_shuffle(posicoesPossiveis.begin(), posicoesPossiveis.end());
	vector<sf::Vector2f>::iterator it = posicoesPossiveis.begin();

	for (int i = 0; i < n_aranhas; i++)
	{
		Aranha* aux = nullptr;
		aux = new Aranha();
		if (aux != nullptr)
		{
			aux->getBody()->setPosition(*it);
			listaEntidades.LEs.push(static_cast<Entidade*>(aux));
			it++;
		}
	}
}

//Cria Gelo na fase e distribui de forma aleatoria
void FaseDois::criarObstaculosMedios()
{
	vector<sf::Vector2f> posicoesPossiveis = {	{200.f, 174.9f}, {50.f + (float)(rand() % 200), 374.9f }, {200.f + (float)(rand() % 500), 574.9f}, {50.f + (float)(rand() % 600), 774.9f},
												{800.f + (float)(rand() % 100), 774.9f}, {800 + (float)(rand() % 300), 174.9f}, {1325.f + (float)(rand() % 150), 574.9f}};

	std::random_shuffle(posicoesPossiveis.begin(), posicoesPossiveis.end());

	vector<sf::Vector2f>::iterator it = posicoesPossiveis.begin();
	for (int i = 0; i < n_gelos; i++)
	{
		Gelo* aux = nullptr;
		aux = new Gelo();
		if (aux != nullptr)
		{
			aux->getBody()->setPosition(*it);
			listaEntidades.LEs.push(static_cast<Entidade*>(aux));
			it++;
		}
	}
}

//Cria Espinhos na fase e distribui de forma aleatoria
void FaseDois::criarObstaculosDificeis()
{
	vector<sf::Vector2f> posicoesPossiveis = {	{200.f, 155.f}, {50.f + (float)(rand() % 200), 355.f }, {200.f + (float)(rand() % 500), 555.f}, {50.f + (float)(rand() % 600), 755.f},
												{800.f + (float)(rand() % 100), 755.f}, {800 + (float)(rand() % 300), 155.f} };

	Espinhos* aux = new Espinhos();
	if (aux != nullptr)
	{
		aux->getBody()->setPosition(sf::Vector2f(1275.f, 355.f));
		listaEntidades.LEs.push(static_cast<Entidade*>(aux));
	}

	std::random_shuffle(posicoesPossiveis.begin(), posicoesPossiveis.end());

	vector<sf::Vector2f>::iterator it = posicoesPossiveis.begin();
	for (int i = 1; i < n_espinhos; i++)
	{
		aux = nullptr;
		aux = new Espinhos();
		if (aux != nullptr)
		{
			aux->getBody()->setPosition(*it);
			listaEntidades.LEs.push(static_cast<Entidade*>(aux));
			it++;
		}
	}
}

//Cria o terreno da fase
void FaseDois::criarTerreno()
{
	//Criando Terreno da Primeira Sala

	//Criando Paredes
	Solo* temp;
	sf::Vector2f tam(25.f, 750.f);
	sf::Vector2f pos(0.f, 25.f);

	for (int i = 0; i < 2; i++)
	{
		temp = new Solo("Parede2");
		pos.x = 1575.f * i;
		temp->setBody(tam);
		temp->getBody()->setPosition(pos);
		listaEntidades.LEs.push(static_cast<Entidade*>(temp));
	}
	
	tam.y = 200.f;
	for (int i = 0; i < 2; i++)
	{
		temp = new Solo("Parede2");
		pos.x = 775.f + (275.f * i);
		pos.y = 425.f - (200.f * i);
		temp->setBody(tam);
		temp->getBody()->setPosition(pos);
		listaEntidades.LEs.push(static_cast<Entidade*>(temp));
	}

	tam.y = 400.f;
	for(int i =0; i < 2; i++)
	{
		tam.y -= 50.f * i;
		temp = new Solo("Parede2");
		pos.x = 525. + (700 * i);
		pos.y = 25.f + (400.f * i);
		temp->setBody(tam);
		temp->getBody()->setPosition(pos);
		listaEntidades.LEs.push(static_cast<Entidade*>(temp));
	}

	/***********************************************************************************/
	//Criando teto e chão

	//Tetos
	tam = sf::Vector2f(800.f, 25.f);
	pos.y = 0.f;
	for (int i = 0; i < 2; i++)
	{
		temp = new Solo("Teto2");
		pos.x = 800.f * i;
		temp->setBody(tam);
		temp->getBody()->setPosition(pos);
		listaEntidades.LEs.push(static_cast<Entidade*>(temp));
	}
	
	//Chão
	pos = sf::Vector2f(0.f, 775.f);
	for (int i = 0; i < 2; i++)
	{
		temp = new Solo("Teto2");
		pos.x = 800.f * i;
		temp->setBody(tam);
		temp->getBody()->setPosition(pos);
		listaEntidades.LEs.push(static_cast<Entidade*>(temp));
	}

	/***********************************************************************************/
	//Criando andares

	tam = sf::Vector2f(350.f, 50.f);

	for(int i = 0; i < 2; i++)
	{
		pos = sf::Vector2f(25.f + 150.f * ((i+1) % 2), 175.f + 200.f * i);
		temp = new Solo("Andar2");
		temp->setBody(tam);
		temp->getBody()->setPosition(pos);
		listaEntidades.LEs.push(temp);
	}

	tam.x = 600;
	pos = sf::Vector2f(175.f, 575.f);
	temp = new Solo("Andar2");
	temp->setBody(tam);
	temp->getBody()->setPosition(pos);
	listaEntidades.LEs.push(temp);

	tam.x = 500.f;
	pos = sf::Vector2f(750.f, 175.f);
	temp = new Solo("Andar2");
	temp->setBody(tam);
	temp->getBody()->setPosition(pos);
	listaEntidades.LEs.push(temp);

	tam.x = 250.f;
	pos.x = 1325.f;
	for (int i = 0; i < 2; i++)
	{
		tam.x = 250.f;
		pos.y = 175.f + (400.f * i);
		temp = new Solo("Andar2");
		temp->setBody(tam);
		temp->getBody()->setPosition(pos);
		listaEntidades.LEs.push(temp);
	}

	tam.x = 350.f;
	pos = sf::Vector2f(1075.f, 375.f);
	temp = new Solo("Andar2");
	temp->setBody(tam);
	temp->getBody()->setPosition(pos);
	listaEntidades.LEs.push(temp);

	/***********************************************************************************/
	//Criando Escadas

	tam = sf::Vector2f(200.f, 50.f);
	for (int i = 0; i < 3; i++)
	{
		tam.x += -50.f;
		pos = sf::Vector2f(1075.f + (50.f * i), 725.f - (50.f * i));
		temp = new Solo("Escada");
		temp->setBody(tam);
		temp->getBody()->setPosition(pos);
		listaEntidades.LEs.push(temp);
	}

	pos = sf::Vector2f(800.f, 325.f);
	for(int i = 1; i <= 5; i++)
	{
		tam.x = 50.f * i;
		pos.y += 50.f;
		temp = new Solo("Escada");
		temp->setBody(tam);
		temp->getBody()->setPosition(pos);
		listaEntidades.LEs.push(temp);
	}

	pos = sf::Vector2f(550.f, 125.f);
	for (int i = 1; i <= 5; i++)
	{
		tam.x = 50.f * i;
		pos.y += 50.f;
		temp = new Solo("Escada");
		temp->setBody(tam);
		temp->getBody()->setPosition(pos);
		listaEntidades.LEs.push(temp);
	}

}

//Cria os elementos da fase
void FaseDois::criarFase()
{
	criarTerreno();
	criarInimigosFaceis();
	criarInimigosMedios();
	criarObstaculosMedios();
	criarObstaculosDificeis();
}

//Deleta os elementos criados para a fase
void FaseDois::apagarFase()
{
	{
		for (int i = 0; i < listaJogadores->getLen(); i++)
		{
			if (listaJogadores->getItem(i)->getTipo() != 1)
			{
				delete listaJogadores->getItem(i);
			}
		}
	}
}

//Atualiza o fundo da janela caso algum jogador mude de sala
void FaseDois::atualizarFundo()
{
	if (sala_Atual == 1)
		atualizarTextura("../Imagens/Background2.2.png");
	else
		atualizarTextura("../Imagens/Background2.1.png");
}

//Verifica se algum jogador chegou ao final da fase, encerra a fase caso sim
bool FaseDois::verificarFim()
{
	sf::FloatRect saida(1500.f, 675.f, 100.f, 100.f);
	for (int i = 0; i < listaJogadores->getLen(); i++)
	{
		if (saida.contains(listaJogadores->getItem(i)->getCentro()))
			return true;
	}
	return false;
}

//Verifica se algum jogador foi para outra sala
bool FaseDois::mudouSala()
{
	bool flag = false;
	for (int i = 0; i < salas.size(); i++)
	{
		if (salas[i]->contains(listaJogadores->getItem(0)->getCentro()) && sala_Atual != i)
		{
			flag = true;
			sala_Atual = i;
			body.setPosition((salas[i]->getPosition()));
			if (listaJogadores->getLen() == 2)
				listaJogadores->getItem(1)->getBody()->setPosition(listaJogadores->getItem(0)->getBody()->getPosition());
		}
		else if (listaJogadores->getLen() == 2)
			if (salas[i]->contains(listaJogadores->getItem(1)->getCentro()) && sala_Atual != i)
			{
				flag = true;
				sala_Atual = i;
				body.setPosition((salas[i]->getPosition()));
				listaJogadores->getItem(0)->getBody()->setPosition(listaJogadores->getItem(1)->getBody()->getPosition());
			}
	}
	return flag;
}

void FaseDois::executar()
{
	incluirElementosColisao();
	Personagem* pPers = nullptr;
	Obstaculo* pObst = nullptr;
	Entidade* pEnt = nullptr;
	vector<Inimigo*>::iterator itInim;
	list<Obstaculo*>::iterator itObst;
	int i = 0;

	//Move os jogadores para o inicio da fase
	for (i = 0; i < listaJogadores->getLen(); i++)
	{
		Jogador* pJog = listaJogadores->getItem(i);
		pJog->getBody()->setPosition(sf::Vector2f(450.f, 100.f));
	}

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
		pGrafico->limparJanela();
		desenhar();
		for (int i = 0; i < listaEntidades.LEs.getLen(); i++)
		{
			pEnt = listaEntidades.LEs.getItem(i);
			if (pEnt->getNoJogo())
			{
				pEnt->executar();
				pEnt->desenhar();
			}
		}


		if (mudouSala())
			atualizarFundo();
		pGrafico->getWindow()->setView(sf::View(*salas[sala_Atual]));
		pColisao->executar();
		pGrafico->mostrarElementos();
		if (verificarFim())
			return;
		if (verificaGameOver())
			return;
	}
}