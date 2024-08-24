#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"


namespace Menus {
	class MenuPrincipal : public Menu 
	{
	private:
		bool iniciar;
		bool dois_jogadores;

		static MenuPrincipal* pMenuPrincipal;
		MenuPrincipal();
	public:
		~MenuPrincipal();
		
		static MenuPrincipal* getMenuPrincipal();
		void desenharMenu();
		void selecionarOpcao();
		void voltarMenu();
		bool getIniciar();
		void executar();
		bool getDoisJogadores() const;

	};
} using namespace Menus;