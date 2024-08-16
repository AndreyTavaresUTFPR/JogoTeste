#pragma once
#include "Entidade.h"

namespace Obstaculos {
	class Obstaculo : public Entidade
	{
	protected:
		bool danoso;
	public:
		Obstaculo(bool dano);
		~Obstaculo();

		virtual void executar() = 0;
	};
} using namespace Obstaculos;

