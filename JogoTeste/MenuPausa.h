#pragma once
#include "Menu.h"

namespace Menus {
	class MenuPausa: public Menu 
	{
	private:
		bool pausar;

	public:
		MenuPausa();
		~MenuPausa();

		bool getPausa() const;
		void desenharMenu();
		void selecionarOpcao();
		void executar();
	};
}