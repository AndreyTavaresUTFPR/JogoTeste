#include "Jogo.h"


Jogo::Jogo() :
    pGrafico(pGrafico->getGerenciadorGrafico()),
    pEvento(pEvento->getGerenciadorEvento())
{
    sf::Vector2f tam(50.f, 50.f);
    jogador1 = new Jogador();
    jogador1->setBody(tam);
    fase1 = new FaseUm(jogador1);
    LEs1 = fase1->getListaPersonagens();
    LEs2 = fase1->getListaObstaculos();
   
    executar();
}


Jogo::~Jogo()
{

}

void Jogo::executar()
{
    //Conferir qual a fase a ser executada  
        pEvento->setListaPersonagens(LEs1);
        pEvento->setListaObstaculos(LEs2);
        pEvento->executar();

}
