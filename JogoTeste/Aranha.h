#pragma once
#include "Inimigo.h"

#define VELOCIDADE_PULO -3.F
#define VELOCIDADE_HORIZONTAL 0.25f


class Aranha :
    public Inimigo
{
private:
    sf::Vector2f pulo;
    sf::Clock timer_pulo;
    sf::Clock timer_gravide;

public:
    Aranha();
    ~Aranha();

    void move();
    void executar();

    void setBody(sf::Vector2f tam);
};

