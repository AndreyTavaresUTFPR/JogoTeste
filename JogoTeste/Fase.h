#pragma once
#include "Jogador.h"
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>

namespace Fases {
	class Fase : public Ente
	{
	protected:
		ListaEntidades* lPersonagens;
		Lista<Obstaculo> lObstaculos;
		Jogador* j1;
		Jogador* j2;

		virtual void inicializaElementos() = 0;

	public:
		Fase(Jogador* j1, Jogador* j2);
		virtual ~Fase();

		
		ListaEntidades* getListaPersonagens();
		Lista<Obstaculo>* getListaObstaculos();
		void executar();
	};
} using namespace Fases;
