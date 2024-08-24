#pragma once
#include "Obstaculo.h"
#define DANO true
#define SOLIDEZ true

namespace Obstaculos {
	class Espinhos : public Obstaculo 
	{
	private:
		int dano;

	public:
		Espinhos();
		~Espinhos();

		void setBody(sf::Vector2f pos);
		void afetarPersonagem(Jogador* pJog);
		void afetarPersonagem(Inimigo* pInim);
		void executar();
	};

} using namespace Obstaculos;