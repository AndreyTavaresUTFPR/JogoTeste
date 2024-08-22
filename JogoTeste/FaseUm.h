#pragma once
#include "Fase.h"
#include "Esqueleto.h"
#include "Aranha.h"
#include "Solo.h"
#include "Obstaculodiferente.h"

namespace Fases {
	class FaseUm : public Fase
	{
	private:
		Esqueleto* e1;
		Aranha* a1;
		Solo* solo1;
		Obstaculodiferente* obst1;

		void inicializaElementos();
	public:
		FaseUm(Jogador* j1);
		~FaseUm();

	};
} using namespace Fases;