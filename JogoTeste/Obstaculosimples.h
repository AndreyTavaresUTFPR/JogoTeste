#pragma once
#include "Obstaculo.h"

//COMENTARIO TESTE

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