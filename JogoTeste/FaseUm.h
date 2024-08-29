#pragma once
#include "Fase.h"
#include "Esqueleto.h"
#include "Aranha.h"
#include "Chefe.h"
#include "Solo.h"
#include "Teia.h"
#include "Espinhos.h"
#include "MenuPausa.h"

namespace Fases {
	class FaseUm : public Fase
	{
	private:
		Jogador* j1;
		Jogador* j2;
		Esqueleto* e1;
		Esqueleto* e2;
		Aranha* a1;
		Solo* solo1;
		Teia* obst1;
		Teia* obst2;
		Espinhos* obst3;
		Chefe* mago;

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
		void executar();
	};
} using namespace Fases;