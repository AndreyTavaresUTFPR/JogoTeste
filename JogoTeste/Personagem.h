#pragma once
#include "Entidade.h"


namespace Personagens {
		class Personagem : public Entidade
		{
		protected:
			sf::Vector2f vel;	//Velocidade Personagem
			float alteracaoVel; //Caso haja alteração na velocidade do personagem, esse valor acumula...
			sf::Clock tempo_queda;
			int vida;
			bool cair;
			bool esquerda;
			bool direita;

		public:
			Personagem();
			Personagem(int vida);
			~Personagem();

			void conferirColisao(sf::Vector2f colisao, sf::Vector2f centroOutraEnt);
			void operator--();
			int getVida() const;
			virtual void mudarVelocidade(float fator) = 0;
			virtual void move() = 0;
			virtual void executar() = 0; 
		};
} using namespace Personagens;