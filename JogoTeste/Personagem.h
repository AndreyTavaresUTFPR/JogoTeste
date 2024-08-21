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
			virtual void executar() = 0; 
		};
} using namespace Personagens;