#pragma once
#include "Fase.h"
#include "Esqueleto.h"
#include "Aranha.h"
#include "Solo.h"
#include "Teia.h"
#include "Gelo.h"
#include "MenuPausa.h"

namespace Fases {
	class FaseUm : public Fase
	{
	private:
		int n_esqueletos;
		int n_aranhas;
		int n_teias;
		int n_gelos;

	public:
		FaseUm();
		FaseUm(Lista<Jogador>* listaJog);
		~FaseUm();

		void criarInimigosFaceis();
		void criarInimigosMedios();
		void criarObstaculosFaceis();
		void criarObstaculosMedios();
		void criarTerreno();

		void criarFase();
		void apagarFase();
		bool verificarFim();
		bool mudouSala();
		void atualizarFundo();
		void executar();
	};
} using namespace Fases;