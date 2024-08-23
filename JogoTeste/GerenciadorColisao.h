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

		void conferirColisaoJogInim(Jogador* pJog, Inimigo* pInim);
		void conferirColisaoJogObst(Jogador* pJog, Obstaculo* pObst);
		void conferirColisaoInimInim(Inimigo* pInim1, Inimigo* pInim2);
		void conferirColisaoInimObst(Inimigo* pInim, Obstaculo* pObst);
		void executar();
	};
} using namespace Gerenciadores;