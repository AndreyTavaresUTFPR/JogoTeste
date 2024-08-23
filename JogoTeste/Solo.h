#pragma once
#include "Obstaculo.h"

namespace Obstaculos {
	class Solo : public Obstaculo
	{
	private:

	public:
		Solo();
		~Solo();

		void setBody(sf::Vector2f tam, sf::Vector2f pos);
		void executar();
	};
} using namespace Obstaculos;