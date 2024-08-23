#include "Esqueleto.h"


Esqueleto::Esqueleto(Jogador* jogador):
	Inimigo(), jogador(jogador), moveAleatorio(rand()%5)
{
	vida = VIDA_ESQUELETO;
	vel.x = VEL_ESQUELETO_X;
	vel.y = VEL_ESQUELETO_Y;
	relogio.restart();
}


Esqueleto::~Esqueleto()
{
}

void Esqueleto::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
	body.setFillColor(sf::Color::Magenta);
	body.setPosition(sf::Vector2f(400.f, 250.f));
}

void Esqueleto::perseguir(sf::Vector2f posJogador, sf::Vector2f posEsqueleto) // Persegue o jogardor se o mesmo entrar no aggro
{
	if (posJogador.x - posEsqueleto.x > 0.0f) {
		if (direita)
			body.move(vel.x, 0.0f);
		esquerda = true;
	} else {
		if (esquerda)
			body.move(-vel.x, 0.0f);
		direita = true;
	}
}


void Personagens::Esqueleto::movimentoAleatorio() // Movimento aleatório do esqueleto
{
	if (moveAleatorio == 1 && direita) {
		body.move(vel.x/2.f, 0.f);
		if (body.getPosition().x + body.getSize().x > pGrafico->getWindow()->getSize().x)
			body.setPosition((pGrafico->getWindow()->getSize().x - body.getSize().x), body.getPosition().y);
	}
	else if (moveAleatorio == 2 && esquerda) {
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


void Esqueleto::move() // Gerencia todo o movimento do esqueleto
{
	sf::Vector2f posJogador = jogador->getBody().getPosition();
	sf::Vector2f posEsqueleto = getBody().getPosition();

	if (fabs(posJogador.x - posEsqueleto.x) <= RAIO_AGGRO_X) {

			perseguir(posJogador, posEsqueleto);

			moveAleatorio = 4; // Para o esqueleto após sair do aggro
			relogio.restart();

	} else {
		movimentoAleatorio();
	}
	if (cair) {
		body.move(sf::Vector2f(0, 9.8f * relogio.getElapsedTime().asSeconds() * relogio.getElapsedTime().asSeconds()));
	}

}


void Esqueleto::executar() { move(); } // Move o esqqueleto corretamente
