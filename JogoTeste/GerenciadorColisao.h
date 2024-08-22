#pragma once
#include <SFML/Graphics.hpp>
#include "ListaEntidades.h"
#include "Entidade.h"


namespace Gerenciadores {
	class GerenciadorColisao {
	private:
		ListaEntidades* lPersonagens;
		ListaEntidades* lObstaculos;

	public:
		GerenciadorColisao();
		~GerenciadorColisao();

		void setListas(ListaEntidades* listaPers, ListaEntidades* listaObst);

		void repararColisao(Entidade* ent1, Entidade* ent2);
		void executar();
	};
} using namespace Gerenciadores;