#pragma once
#include <SFML/Graphics.hpp>

namespace Gerenciadores {
	class GerenciadorGrafico
	{
	private:
		sf::RenderWindow* janela;


		static GerenciadorGrafico* pGrafico;
		GerenciadorGrafico();

	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico* getGerenciadorGrafico();
		sf::RenderWindow* getJanela();
		void limparJanela();
		void desenharElemento(sf::RectangleShape corpo);
		void mostrarElemento();
		void fecharJanela();
		const bool verificarJanela();
	};
} using namespace Gerenciadores;