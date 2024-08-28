#pragma once
#include "SFML/Graphics.hpp"
#include "Obstaculo.h"
#define DANO false
#define SOLIDEZ false
#define LENTIDAO_TEIA 0.1f

namespace Obstaculos {
	class Teia : public Obstaculo 
	{
	private:
		float lentidao;

	public:
		Teia();
		~Teia();

		void setBody(sf::Vector2f pos);
		void obstacular(Jogador* pJog);
		void obstacular(Inimigo* pInim);
		void executar();
	};

} using namespace Obstaculos;