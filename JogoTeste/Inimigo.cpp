#include "Inimigo.h"


Inimigo::Inimigo(Jogador* jogador):
	Personagem(), vida(VIDA_INIMIGO), vel(VEL_INIMIGO_X, VEL_INIMIGO_Y), jogador(jogador), moveAleatorio(rand()%5)
{

}


Inimigo::~Inimigo()
{
}

void Inimigo::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
	body.setFillColor(sf::Color::Magenta);
	body.setPosition(sf::Vector2f(400.f, 250.f));
}

void Inimigo::perseguir(sf::Vector2f posJogador, sf::Vector2f posInimigo) // Persegue o jogardor se o mesmo entrar no aggro
{
	if (posJogador.x - posInimigo.x > 0.0f) {
		body.move(vel.x, 0.0f);
	} else {
		body.move(-vel.x, 0.0f);
	}
}


void Personagens::Inimigo::movimentoAleatorio() // Movimento aleatório do inimigo
{
	if (moveAleatorio == 1) {
		body.move(vel.x/2.f, 0.f);
	}
	else if (moveAleatorio == 2) {
		body.move(-vel.x/2.f, 0.f);
	}
	else {
		body.move(0.f, 0.f);  // Pausas ocasionais no movimento
	}

	float tempo = relogio.getElapsedTime().asSeconds();
	if (tempo >= 1.0f) {	// Relogio que controla o movimento aleatorio
		moveAleatorio = rand() % 3;
		relogio.restart();
	}
}


void Inimigo::move() // Gerencia todo o movimento do inimigo
{
	sf::Vector2f posJogador = jogador->getBody().getPosition();
	sf::Vector2f posInimigo = getBody().getPosition();

	if (fabs(posJogador.x - posInimigo.x) <= RAIO_AGGRO_X) {

			perseguir(posJogador, posInimigo);

			moveAleatorio = 4; // Para o inimigo após sair do aggro
			relogio.restart();

	} else {
		movimentoAleatorio();
	}
	if (cair) {
		body.move(sf::Vector2f(0, 9.8 * relogio.getElapsedTime().asSeconds() * relogio.getElapsedTime().asSeconds()));
	}

}


void Inimigo::executar() { move(); } // Move o inimigo corretamente
