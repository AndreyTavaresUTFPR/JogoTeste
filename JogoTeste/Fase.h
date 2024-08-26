#pragma once
#include "Ente.h"
#include "Jogador.h"
#include "ListaJogadores.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Projetil.h"
#include <SFML/Graphics.hpp>

namespace Fases {
	class Fase : public Ente
	{
	protected:
		ListaJogadores listaJogadores;
		Lista<Inimigo> listaInimigos;
		Lista<Obstaculo> listaObstaculos;
		Lista<Projetil> listaProjetil;
		Jogador* j1;
		Jogador* j2;

		virtual void inicializaElementos() = 0;

	public:
		Fase(Jogador* j1, Jogador* j2);
		virtual ~Fase();

		ListaJogadores* getListaJogadores();
		Lista<Inimigo>* getListaInimigos();
		Lista<Obstaculo>* getListaObstaculos();
		void executar() = 0;
	};
} using namespace Fases;
