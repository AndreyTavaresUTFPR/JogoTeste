#pragma once
#include "Personagem.h"

namespace Personagens {
	class Inimigo : public Personagem
	{
	private:
		int vida;
	public:
		Inimigo();
		~Inimigo();
	};
} using namespace Personagens;