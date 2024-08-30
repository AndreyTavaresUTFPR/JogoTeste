#pragma once
#include "Inimigo.h"
#include "Jogador.h"

#define VEL_ARANHA_PULO 0.5f  //Diminui o pulo da aranha para ficar mais facil acompanhar
#define VEL_ARANHA_X 0.5f
#define VIDA_ARANHA 5

class Aranha :
    public Inimigo
{
private:
    bool paraEsquerda;
    bool peconhenta;

public:
    Aranha();
    ~Aranha();

    void setBody(sf::Vector2f tam);
    void mudarVelocidade(float fator); 
    void danificar(Jogador* pJog);

    void pular();

    void move();
    void executar();
};

