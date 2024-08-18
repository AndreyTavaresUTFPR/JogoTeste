#pragma once
#include <SFML/Graphics.hpp>


namespace Entidades {
	class Entidade
	{
	protected:
		sf::RectangleShape body;

	public:
		Entidade();
		virtual ~Entidade();

		bool cair;
		bool esquerda;
		bool direita;

		sf::RectangleShape getBody();
		virtual void setBody(sf::Vector2f tam);

		void conferirColisao(sf::Vector2f colisao, Entidade* outraEnt);
		virtual void executar() = 0;
	};

} using namespace Entidades;