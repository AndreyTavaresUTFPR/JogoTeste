#pragma once
#include "Inimigo.h"
#include "Jogador.h"

#define VIDA_ESQUELETO 100

#define VEL_ESQUELETO_X 0.15f
#define VEL_ESQUELETO_Y 0.2f

#define RAIO_AGGRO_X 200.0f
#define RAIO_AGGRO_Y 100.0f


namespace Personagens {
	class Esqueleto : public Inimigo
	{
	private:
		Jogador* jogador; // Ponteiro para jogador
		int moveAleatorio;

	public:
		Esqueleto(Jogador* jogador);
		~Esqueleto();

		void setBody(sf::Vector2f tam);
		void mudarVelocidade(float fator);
		void danificar(Jogador* pJog);
		void perseguir(sf::Vector2f posJogador, sf::Vector2f posEsqueleto);
		void movimentoAleatorio();
		void move();
		void executar();
	};
} using namespace Personagens;