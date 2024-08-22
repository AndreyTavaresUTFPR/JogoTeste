#pragma once
#include <SFML/Graphics.hpp>
#include "ListaEntidades.h"
#include "Entidade.h"
#include "Obstaculo.h"


namespace Gerenciadores {
	class GerenciadorColisao {
	private:
		ListaEntidades* lPersonagens;
		Lista<Obstaculo>* lObstaculos;

	public:
		GerenciadorColisao();
		~GerenciadorColisao();

		void setListas(ListaEntidades* listaPers, Lista<Obstaculo>* listaObst);

		void repararColisao(Entidade* ent1, Entidade* ent2);
		void executar();
	};
} using namespace Gerenciadores;