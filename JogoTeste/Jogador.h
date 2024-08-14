#pragma once
#include "Entidade.h"
#include <SFML/Graphics.hpp>


class Jogador : public Entidade
{
private:
       sf::Vector2f vel;

public:
    Jogador();
    ~Jogador();


    void move();
};

