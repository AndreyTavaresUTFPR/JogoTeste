#include "Jogo.h"
#include <iostream>
using namespace std;


Jogo::Jogo() :
    pGrafico(pGrafico->getGerenciadorGrafico()), pEvento(pEvento->getGerenciadorEvento())
{
    temp = nullptr;
    
    jogador1 = new Jogador();
    jogador1->setWindow(pGrafico->getWindow());
    fase1 = new Fase(jogador1, pGrafico->getWindow());
    LEs = fase1->getListaEntidades();
   
    executar();
}


Jogo::~Jogo()
{
    temp = nullptr;
}

void Jogo::executar()
{
    pEvento->setJogador(jogador1);
    pEvento->setLista(LEs);
    pEvento->executar();

}
