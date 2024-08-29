#include "Aranha.h"

Aranha::Aranha():
	Inimigo(), pulo(VELOCIDADE_HORIZONTAL, VELOCIDADE_PULO)
{
	timer_gravidade.restart();
	nivel_maldade = 2;
	setBody(sf::Vector2f(30.f, 30.f));
}

Aranha::~Aranha()
{
}

void Aranha::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
	//body.setFillColor(sf::Color::Yellow);
	textura.loadFromFile("../Imagens/Aranha.png");
	body.setTexture(&textura);
	body.setPosition(sf::Vector2f(700.f, 250.f));
}


void Aranha::liberarGravidade()
{
	cair = true;
	vel.y = VELOCIDADE_PULO;
}


void Aranha::liberarMovimento()
{
	esquerda = true;
	direita = true;
	vel.x = VELOCIDADE_HORIZONTAL;
}

void Aranha::mudarVelocidade(float fator)
{
	vel.x = VELOCIDADE_HORIZONTAL * fator;
	vel.y = VELOCIDADE_PULO * fator;
}

void Aranha::danificar()
{

}

void Aranha::pular()
{
	float tempo = timer_gravidade.getElapsedTime().asSeconds();
	pulo.x = -pulo.x;
		body.move(sf::Vector2f(pulo.x, pulo.y + (9.8f / 2.f * (tempo * tempo))));
		//body.move(sf::Vector2f(-pulo.x, pulo.y + (9.8f / 2.f * (tempo * tempo)))); PENSAR EM COMO IMPLEMENTAR O MOVIMENTO ALEATORIO
}


void Aranha::move()
{
	pular();

	if (!cair) {
		timer_gravidade.restart();
	}
}

void Aranha::executar()
{
	if (body.getPosition().x > 800-body.getSize().x || body.getPosition().x < 0)
		pulo.x = -pulo.x;

	move();
}

