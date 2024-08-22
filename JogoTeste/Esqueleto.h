#pragma once
#include "Inimigo.h"
#include "Jogador.h"

#define VIDA_ESQUELETO 100

#define VEL_ESQUELETO_X 0.05f
#define VEL_ESQUELETO_Y 0.05f

#define RAIO_AGGRO_X 200.0f
#define RAIO_AGGRO_Y 200.0f


namespace Personagens {
	class Esqueleto : public Inimigo
	{
	private:
		Jogador* jogador; // Ponteiro para jogador
		sf::Clock relogio;
		int moveAleatorio;

	public:
		Esqueleto(Jogador* jogador);
		~Esqueleto();

		virtual void setBody(sf::Vector2f tam);
		void perseguir(sf::Vector2f posJogador, sf::Vector2f posEsqueleto);
		void movimentoAleatorio();
		void move();
		void executar();
	};
} using namespace Personagens;