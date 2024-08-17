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

void Jogador::setBody(sf::Vector2f tam)
{
    sf::RectangleShape b(tam);
    body = b;
    body.setPosition(0.f, 0.f);
}

// Move o jogardor
void Jogador::move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { // para cima
        body.move(sf::Vector2f(0, -vel.y));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { // para esquerda
        body.move(sf::Vector2f(-vel.x, 0));
    }
    if (cair) {
        body.move(sf::Vector2f(0, 9.8 * timer.getElapsedTime().asSeconds() * timer.getElapsedTime().asSeconds()));
    }
    else
        timer.restart();
    
        /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { // para baixo
        body.move(sf::Vector2f(0, vel.y));
    }*/
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { // para direita
        body.move(sf::Vector2f(vel.x, 0));
    }
  
}

void Personagens::Jogador::executar()
{
    move();
}
