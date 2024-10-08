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
    Lista<Jogador>* listaJogadores;
    Jogador* pJogador;
    Lista<Projetil>* listaProjetil;


public:
    Chefe();
    ~Chefe();

    void setBody(sf::Vector2f tam);
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
