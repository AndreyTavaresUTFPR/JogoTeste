#pragma once
#include "Personagem.h"
#include <SFML/Graphics.hpp>

#define VEL_JOGADOR_X 0.15f
#define VEL_JOGADOR_Y 0.15f


namespace Personagens {
    class Jogador : public Personagem
    {
    private:
        sf::Clock timer;
        int player;

    public:
        Jogador(int player);
        ~Jogador();

        void setBody(sf::Vector2f tam);
        void move();
        void executar();
    };
} using namespace Personagens;
