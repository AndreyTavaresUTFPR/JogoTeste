#pragma once
#include "Fase.h"
#include "Esqueleto.h"
#include "Aranha.h"
#include "Solo.h"
#include "Teia.h"

namespace Fases {
	class FaseUm : public Fase
	{
	private:
		Esqueleto* e1;
		Esqueleto* e2;
		Aranha* a1;
		Solo* solo1;
		Teia* obst1;
		Teia* obst2;

		void inicializaElementos();
	public:
		FaseUm(Jogador* j1, Jogador* j2);
		~FaseUm();

		void executar();
		void criarMapa();
	};
} using namespace Fases;