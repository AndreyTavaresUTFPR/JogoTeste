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
		
		void desenharMenu();
		void opcaoAcima();
		void opcaoAbaixo();
		void selecionarOpcao();
		void voltarMenu();
		bool getIniciar();
		void executar();
		bool getDoisJogadores() const;

	};
} using namespace Menus;