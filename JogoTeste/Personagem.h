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
		};

} using namespace Personagens;