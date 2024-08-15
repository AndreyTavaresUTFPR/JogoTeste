#pragma once
#include "Entidade.h"


namespace Personagens {
		class Personagem : public Entidade
		{
		protected:
			int vida;
		public:
			Personagem();
			~Personagem();

			virtual void move() = 0;
			virtual void executar() = 0; // Não sei se é necessario, pois ja esta na classe Entidade
		};

} using namespace Personagens;