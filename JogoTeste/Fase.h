#pragma once
#include "Ente.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include <SFML/Graphics.hpp>

namespace Fases {
	class Fase : public Ente
	{
	protected:
		Lista<Jogador> listaJogadores;
		Lista<Inimigo> listaInimigos;
		Lista<Obstaculo> listaObstaculos;
		Jogador* j1;
		Jogador* j2;

		virtual void inicializaElementos() = 0;

	public:
		Fase(Jogador* j1, Jogador* j2);
		virtual ~Fase();

		Lista<Jogador>* getListaJogadores();
		Lista<Inimigo>* getListaInimigos();
		Lista<Obstaculo>* getListaObstaculos();
		void executar() = 0;
	};
} using namespace Fases;
