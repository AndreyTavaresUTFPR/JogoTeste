#include "Aranha.h"

Aranha::Aranha():
	Inimigo(VIDA_ARANHA)
{
	paraEsquerda = (bool)(rand() % 2);
	peconhenta = (bool)(rand() % 2);
	nivel_maldade = rand() % 2 + 1;
	setBody(sf::Vector2f(30.f, 30.f));
}

Aranha::~Aranha()
{
}

void Aranha::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
	if (peconhenta)
		body.setFillColor(sf::Color::Green);
	textura.loadFromFile("../Imagens/AranhaE.png");
	body.setTexture(&textura);
	body.setPosition(sf::Vector2f(700.f, 250.f));
}

void Aranha::mudarVelocidade(float fator)
{
	alteracaoVel *= fator;
}

void Aranha::danificar(Jogador* pJog)
{
	pJog->operator--();
	if (peconhenta) 
		pJog->operator--();
	if (pJog->getCentro().x < getCentro().x)
		pJog->empurrar(true);
	else
		pJog->empurrar(false);
}

void Aranha::move()
{
	if (paraEsquerda)
		vel.x += -VEL_ARANHA_X * (nivel_maldade + 1) / 2.f;
	else
		vel.x += VEL_ARANHA_X * (nivel_maldade + 1) / 2.f;
	vel.y -= VEL_ARANHA_PULO;
	if (cair)
	{
		if (tempo_queda.getElapsedTime().asSeconds() > 2.f)
			tempo_queda.restart();
		vel.y += 9.8f / 2.f * tempo_queda.getElapsedTime().asSeconds() * tempo_queda.getElapsedTime().asSeconds();
	}
	else
	{
		tempo_queda.restart();
		paraEsquerda = !paraEsquerda;
	}
	if (vel.x > 0)
		atualizarTextura("../Imagens/AranhaD.png");
	else
		atualizarTextura("../Imagens/AranhaE.png");
	body.move(vel);
	vel.x = 0.f;
	vel.y = 0.f;
	alteracaoVel = 1.f;
	cair = true;
	esquerda = true;
	direita = true;

}

void Aranha::executar()
{
	move();
}

