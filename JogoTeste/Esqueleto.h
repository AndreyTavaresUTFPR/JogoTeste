#pragma once
#include "Inimigo.h"
#include "Jogador.h"
#include "Lista.h"

#define VIDA_ESQUELETO 2

#define VEL_ESQUELETO_X 1.f
#define VEL_ESQUELETO_Y 1.f

#define RAIO_AGGRO_X 200.0f
#define RAIO_AGGRO_Y 100.0f


namespace Personagens {
	class Esqueleto : public Inimigo
	{
	private:
		Lista<Jogador>* listaJogadores;
		int moveAleatorio;

	public:
		Esqueleto();
		Esqueleto(Lista<Jogador>* listaJog);
		~Esqueleto();

		void setBody(sf::Vector2f tam);
		void mudarVelocidade(float fator);
		void danificar(Jogador* pJog);
		void perseguir(float distanciaX);
		void movimentoAleatorio();
		void move();
		void executar();
	};
} using namespace Personagens;