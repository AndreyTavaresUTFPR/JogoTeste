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

		void setWindow(sf::RenderWindow* w);
		void draw();
	};

} using namespace Entidades;