#include "Chefe.h"

Chefe::Chefe():
	tempo_ataque(DELAY)
{
	vel.x = 0.f;
	vel.y = 0.f;
	this->setBody(sf::Vector2f(60.f, 120.f));
	nivel_maldade = 3;
	delay.restart();
	pJogador = nullptr;
	listaProjetil = nullptr;

}


Chefe::~Chefe()
{
}

void Chefe::atacarProjetil()
{
	sf::Vector2f tamProjetil(10.f, 10.f);
	listaProjetil->push(new Projetil(tamProjetil, pJogador));
}

void Chefe::move()
{
}

void Chefe::executar()
{
	if (delay.getElapsedTime().asSeconds() >= DELAY) {
		atacarProjetil();
		delay.restart();
	}
	move();
}


void Chefe::liberarGravidade()
{
	cair = true;
	vel.y = 0.f;
}


void Chefe::liberarMovimento()
{
	esquerda = true;
	direita = true;
	vel.x = 0.f;
}


void Chefe::mudarVelocidade(float fator)
{
	vel.x = 0.f + fator;
	vel.y = 0.f + fator;
}

void Chefe::danificar()
{

}

void Chefe::setJogador(Jogador* jogador)
{
	this->pJogador = jogador;
}

void Chefe::setLProj(Lista<Projetil>* listaProjetil)
{
	this->listaProjetil = listaProjetil;
}

