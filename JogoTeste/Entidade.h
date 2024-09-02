#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.h"


namespace Entidades {
	class Entidade : public Ente
	{
	protected:
		int tipo; // 1 - Jogador, 2 - Inimigo ou 3 - Obstaculo
		bool noJogo;
		sf::Vector2f centro; //Posição central da Entidade

	public:
		Entidade();
		virtual ~Entidade();

		int getTipo() const;
		bool getNoJogo() const;
		sf::Vector2f getCentro();
		
		virtual void executar() = 0;
	};

} using namespace Entidades;