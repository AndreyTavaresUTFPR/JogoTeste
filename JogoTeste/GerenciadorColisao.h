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

		void setListas(ListaEntidades* pPers, ListaEntidades* pObst);
		sf::Vector2f calcularColisao(Entidade* ent1, Entidade* ent2);
		void repararColisao(Entidade* ent1, Entidade* ent2);
		bool verificarColisao(Entidade* ent1, Entidade* ent2);
		void executar();
	};
} using namespace Gerenciadores;