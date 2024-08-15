#pragma once
#include "Personagem.h"
#include "Jogador.h"

#define VIDA_INIMIGO 100

#define VEL_INIMIGO_X 0.05f
#define VEL_INIMIGO_Y 0.05f

#define RAIO_AGGRO_X 200.0f
#define RAIO_AGGRO_Y 200.0f


namespace Personagens {
	class Inimigo : public Personagem
	{
	private:
		int vida;
		sf::Vector2f vel;

		Jogador* jogador; // Ponteiro para jogador
		sf::Clock relogio;
		int moveAleatorio;

	public:
		Inimigo(Jogador* jogador);
		~Inimigo();

		
		void perseguir(sf::Vector2f posJogador, sf::Vector2f posInimigo);
		void movimentoAleatorio();
		void move();
		void executar();
	};
} using namespace Personagens;