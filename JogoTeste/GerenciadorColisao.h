#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include "Lista.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
using namespace std;


namespace Gerenciadores {
	class GerenciadorColisao {
	private:
		Lista<Jogador>* listaJogadores;
		vector<Inimigo*> listaInimigos;
		list<Obstaculo*> listaObstaculos;
		
		static GerenciadorColisao* pColisao;
		GerenciadorColisao();
	public:
		~GerenciadorColisao();

		static GerenciadorColisao* getGerenciadorColisao();
		void setListas(Lista<Jogador>* listaJog, Lista<Inimigo>* listaInim, Lista<Obstaculo>* listaObst);

		void conferirColisaoJogInim(Jogador* pJog, Inimigo* pInim);
		void conferirColisaoJogObst(Jogador* pJog, Obstaculo* pObst);
		void conferirColisaoInimInim(Inimigo* pInim1, Inimigo* pInim2);
		void conferirColisaoInimObst(Inimigo* pInim, Obstaculo* pObst);
		void executar();
	};
} using namespace Gerenciadores;