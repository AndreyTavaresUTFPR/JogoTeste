#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorColisao.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "MenuPrincipal.h"
#include "Obstaculo.h"
#include "Inimigo.h"

namespace Gerenciadores
{
	class GerenciadorEvento
	{
	private:
		GerenciadorGrafico* pGrafico;
		GerenciadorColisao* pColisao;
		Lista<Jogador>* listaJogadores;
		Lista<Inimigo>* listaInimigos;
		Lista<Obstaculo>* listaObstaculos;
		MenuPrincipal* menuPrincipal;
		

		static GerenciadorEvento* pEventos;
		GerenciadorEvento();
	public:
		~GerenciadorEvento();
		static GerenciadorEvento* getGerenciadorEvento();
		void setListas(Lista<Jogador>* listaJog, Lista<Inimigo>* listaInim, Lista<Obstaculo>* listaObst);
		void verificaTeclaPressionada(sf::Keyboard::Key tecla);
		void verificaTeclaSolta(sf::Keyboard::Key tecla);
		void executarMenuPrincipal();
		void executarFaseUm();
		void executar();
	};
} using namespace Gerenciadores;