#pragma once
#include "Personagem.h"
#include <SFML/Graphics.hpp>

#define VEL_JOGADOR_X 1.f
#define VEL_JOGADOR_Y 1.2f


namespace Personagens {
    class Jogador : public Personagem
    {
    private:
        sf::Clock tempo_queda;
        sf::Clock tempo_andando;
        static int n_players;
        int player;
        int pontuacao;

    public:
        Jogador();
        ~Jogador();

        void setBody(sf::Vector2f tam);
        void mudarVelocidade(float fator);
        void empurrar(bool esquerda);
        void ganharPontos(int pontos);
        void move();
        void executar();
    };
} using namespace Personagens;
