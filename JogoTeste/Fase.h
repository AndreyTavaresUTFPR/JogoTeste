#pragma once
#include "Ente.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>

namespace Fases {
	class Fase : public Ente
	{
	protected:
		ListaEntidades* lPersonagens;
		ListaEntidades* lObstaculos;
		Jogador* j1;

		virtual void inicializaElementos() = 0;

	public:
		Fase(Jogador* j1);
		virtual ~Fase();

		
		ListaEntidades* getListaPersonagens();
		ListaEntidades* getListaObstaculos();
		void executar();
	};
} using namespace Fases;
