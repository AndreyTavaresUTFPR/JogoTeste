#include "Inimigo.h"


Inimigo::Inimigo():
	Personagem(), nivel_maldade(0)
{
	tipo = 2;
	relogio.restart();
}

Inimigo::Inimigo(int vida) :
	Personagem(vida), nivel_maldade(0)
{
	tipo = 2;
	relogio.restart();
}

Inimigo::~Inimigo()
{

}
