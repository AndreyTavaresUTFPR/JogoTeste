#include "Jogador.h"


Jogador::Jogador():
    Personagem(), vel(0.1f, 0.1f)
{
}

Jogador::~Jogador()
{
}

// Move o jogardor
void Jogador::move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { // para cima
        body.move(sf::Vector2f(0, -vel.y));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { // para direita
        body.move(sf::Vector2f(-vel.x, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { // para baixo
        body.move(sf::Vector2f(0, vel.y));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { // para esquerda
        body.move(sf::Vector2f(vel.x, 0));
    }
  
}
