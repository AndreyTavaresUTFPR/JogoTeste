#pragma once
#include "Personagem.h"
#include <SFML/Graphics.hpp>

namespace Personagens {
    class Jogador : public Personagem
    {
    private:
        sf::Vector2f vel;

    public:
        Jogador();
        ~Jogador();


        void move();
    };
} using namespace Personagens;
