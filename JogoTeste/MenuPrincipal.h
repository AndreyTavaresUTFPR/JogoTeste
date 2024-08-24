#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"


namespace Menus {
	class MenuPrincipal : public Menu 
	{
	private:
		bool iniciar;
		bool dois_jogadores;

	public:
		MenuPrincipal();
		~MenuPrincipal();
		
		static MenuPrincipal* getMenuPrincipal();
		void voltarMenu();
		bool getIniciar() const;
		bool getDoisJogadores() const;
		void desenharMenu();
		void opcaoAcima();
		void opcaoAbaixo();
		void selecionarOpcao();
		void executar();
	};
} using namespace Menus;