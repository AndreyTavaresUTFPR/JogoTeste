#include "FaseDois.h"

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

	n_esqueletos = rand() % 3 + 3;
	n_aranhas = rand() % 3 + 3;
	n_gelos = rand() % 3 + 3;
	n_espinhos = rand() % 3 + 3;

	criarFase();
}

FaseDois::~FaseDois()
{
	listaJogadores = nullptr;
	apagarFase();
	pColisao->limparListas();
}

//Cria Esqueleto na fase e distribui de forma aleatoria
void FaseDois::criarInimigosFaceis()
{
	vector<sf::Vector2f> posicoesPossiveis = { {200.f + (float)(rand() % 200), 125.f}, { 200.f + (float)(rand() % 200), 325.f }, {200.f + (float)(rand() % 200), 525.f}, {200.f + (float)(rand() % 200), 725.f},
												{-600.f + (float)(rand() % 200), 725.f}, {-600.f + (float)(rand() % 200), 925.f}, {-600.f + (float)(rand() % 200), 1125.f}, {-600.f + (float)(rand() % 200), 1325.f} };

	std::random_shuffle(posicoesPossiveis.begin(), posicoesPossiveis.end());
	vector<sf::Vector2f>::iterator it = posicoesPossiveis.begin();

	for (int i = 0; i < n_esqueletos; i++)
	{
		Esqueleto* aux = nullptr;
		aux = new Esqueleto(listaJogadores->getItem(0));
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
	vector<sf::Vector2f> posicoesPossiveis = { {200.f + (float)(rand() % 300), 145.f}, {200.f + (float)(rand() % 300), 345.f}, {200.f + (float)(rand() % 300), 545.f}, {200.f + (float)(rand() % 300), 745.f},
												{-600.f + (float)(rand() % 300), 745.f}, {-600.f + (float)(rand() % 300), 945.f}, {-600.f + (float)(rand() % 300), 1145.f}, {-600.f + (float)(rand() % 300), 1345.f} };

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
	vector<sf::Vector2f> posicoesPossiveis = { {200.f + (float)(rand() % 300), 174.9f}, {200.f + (float)(rand() % 300), 374.9f}, {200.f + (float)(rand() % 300), 574.9f}, {200.f + (float)(rand() % 300), 774.9f},
												{-600.f + (float)(rand() % 300), 774.9f}, {-600.f + (float)(rand() % 300), 974.9f}, {-600.f + (float)(rand() % 300), 1174.9f}, {-600.f + (float)(rand() % 300), 1374.9f} };

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

void FaseDois::criarObstaculosDificeis()
{

}

//Cria o terreno da fase
void FaseDois::criarTerreno()
{
	//Criando Terreno da Primeira Sala

	//Criando Paredes
	Solo* temp = new Solo();
	sf::Vector2f tam(25.f, 750.f);
	sf::Vector2f pos(0.f, 25.f);
	temp->setBody(tam); 
	temp->getBody()->setPosition(pos);
	temp->atualizarTextura("../Imagens/Parede2.png");
	listaEntidades.LEs.push(static_cast<Entidade*>(temp));

	temp = new Solo();
	tam.y = 400.f;
	pos.x = 525.f;
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Parede2.png");
	temp->getBody()->setPosition(pos); 
	listaEntidades.LEs.push(static_cast<Entidade*>(temp));

	temp = new Solo();
	tam.y = 200.f;
	pos = sf::Vector2f(775.f, 425.f);
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Parede2.png");
	temp->getBody()->setPosition(pos);
	listaEntidades.LEs.push(static_cast<Entidade*>(temp));

	temp = new Solo();
	pos = sf::Vector2f(1050.f, 225.f);
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Parede2.png");
	temp->getBody()->setPosition(pos);
	listaEntidades.LEs.push(static_cast<Entidade*>(temp));

	/***********************************************************************************/
	//Criando teto e chão

	temp = new Solo();
	tam = sf::Vector2f(800.f, 25.f);
	pos = sf::Vector2f(0.f, 0.f);
	temp->setBody(tam);
	temp->getBody()->setPosition(pos); //Teto
	temp->atualizarTextura("../Imagens/Teto2.png");
	listaEntidades.LEs.push(static_cast<Entidade*>(temp));

	temp = new Solo();
	pos = sf::Vector2f(0.f, 775.f);
	temp->setBody(tam);
	temp->getBody()->setPosition(pos); //Chão
	temp->atualizarTextura("../Imagens/Teto2.png");
	listaEntidades.LEs.push(static_cast<Entidade*>(temp));

	/***********************************************************************************/
	//Criando andares

	tam = sf::Vector2f(350.f, 50.f);

	for(int i = 0; i < 2; i++)
	{
		pos = sf::Vector2f(25.f + 150.f * ((i+1) % 2), 175.f + 200.f * i);
		temp = new Solo();
		temp->setBody(tam);
		temp->atualizarTextura("../Imagens/Andar2.png");
		temp->getBody()->setPosition(pos);
		listaEntidades.LEs.push(temp);
	}

	tam.x = 600;
	pos = sf::Vector2f(175.f, 575.f);
	temp = new Solo();
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Andar2.png");
	temp->getBody()->setPosition(pos);
	listaEntidades.LEs.push(temp);

	tam.x = 500.f;
	pos = sf::Vector2f(750.f, 175.f);
	temp = new Solo();
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Andar2.png");
	temp->getBody()->setPosition(pos);
	listaEntidades.LEs.push(temp);

	tam.x = 250.f;
	pos.x = 1325.f;
	temp = new Solo();
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Andar2.png");
	temp->getBody()->setPosition(pos);
	listaEntidades.LEs.push(temp);

	tam.x = 350.f;
	pos = sf::Vector2f(1075.f, 375.f);
	temp = new Solo();
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Andar2.png");
	temp->getBody()->setPosition(pos);
	listaEntidades.LEs.push(temp);

	tam = sf::Vector2f(200.f, 50.f);
	for (int i = 0; i < 3; i++)
	{
		tam.x += -50.f;
		pos = sf::Vector2f(1075.f + (50.f * i), 725.f - (50.f * i));
		temp = new Solo();
		temp->setBody(tam);
		temp->atualizarTextura("../Imagens/Escada2.png");
		temp->getBody()->setPosition(pos);
		listaEntidades.LEs.push(temp);
	}
	/*
	tam = sf::Vector2f(125.f, 50.f);
	pos = sf::Vector2f(1075.f, 675.f);
	temp = new Solo();
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Escada2.png");
	temp->getBody()->setPosition(pos);
	listaEntidades.LEs.push(temp);

	tam = sf::Vector2f(50.f, 50.f);
	pos = sf::Vector2f(1150.f, 625.f);
	temp = new Solo();
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Escada2.png");
	temp->getBody()->setPosition(pos);
	listaEntidades.LEs.push(temp);
	*/

	pos = sf::Vector2f(800.f, 325.f);
	for(int i = 1; i <= 5; i++)
	{
		tam.x = 50 * i;
		pos.y += 50.f;
		temp = new Solo();
		temp->setBody(tam);
		temp->atualizarTextura("../Imagens/Escada2.png");
		temp->getBody()->setPosition(pos);
		listaEntidades.LEs.push(temp);
	}

	pos = sf::Vector2f(550.f, 125.f);
	for (int i = 1; i <= 5; i++)
	{
		tam.x = 50 * i;
		pos.y += 50.f;
		temp = new Solo();
		temp->setBody(tam);
		temp->atualizarTextura("../Imagens/Escada2.png");
		temp->getBody()->setPosition(pos);
		listaEntidades.LEs.push(temp);
	}

	/*
	for (int i = 1; i <= 3; i++)
	{
		temp = new Solo();
		if (temp == nullptr)
			cout << "Erro ao criar Solo." << endl;
		pos = sf::Vector2f(25.f + 150.f * ((i - 1) % 2), 200.f * i - 25.f);
		temp->setBody(tam);
		temp->getBody()->setPosition(pos);
		temp->atualizarTextura("../Imagens/Andar.png");
		listaEntidades.LEs.push(static_cast<Entidade*>(temp));
	}
	*/
	//Por algum motivo o andar da altura 600 não está sendo criado, então tive que fazer ele fora do loop
	pos = sf::Vector2f(25.f, 600.f - 25.f);
	temp = new Solo();
	temp->setBody(tam);
	temp->getBody()->setPosition(pos);
	temp->atualizarTextura("../Imagens/Andar2.png");
	listaEntidades.LEs.push(static_cast<Entidade*>(temp));

	/***********************************************************************************/
	//Criando Terreno da Segunda Sala

	//Criando Paredes
	tam = sf::Vector2f(25.f, 750.f);
	pos = sf::Vector2f(1575.f, 25.f);
	temp->setBody(tam); //Parede lateal esquerda
	temp->getBody()->setPosition(pos);
	temp->atualizarTextura("../Imagens/Parede2.png");
	listaEntidades.LEs.push(static_cast<Entidade*>(temp));

	temp = new Solo();
	tam.y = 650.f;
	pos.x = -25.f;
	pos.y = 775.f;
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Parede2.png");
	temp->getBody()->setPosition(pos); //Parede da lateral direita
	listaEntidades.LEs.push(static_cast<Entidade*>(temp));

	/***********************************************************************************/
	//Criando Teto e Chao

	temp = new Solo();
	tam = sf::Vector2f(800.f, 25.f);
	pos = sf::Vector2f(800.f, 0.f);
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Teto2.png");
	temp->getBody()->setPosition(pos); //Teto
	listaEntidades.LEs.push(static_cast<Entidade*>(temp));

	temp = new Solo();
	pos.y = 775.f;
	temp->setBody(tam);
	temp->atualizarTextura("../Imagens/Teto2.png");
	temp->getBody()->setPosition(pos); //Chão
	listaEntidades.LEs.push(static_cast<Entidade*>(temp));

	/***********************************************************************************/
	//Criando Andares

	for (int i = 0; i < 3; i++)
	{
		temp = new Solo();
		tam = sf::Vector2f(600.f, 50.f);
		pos = sf::Vector2f(-775.f + 150.f * ((i + 1) % 2), 200.f * (i + 1) + 575.f);
		temp->setBody(tam);
		temp->atualizarTextura("../Imagens/Andar2.png");
		temp->getBody()->setPosition(pos);
		listaEntidades.LEs.push(static_cast<Entidade*>(temp));
	}
}

//Cria os elementos da fase
void FaseDois::criarFase()
{
	criarTerreno();
	//criarInimigosFaceis();
	//criarInimigosMedios();
	//criarObstaculosMedios();
	//criarObstaculosDificeis();
}

//Deleta os elementos criados para a fase
void FaseDois::apagarFase()
{

}

//Atualiza o fundo da janela caso algum jogador mude de sala
void FaseDois::atualizarFundo()
{
	if (sala_Atual == 1)
		atualizarTextura("../Imagens/Background2.1.png");
	else
		atualizarTextura("../Imagens/Background2.2.png");
}

//Verifica se algum jogador chegou ao final da fase, encerra a fase caso sim
bool FaseDois::verificarFim()
{
	sf::FloatRect saida(1450.f, 675.f, 100.f, 100.f);
	for (int i = 0; i < listaJogadores->getLen(); i++)
	{
		if (saida.contains(listaJogadores->getItem(i)->getCentro()))
			return true;
	}
	return false;
}

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
		//pJog->getBody()->setPosition(sf::Vector2f(450.f, 100.f));
		pJog->getBody()->setPosition(sf::Vector2f(800.f, 700.f));
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
	}
}