#pragma once
#include "Entidade.h"

namespace Obstaculos {
	class Obstaculo : public Entidade
	{
	protected:
		bool danoso;
		bool solido;

	public:
		Obstaculo(bool dano, bool solidez);
		virtual ~Obstaculo();

		virtual void executar() = 0;
	};
} using namespace Obstaculos;

