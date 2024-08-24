#pragma once
#include <SFML/Graphics.hpp>

#define WIDTH  800
#define HEIGHT 800


namespace Gerenciadores {
	class GerenciadorGrafico
	{
	private:
		sf::RenderWindow* window;


		static GerenciadorGrafico* pGrafico;
		GerenciadorGrafico();

	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico* getGerenciadorGrafico();
		sf::RenderWindow* getWindow();
		void limparJanela();
		void desenharMenu(sf::Text text[], int nMenus);
		void desenharElemento(sf::RectangleShape corpo);
		void desenharElemento(sf::Text& text);
		void mostrarElementos();
		void fecharJanela();
		bool verificarJanela() const;
	};
} using namespace Gerenciadores;