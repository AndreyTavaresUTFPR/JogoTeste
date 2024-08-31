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
		Lista<Jogador> listaJogadores;
		vector<Inimigo*> listaInimigos;
		list<Obstaculo*> listaObstaculos;
		
		static GerenciadorColisao* pColisao;
		GerenciadorColisao();
	public:
		~GerenciadorColisao();

		static GerenciadorColisao* getGerenciadorColisao();
		void incluirJogador(Jogador* pJog);
		void incluirInimigo(Inimigo* pInim);
		void incluirObstaculo(Obstaculo* pObst);
		void limparListas();

		void conferirColisaoJogInim(Jogador* pJog, Inimigo* pInim);
		void conferirColisaoJogObst(Jogador* pJog, Obstaculo* pObst);
		void conferirColisaoInimInim(Inimigo* pInim1, Inimigo* pInim2);
		void conferirColisaoInimObst(Inimigo* pInim, Obstaculo* pObst);
		void executar();
	};
} using namespace Gerenciadores;