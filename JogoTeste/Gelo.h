#pragma once
#include "Obstaculo.h"

namespace Obstaculos {
	class Gelo : public Obstaculo
	{
	private:
		float lisura;

	public:
		Gelo();
		~Gelo();

		void setBody(sf::Vector2f tam);
		void obstacular(Jogador* pJog);
		void obstacular(Inimigo* pInim);
		void executar();
	};
} using namespace Obstaculos;