#pragma once
#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "ListaEntidades.h"

namespace Gerenciadores
{
	class GerenciadorEvento
	{
	private:
		GerenciadorGrafico* pGrafico;
		Jogador* pJogador;
		ListaEntidades* pLista;

		static GerenciadorEvento* pEventos;
		GerenciadorEvento();
	public:
		~GerenciadorEvento();
		static GerenciadorEvento* getGerenciadorEvento();
		void setJogador(Jogador* pJog);
		void setLista(ListaEntidades* lista);
		void verificaTeclaPressionada(sf::Keyboard::Key tecla);
		void verificaTeclaSolta(sf::Keyboard::Key tecla);
		void executar();
	};
} using namespace Gerenciadores;