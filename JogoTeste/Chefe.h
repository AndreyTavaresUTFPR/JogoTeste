#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#include "ListaJogadores.h"
#include "ListaEntidades.h"
        
#define DELAY 4

class Chefe : public Inimigo
{
private:
    int tempo_ataque;
    sf::Clock delay;
    ListaJogadores* listaJogadores;
    Jogador* pJogador;
    Lista<Projetil>* listaProjetil;


public:
    Chefe();
    ~Chefe();

    void atacarProjetil();
    void move();
    void executar();
    void liberarGravidade();
    void liberarMovimento();
    void mudarVelocidade(float fator);
    void setJogador(Jogador* jogador);
    void setLProj(Lista<Projetil>* listaProjetil);
};
