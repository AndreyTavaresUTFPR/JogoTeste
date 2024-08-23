#pragma once
#include <SFML/Graphics.hpp>
#include "Lista.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"


namespace Gerenciadores {
	class GerenciadorColisao {
	private:
		Lista<Jogador>* listaJogadores;
		Lista<Inimigo>* listaInimigos;
		Lista<Obstaculo>* listaObstaculos;

	public:
		GerenciadorColisao();
		~GerenciadorColisao();

		void setListas(Lista<Jogador>* listaJog, Lista<Inimigo>* listaInim, Lista<Obstaculo>* listaObst);

		void repararColisao(Entidade* ent1, Entidade* ent2);
		void executar();
	};
} using namespace Gerenciadores;