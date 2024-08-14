#include "Jogador.h"


Jogador::Jogador():
    Entidade()
{
}

Jogador::~Jogador()
{
}


void Jogador::move()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        body.move(sf::Vector2f(0.2f, 0.1f));
    }
}
