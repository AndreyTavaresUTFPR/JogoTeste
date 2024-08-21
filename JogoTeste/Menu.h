#pragma once
#include <SFML/Graphics.hpp>
#include "Lista.h"
#include "GerenciadorGrafico.h"
#include <iostream>
using namespace std;

namespace Menus{
	class Menu {
	protected:
		int n_opcoes;
		sf::Font font;
		sf::Text titulo;
		sf::Text opcoes[3];
		float altura;
		float largura;
		int opcaoSelecionada;
		
		GerenciadorGrafico* pGrafico;

	public:
		Menu();
		virtual ~Menu();

		virtual void desenharMenu();
		virtual void opcaoAcima();
		virtual void opcaoAbaixo();
		virtual void selecionarOpcao();
		virtual void voltarMenu();
		virtual void executar();
	};
} using namespace Menus;