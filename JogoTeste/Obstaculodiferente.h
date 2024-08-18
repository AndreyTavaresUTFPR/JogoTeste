#pragma once
#include "SFML/Graphics.hpp"
#include "Obstaculo.h"


namespace Obstaculos {
	class Obstaculodiferente : public Obstaculo 
	{
	private:
	
	public:
		Obstaculodiferente();
		~Obstaculodiferente();

		void setBody();
		void executar();
	};

} using namespace Obstaculos;