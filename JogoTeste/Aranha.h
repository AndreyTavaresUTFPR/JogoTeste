#pragma once
#include "Inimigo.h"
#include "Jogador.h"

#define VEL_ARANHA_PULO 2.f  
#define VEL_ARANHA_X 2.f
#define VIDA_ARANHA 1

class Aranha :
    public Inimigo
{
private:
    bool paraEsquerda;
    bool peconhenta; //Aranhas peconhentas dão o dobro de dano

public:
    Aranha();
    ~Aranha();

    void setBody(sf::Vector2f tam);
    void mudarVelocidade(float fator); 
    void danificar(Jogador* pJog);

    void move();
    void executar();
};

