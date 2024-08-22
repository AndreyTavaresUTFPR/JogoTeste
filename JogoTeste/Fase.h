#pragma once
#include "Ente.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Obstaculo.h"
#include <SFML/Graphics.hpp>

namespace Fases {
	class Fase : public Ente
	{
	protected:
		ListaEntidades* lPersonagens;
		Lista<Obstaculo> lObstaculos;
		Jogador* j1;

		virtual void inicializaElementos() = 0;

	public:
		Fase(Jogador* j1);
		virtual ~Fase();

		
		ListaEntidades* getListaPersonagens();
		Lista<Obstaculo>* getListaObstaculos();
		void executar();
	};
} using namespace Fases;
