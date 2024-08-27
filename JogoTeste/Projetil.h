#pragma once

#include <SFML/Graphics.hpp>
#include "Entidade.h"
#include "Jogador.h"

#define VELOCIDADE_PROJETIL_X 3.f
#define VELOCIDADE_PROJETIL_Y 0.f

class Projetil : public Entidade
{
private:
    sf::Vector2f vel;
    Jogador* pJogador;
    
public:
    Projetil(sf::Vector2f tam, Jogador* pJogador = nullptr);
    ~Projetil();
    void executar();
};

