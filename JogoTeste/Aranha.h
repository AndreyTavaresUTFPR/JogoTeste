#pragma once
#include "Inimigo.h"

#define VELOCIDADE_PULO -0.15f  //Diminui o pulo da aranha para ficar mais facil acompanhar
#define VELOCIDADE_HORIZONTAL -0.1f


class Aranha :
    public Inimigo
{
private:
    sf::Vector2f pulo;
    sf::Clock timer_gravidade;

public:
    Aranha();
    ~Aranha();

    void pular();

    void move();
    void executar();

    void setBody(sf::Vector2f tam);
};

