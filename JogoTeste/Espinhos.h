#pragma once
#include "Obstaculo.h"

namespace Obstaculos {
	class Espinhos : public Obstaculo 
	{
	private:
		bool muitosEspinhos;

	public:
		Espinhos();
		~Espinhos();

		void setBody(sf::Vector2f tam);
		void obstacular(Jogador* pJog);
		void obstacular(Inimigo* pInim);
		void executar();
	};

} using namespace Obstaculos;