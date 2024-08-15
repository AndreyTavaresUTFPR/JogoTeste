#include "Jogador.h"

#define VEL_JOGADOR_X 0.15f
#define VEL_JOGADOR_Y 0.15f


Jogador::Jogador():
    Personagem(), vel(VEL_JOGADOR_X, VEL_JOGADOR_Y)
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

void Personagens::Jogador::executar()
{
    move();
}
