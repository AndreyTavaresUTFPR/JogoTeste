#pragma once
#include "Inimigo.h"
#include "Jogador.h"
#include "ListaJogadores.h"

#define VIDA_ESQUELETO 100

#define VEL_ESQUELETO_X 0.15f
#define VEL_ESQUELETO_Y 0.2f

#define RAIO_AGGRO_X 200.0f
#define RAIO_AGGRO_Y 100.0f


namespace Personagens {
	class Esqueleto : public Inimigo
	{
	private:
		ListaJogadores* LJogs;
		Jogador* jogador; // Ponteiro para jogador
		Jogador* jogador2;
		sf::Clock relogio;
		int moveAleatorio;

	public:
		Esqueleto(ListaJogadores* listaJogadores);
		~Esqueleto();

		virtual void setBody(sf::Vector2f tam);
		void liberarGravidade();
		void liberarMovimento();
		void mudarVelocidade(float fator);
		void perseguir(sf::Vector2f posJogador, sf::Vector2f posEsqueleto);
		void movimentoAleatorio();
		void move();
		void executar();
	};
} using namespace Personagens;