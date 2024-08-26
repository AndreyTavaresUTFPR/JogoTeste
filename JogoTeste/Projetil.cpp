#include "Projetil.h"

Projetil::Projetil(sf::Vector2f tam, Jogador* pJogador):
	Entidade(), pJogador(pJogador)
{
	this->setBody(tam);
	this->body.setPosition(400.f, 700.f);
	vel.x = VELOCIDADE_PROJETIL_X;
	vel.y = VELOCIDADE_PROJETIL_Y;
}

Projetil::~Projetil()
{
}

void Projetil::executar()
{
	if (pJogador->getCentro().x <= this->getCentro().x)
		vel.x = !vel.x;

	this->body.move(vel);
}
