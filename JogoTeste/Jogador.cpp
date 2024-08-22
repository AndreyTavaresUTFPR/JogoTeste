#include "Jogador.h"


Jogador::Jogador():
    Personagem()
{
    vel.x = VEL_JOGADOR_X;
    vel.y = VEL_JOGADOR_Y;
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
        body.move(sf::Vector2f(0, -vel.x));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && esquerda) { // para esquerda
        body.move(sf::Vector2f(-vel.x, 0));
        if (body.getPosition().x < 0.f)
            body.setPosition(sf::Vector2f(0.f, body.getPosition().y));
        direita = true;
    }
    if (cair) {
        body.move(sf::Vector2f(0.f, 9.8f/2.f * timer.getElapsedTime().asSeconds() * timer.getElapsedTime().asSeconds()));
    }
    else
        timer.restart();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && direita) { // para direita
        body.move(sf::Vector2f(vel.x, 0));
        if (body.getPosition().x > 750.f)
            body.setPosition(sf::Vector2f((800.f - body.getSize().x), body.getPosition().y));
        esquerda = true;
    }
  
}

void Personagens::Jogador::executar()
{
    move();
}
