#include "Esqueleto.h"


Esqueleto::Esqueleto(Jogador* jogador) :
	Inimigo(), jogador(jogador), moveAleatorio(rand() % 5)
{
	vida = VIDA_ESQUELETO;
	vel.x = VEL_ESQUELETO_X;
	vel.y = VEL_ESQUELETO_Y;
	nivel_maldade = 1;
	vida = 1;
	relogio.restart();
	setBody(sf::Vector2f(30.f, 60.f));
}


Esqueleto::~Esqueleto()
{
}

void Esqueleto::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
}

void Esqueleto::liberarGravidade()
{
	cair = true;
	vel.y = VEL_ESQUELETO_Y;
}


void Esqueleto::liberarMovimento()
{
	esquerda = true;
	direita = true;
	vel.x = VEL_ESQUELETO_X;
}

void Esqueleto::mudarVelocidade(float fator)
{
	vel.x = VEL_ESQUELETO_X * fator;
	vel.y = VEL_ESQUELETO_Y * fator;
}

void Esqueleto::danificar()
{

}

void Esqueleto::perseguir(sf::Vector2f posJogador, sf::Vector2f posEsqueleto) // Persegue o jogador se o mesmo entrar no aggro
{
	if (posJogador.x - posEsqueleto.x > 0.0f) {
		if (direita)
			body.move(vel.x, 0.0f);
		esquerda = true;
		atualizarTextura("../Imagens/EsqueletoD.png");
	}
	else {
		if (esquerda)
			body.move(-vel.x, 0.0f);
		direita = true;
		atualizarTextura("../Imagens/EsqueletoE.png");
	}
}


void Personagens::Esqueleto::movimentoAleatorio() // Movimento aleat�rio do esqueleto
{
	if (moveAleatorio == 1 && direita) {
		body.move(vel.x, 0.f);
		atualizarTextura("../Imagens/EsqueletoD.png");
		if (body.getPosition().x + body.getSize().x > pGrafico->getWindow()->getSize().x)
			body.move((pGrafico->getWindow()->getSize().x - body.getSize().x), body.getPosition().y);
	}
	else if (moveAleatorio == 2 && esquerda) {
		body.move(-vel.x, 0.f);
		atualizarTextura("../Imagens/EsqueletoE.png");
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
	sf::Vector2f posJogador = jogador->getCentro();
	sf::Vector2f posEsqueleto = getCentro();
	atualizarTextura("../Imagens/EsqueletoD.png");

	if (fabsf(posJogador.x - posEsqueleto.x) <= RAIO_AGGRO_X && fabsf(posJogador.y - posEsqueleto.y) <= RAIO_AGGRO_Y) {

		perseguir(posJogador, posEsqueleto);

		moveAleatorio = 4; // Para o esqueleto ap�s sair do aggro
		relogio.restart();

	}
	else {
		movimentoAleatorio();
	}
	if (cair) {
		body.move(sf::Vector2f(0.f, 9.8f / 2.f * tempo_queda.getElapsedTime().asSeconds() * tempo_queda.getElapsedTime().asSeconds()));
	}
	else
		tempo_queda.restart();

}


void Esqueleto::executar() { move(); } // Move o esqqueleto corretamente