#pragma once
#include "Obstaculo.h"

namespace Obstaculos {
	class Solo : public Obstaculo
	{
	private:

	public:
		Solo();
		~Solo();

		void setBody(sf::Vector2f tam);
		void obstacular(Jogador* pJog);
		void obstacular(Inimigo* pInim);
		void executar();
	};
} using namespace Obstaculos;