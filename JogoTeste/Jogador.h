#pragma once
#include "Personagem.h"
#include <SFML/Graphics.hpp>

#define VEL_JOGADOR_X 2.5f
#define VEL_JOGADOR_Y 2.5f
#define VIDA_JOGADOR 10

namespace Personagens {
    class Jogador : public Personagem
    {
    private:
        sf::Clock tempo_queda;
        sf::Clock tempo_pulo;
        static int n_players;
        int player;
        int pontuacao;
        bool pulando;

    public:
        Jogador();
        ~Jogador();

        void setBody(sf::Vector2f tam);
        void mudarVelocidade(float fator);
        void empurrar(bool esquerda);
        void ganharPontos(int pontos);
        void setPulando();
        void pular();
        void reviver();
        void move();
        void executar();
    };
} using namespace Personagens;
