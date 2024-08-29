#pragma once
#include "Ente.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Projetil.h"
#include "GerenciadorColisao.h"
#include "MenuPausa.h"
#include <SFML/Graphics.hpp>

namespace Fases {
	class Fase : public Ente
	{
	protected:
		Lista<Jogador>* listaJogadores;
		vector<Inimigo*> listaInimigos;
		list<Obstaculo*> listaObstaculos;
		GerenciadorColisao* pColisao;
		MenuPausa menuPausa;
		Lista<Projetil> listaProjetil;
		Jogador* j1;
		Jogador* j2;
		vector<sf::FloatRect*> salas;
		int sala_Atual;

		virtual void inicializaElementos() = 0;

	public:
		Fase(Lista<Jogador>* listaJog);
		virtual ~Fase();

		virtual void criarMapa() = 0;
		virtual void apagarMapa() = 0;

		Lista<Jogador>* getListaJogadores();
		vector<Inimigo*>* getListaInimigos();
		list<Obstaculo*>* getListaObstaculos();
		void executar() = 0;
	};
} using namespace Fases;