#pragma once
#include "SFML/Graphics.hpp"
#include "Obstaculo.h"

namespace Obstaculos {
	class Teia : public Obstaculo 
	{
	private:
		float lentidao;

	public:
		Teia();
		~Teia();

		void setBody(sf::Vector2f pos);
		void executar();
	};

} using namespace Obstaculos;