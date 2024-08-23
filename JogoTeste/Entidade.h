#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.h"


namespace Entidades {
	class Entidade : public Ente
	{
	protected:
		sf::RectangleShape body;
		bool cair;
		bool esquerda;
		bool direita;

	public:
		Entidade();
		virtual ~Entidade();

		void liberarGravidade();
		void liberarMovimento();
		sf::RectangleShape getBody();
		virtual void setBody(sf::Vector2f tam);
		sf::Vector2f getCentro();

		void conferirColisao(sf::Vector2f colisao, sf::Vector2f centroOutraEnt);
		virtual void executar() = 0;
	};

} using namespace Entidades;