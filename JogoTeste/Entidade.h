#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.h"


namespace Entidades {
	class Entidade : public Ente
	{
	protected:


	public:
		Entidade();
		virtual ~Entidade();

		sf::RectangleShape* getBody();
		virtual void setBody(sf::Vector2f tam);
		sf::Vector2f getCentro();

		virtual void executar() = 0;
	};

} using namespace Entidades;