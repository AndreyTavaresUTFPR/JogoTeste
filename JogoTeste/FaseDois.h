#pragma once
#include "Fase.h"
#include "Esqueleto.h"
#include "Aranha.h"
#include "Solo.h"
#include "Espinhos.h"
#include "Gelo.h"
#include "MenuPausa.h"

namespace Fases {
	class FaseDois : public Fase
	{
	private:
		int n_esqueletos;
		int n_aranhas;
		int n_espinhos;
		int n_gelos;

	public:
		FaseDois();
		FaseDois(Lista<Jogador>* listaJog);
		~FaseDois();

		void criarInimigosFaceis();
		void criarInimigosMedios();
		void criarObstaculosMedios();
		void criarObstaculosDificeis();
		void criarTerreno();

		void criarFase();
		void apagarFase();
		bool verificarFim();
		bool mudouSala();
		void atualizarFundo();
		void executar();
	};
} using namespace Fases;