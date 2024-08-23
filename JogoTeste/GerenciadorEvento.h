#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorColisao.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "MenuPrincipal.h"
#include "Obstaculo.h"

namespace Gerenciadores
{
	class GerenciadorEvento
	{
	private:
		GerenciadorGrafico* pGrafico;
		GerenciadorColisao* pColisao;
		ListaEntidades* listaPersonagens;
		Lista<Obstaculo>* listaObstaculos;
		MenuPrincipal menujogo;
		

		static GerenciadorEvento* pEventos;
		GerenciadorEvento();
	public:
		~GerenciadorEvento();
		static GerenciadorEvento* getGerenciadorEvento();
		void setListas(ListaEntidades* listaPers, Lista<Obstaculo>* listaObst);
		void verificaTeclaPressionada(sf::Keyboard::Key tecla);
		void verificaTeclaSolta(sf::Keyboard::Key tecla);
		void executarMenu();
		void executarFaseUm();
		void executar();
	};
} using namespace Gerenciadores;