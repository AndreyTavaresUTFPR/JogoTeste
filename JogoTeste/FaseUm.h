#pragma once
#include "Fase.h"
#include "Esqueleto.h"
#include "Aranha.h"
#include "Chefe.h"
#include "Solo.h"
#include "Teia.h"
#include "Espinhos.h"
#include "Gelo.h"
#include "MenuPausa.h"

namespace Fases {
	class FaseUm : public Fase
	{
	private:
		Jogador* j1;
		Jogador* j2;
		Aranha* a1;
		Espinhos* obst3;
		Gelo* obst4;

		MenuPausa pausa;

		void inicializaElementos();
	public:
		FaseUm(Lista<Jogador>* listaJog);
		~FaseUm();

		void criarInimigosFaceis();
		void criarInimigosMedios();
		void criarObstaculosFaceis();
		void criarObstaculosMedios();
		void criarTerreno1();
		void criarTerreno2();

		void criarMapa();
		void apagarMapa();
		void atualizarFundo();
		bool verificarFim();
		void executar();
	};
} using namespace Fases;