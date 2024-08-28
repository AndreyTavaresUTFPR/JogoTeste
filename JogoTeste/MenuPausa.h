#pragma once
#include "Menu.h"

namespace Menus {
	class MenuPausa : public Menu
	{
	private:
		bool pausar;
		bool voltarInicio;

	public:
		MenuPausa();
		~MenuPausa();

		bool getPausa() const;
		bool getVoltarInicio() const;
		void desenharMenu();
		void selecionarOpcao();
		void executar();
	};
}