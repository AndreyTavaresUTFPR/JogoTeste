#pragma once
#include <SFML/Graphics.hpp>


namespace Entidades {
	class Entidade
	{
	protected:
		sf::RectangleShape body;
		//sf::RenderWindow* window; O atributo window e os metodos relacionados nao estao sendo utilizados

	public:
		Entidade();
		virtual ~Entidade();

		sf::RectangleShape getBody();
		virtual void setBody(sf::Vector2f tam);
		//void setWindow(sf::RenderWindow* w);
		//void draw();

		virtual void executar() = 0;
	};

} using namespace Entidades;