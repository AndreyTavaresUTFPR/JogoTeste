#pragma once

#include <SFML/Graphics.hpp>
#include "Entidade.h"
#include "Jogador.h"

#define VELOCIDADE_PROJETIL_X 3.f
#define VELOCIDADE_PROJETIL_Y 0.5f
#define TEMPO_DE_VIDA 20

class Projetil : public Entidade
{
private:
    sf::Vector2f vel;
    Jogador* pJogador;
    int time_vivo;
    
public:
    Projetil(sf::Vector2f tam,  sf::Vector2f pos, Jogador* pJogador);
    ~Projetil();
    void executar();
};

