#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.h"


namespace Entidades {
	class Entidade : public Ente
	{
	protected:
		int tipo; // 1 - Jogador, 2 - Inimigo ou 3 - Obstaculo
		bool noJogo;

	public:
		Entidade();
		virtual ~Entidade();

		int getTipo() const;
		bool getNoJogo() const;
		sf::RectangleShape* getBody();
		virtual void setBody(sf::Vector2f tam);
		sf::Vector2f getCentro() const;
		

		virtual void executar() = 0;
	};

} using namespace Entidades;