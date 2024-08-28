#include "Projetil.h"

Projetil::Projetil(sf::Vector2f tam, sf::Vector2f pos, Jogador* pJogador):
	Entidade(), pJogador(pJogador)
{
	time_vivo = TEMPO_DE_VIDA;
	this->setBody(tam);
	this->body.setPosition(pos);
	vel.x = VELOCIDADE_PROJETIL_X;
	vel.y = VELOCIDADE_PROJETIL_Y;

	if (this->pJogador->getCentro().x <= this->getCentro().x)
		vel.x = -vel.x;
	if (this->pJogador->getCentro().y <= this->getCentro().y)
		vel.y = -vel.y; 

	executar();
}

Projetil::~Projetil()
{
}

void Projetil::executar()
{
	while (time_vivo >= 0) {
		this->body.move(vel);
		time_vivo--;
	}

}
