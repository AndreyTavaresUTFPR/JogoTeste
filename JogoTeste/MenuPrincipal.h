#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"


namespace Menus {
	class MenuPrincipal : public Menu 
	{
	private:
		bool iniciar;
		bool dois_jogadores;
		int fase_selecionada;

		static MenuPrincipal* pMenuPrincipal;
		MenuPrincipal();
	public:
		~MenuPrincipal();
		
		static MenuPrincipal* getMenuPrincipal();
		void voltarMenu();
		bool getIniciar() const;
		bool getDoisJogadores() const;
		int getFaseSelecionada() const;
		void desenharMenu();
		void selecionarOpcao();
		void selecionarFase();
		void executar();
	};
} using namespace Menus;   