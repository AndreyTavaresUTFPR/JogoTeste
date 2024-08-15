#pragma once
#include <SFML/Graphics.hpp>


namespace Entidades {
	class Entidade
	{
	protected:
		sf::RectangleShape body;
		sf::RenderWindow* window;

	public:
		Entidade();
		virtual ~Entidade();

		const sf::RectangleShape getBody();
		void setWindow(sf::RenderWindow* w);
		void draw();

		virtual void executar() = 0;
	};

} using namespace Entidades;