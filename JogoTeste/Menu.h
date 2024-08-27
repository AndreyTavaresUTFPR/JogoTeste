#pragma once
#include "Ente.h"
#include <SFML/Graphics.hpp>
#include "Lista.h"
#include "GerenciadorGrafico.h"
#include <iostream>
using namespace std;

namespace Menus {
	class Menu : public Ente {
	protected:
		sf::Font font;
		sf::Text titulo;
		Lista<sf::Text> opcoes;
		int n_opcoes;
		int opcaoSelecionada;
		float altura;
		float largura;

	public:
		Menu();
		virtual ~Menu();

		void opcaoAcima();
		void opcaoAbaixo();
		virtual void desenharMenu() = 0;
		virtual void selecionarOpcao() = 0;
		virtual void executar() = 0;
	};
} using namespace Menus;