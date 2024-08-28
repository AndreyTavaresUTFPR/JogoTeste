#pragma once
#include "Obstaculo.h"
#define DANO_ESPINHOS true
#define SOLIDEZ_ESPINHOS true

namespace Obstaculos {
	class Espinhos : public Obstaculo 
	{
	private:
		int dano;

	public:
		Espinhos();
		~Espinhos();

		void setBody(sf::Vector2f pos);
		void obstacular(Jogador* pJog);
		void obstacular(Inimigo* pInim);
		void executar();
	};

} using namespace Obstaculos;