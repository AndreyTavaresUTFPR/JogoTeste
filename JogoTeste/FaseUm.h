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
		int n_esqueletos;
		int n_aranhas;
		int n_teias;
		int n_gelos;

	public:
		FaseUm(Lista<Jogador>* listaJog);
		~FaseUm();

		void criarInimigosFaceis();
		void criarInimigosMedios();
		void criarObstaculosFaceis();
		void criarObstaculosMedios();
		void criarTerreno();

		void criarMapa();
		void apagarMapa();
		bool verificarFim();
		bool mudouSala();
		void atualizarFundo();
		void executar();
	};
} using namespace Fases;