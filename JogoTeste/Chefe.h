#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#include "Jogador.h"
#include "ListaEntidades.h"
        
#define DELAY 4

class Chefe : public Inimigo
{
private:
    int tempo_ataque;
    sf::Clock delay;
    Jogador* pJogador;
    Lista<Projetil>* listaProjetil;


public:
    Chefe(Jogador* jogador, Lista<Projetil>* listaProjetil);
    ~Chefe();

    void atacarProjetil();
    void move();
    void executar();
    void liberarGravidade();
    void liberarMovimento();
    void mudarVelocidade(float fator);
    void danificar();
    void setJogador(Jogador* jogador);
    void setLProj(Lista<Projetil>* listaProjetil);
};
