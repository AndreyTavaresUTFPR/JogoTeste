#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorColisao.h"
#include "Jogador.h"
#include "ListaEntidades.h"

namespace Gerenciadores
{
	class GerenciadorEvento
	{
	private:
		GerenciadorGrafico* pGrafico;
		GerenciadorColisao* pColisao;
		Jogador* pJogador;
		ListaEntidades* listaPersonagens;
		ListaEntidades* listaObstaculos;
		

		static GerenciadorEvento* pEventos;
		GerenciadorEvento();
	public:
		~GerenciadorEvento();
		static GerenciadorEvento* getGerenciadorEvento();
		void setJogador(Jogador* pJog);
		void setListaPersonagens(ListaEntidades* lista);
		void setListaObstaculos(ListaEntidades* lista);
		void verificaTeclaPressionada(sf::Keyboard::Key tecla);
		void verificaTeclaSolta(sf::Keyboard::Key tecla);
		void executar();
	};
} using namespace Gerenciadores;