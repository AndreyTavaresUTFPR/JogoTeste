#pragma once
#include "Entidade.h"
#include "Jogador.h"
#include "Inimigo.h"

namespace Obstaculos {
	class Obstaculo : public Entidade
	{
	protected:
		bool danoso;
		bool solido;

	public:
		Obstaculo();
		Obstaculo(bool dano, bool solidez);
		virtual ~Obstaculo();

		virtual void obstacular(Jogador* pJog) = 0;
		virtual void obstacular(Inimigo* pInim) = 0;
		bool ehSolido() const;
		virtual void executar() = 0;
	};
} using namespace Obstaculos;

