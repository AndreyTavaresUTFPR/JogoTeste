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

		void setBody();
		void executar();
	};

} using namespace Obstaculos;