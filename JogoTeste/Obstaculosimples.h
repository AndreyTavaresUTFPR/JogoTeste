#pragma once
#include "Obstaculo.h"

namespace Obstaculos {
	class Obstaculosimples : public Obstaculo
	{
	private:

	public:
		Obstaculosimples();
		~Obstaculosimples();

		void setBody();
		void executar();
	};
} using namespace Obstaculos;