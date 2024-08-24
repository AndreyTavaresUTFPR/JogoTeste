#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorColisao.h"
#include "ListaJogadores.h"
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
		ListaJogadores* listaJogadores;
		Lista<Inimigo>* listaInimigos;
		Lista<Obstaculo>* listaObstaculos;
		MenuPrincipal menujogo;
		

		static GerenciadorEvento* pEventos;
		GerenciadorEvento();
	public:
		~GerenciadorEvento();
		static GerenciadorEvento* getGerenciadorEvento();
		void setListas(ListaJogadores* listaJog, Lista<Inimigo>* listaInim, Lista<Obstaculo>* listaObst);
		void verificaTeclaPressionada(sf::Keyboard::Key tecla);
		void verificaTeclaSolta(sf::Keyboard::Key tecla);
		void executarMenu();
		void executarFaseUm();
		void executar();
	};
} using namespace Gerenciadores;