#include "Esqueleto.h"


Esqueleto::Esqueleto(Jogador* jogador) :
	Inimigo(VIDA_ESQUELETO), pJogador(jogador), moveAleatorio(rand() % 5)
{
	vida = VIDA_ESQUELETO;
	vel.x = VEL_ESQUELETO_X;
	vel.y = VEL_ESQUELETO_Y;
	nivel_maldade = rand() % 2 + 1;
	relogio.restart();
	setBody(sf::Vector2f(30.f, 50.f));
}


Esqueleto::~Esqueleto()
{
	pJogador = nullptr;
}

void Esqueleto::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
	if (nivel_maldade == 2)
		body.setFillColor(sf::Color::Magenta);
	atualizarTextura("../Imagens/EsqueletoD.png");
}

void Esqueleto::mudarVelocidade(float fator)
{
	alteracaoVel *= fator;
}

void Esqueleto::danificar(Jogador* pJog)
{
	pJog->operator--();
	if (pJog->getCentro().x < getCentro().x)
		pJog->empurrar(true);
	else
		pJog->empurrar(false);
}

void Esqueleto::perseguir() // Persegue o jogador se o mesmo entrar no aggro
{
	if (pJogador->getCentro().x - getCentro().x > 0.0f) {
		if (direita)
			vel.x += VEL_ESQUELETO_X * (nivel_maldade + 1) / 2.f; //Quanto maior o n�vel de maldade, maior a persegui��o 
		atualizarTextura("../Imagens/EsqueletoD.png");
	}
	else {
		if (esquerda)
			vel.x -= VEL_ESQUELETO_X * nivel_maldade;
		atualizarTextura("../Imagens/EsqueletoE.png");
	}
}


void Personagens::Esqueleto::movimentoAleatorio() // Movimento aleat�rio do esqueleto
{
	if (moveAleatorio == 1 && direita) {
		vel.x += VEL_ESQUELETO_X;
		atualizarTextura("../Imagens/EsqueletoD.png");
	}
	else if (moveAleatorio == 2 && esquerda) {
		vel.x -= VEL_ESQUELETO_X;
		atualizarTextura("../Imagens/EsqueletoE.png");
	}
	else {
		vel.x = 0;  // Pausas ocasionais no movimento
	}

	if (relogio.getElapsedTime().asSeconds() >= 1.0f) {	// Relogio que controla o movimento aleatorio
		moveAleatorio = rand() % 3;
		relogio.restart();
	}
}


void Esqueleto::move() // Gerencia todo o movimento do esqueleto
{
	sf::Vector2f posJogador = pJogador->getCentro();
	sf::Vector2f posEsqueleto = getCentro();

	if (fabsf(posJogador.x - posEsqueleto.x) <= RAIO_AGGRO_X && fabsf(posJogador.y - posEsqueleto.y) <= RAIO_AGGRO_Y) {

		perseguir();

		moveAleatorio = 4; // Para o esqueleto ap�s sair do aggro
		relogio.restart();

	}
	else {
		movimentoAleatorio();
	}
	if (cair) {
		if (tempo_queda.getElapsedTime().asSeconds() > 1.f)
			tempo_queda.restart();
		vel.y = VEL_ESQUELETO_X * tempo_queda.getElapsedTime().asSeconds() + 9.8f / 2.f * tempo_queda.getElapsedTime().asSeconds() * tempo_queda.getElapsedTime().asSeconds();
	}
	else
		tempo_queda.restart();
	vel.x *= alteracaoVel;
	vel.y *= alteracaoVel;
	vel.y += 0.1f; //Uma corre��o para ele conseguir passar pelo gelo 

	body.move(sf::Vector2f(vel.x, vel.y));

	vel.x = 0;
	vel.y = 0;
	alteracaoVel = 1.f;
	cair = true;
	esquerda = true;
	direita = true;
}


void Esqueleto::executar() 
{
	if (vida == 1)
		body.setSize(sf::Vector2f(30.f, 25.f));
	move(); 
}