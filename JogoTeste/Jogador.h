#pragma once
#include "Personagem.h"
#include <SFML/Graphics.hpp>

#define VEL_JOGADOR_X 0.15f
#define VEL_JOGADOR_Y 0.2f


namespace Personagens {
    class Jogador : public Personagem
    {
    private:
        sf::Clock timer;
        static int n_players;
        int player;

    public:
        Jogador();
        ~Jogador();

        void setBody(sf::Vector2f tam);
        void mudarVelocidade(float fator);
        void move();
        void executar();
    };
} using namespace Personagens;
