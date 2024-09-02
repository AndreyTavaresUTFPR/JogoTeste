#pragma once
#include "Obstaculo.h"
#include "Lista.h"

namespace Obstaculos {
	class Solo : public Obstaculo
	{
	private:
		const char* tipo_plataforma;
		static Lista<sf::Texture> texturasPlataforma;

	public:
		Solo();
		Solo(const char* tipo);
		~Solo();

		void setBody(sf::Vector2f tam);
		void obstacular(Jogador* pJog);
		void obstacular(Inimigo* pInim);
		void executar();
	};
} using namespace Obstaculos;