#pragma once
#include "Entidade.h"
#include <SFML/Graphics.hpp>


class Jogador : public Entidade
{
private:
public:
    Jogador();
    ~Jogador();


    void move();
};

