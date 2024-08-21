#pragma once
#include "Obstaculo.h"

namespace Obstaculos {
	class Solo : public Obstaculo
	{
	private:

	public:
		Solo();
		~Solo();

		void setBody();
		void executar();
	};
} using namespace Obstaculos;