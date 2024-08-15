#include "Inimigo.h"


Inimigo::Inimigo(Jogador* jogador):
	Personagem(), vida(VIDA_INIMIGO), vel(VEL_INIMIGO_X, VEL_INIMIGO_Y), jogador(jogador)
{
	body.setFillColor(sf::Color::Magenta);
	body.setPosition(sf::Vector2f(400.f, 250.f));
}


Inimigo::~Inimigo()
{
}


void Inimigo::perseguir(sf::Vector2f posJogador, sf::Vector2f posInimigo) // Persegue o jogardor se o mesmo entrar no aggro
{
	if (posJogador.x - posInimigo.x > 0.0f) {
		body.move(vel.x, 0.0f);
	} else {
		body.move(-vel.x, 0.0f);
	}

	if (posJogador.y - posInimigo.y > 0.0f) {
		body.move(0.0f, vel.y);
	}
	else {
		body.move(0.0f, -vel.y);
	}
}


void Inimigo::move()
{
	sf::Vector2f posJogador = jogador->getBody().getPosition();
	sf::Vector2f posInimigo = getBody().getPosition();

	if (fabs(posJogador.x - posInimigo.x) <= RAIO_AGGRO_X &&
		fabs(posJogador.y - posInimigo.y) <= RAIO_AGGRO_Y)   {

			perseguir(posJogador, posInimigo);
	}
	// mvimento Aleatorio; à implementar
}


void Inimigo::executar()
{
	move();
}
