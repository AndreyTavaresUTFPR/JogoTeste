#include "Jogo.h"


Jogo::Jogo() :
    pGrafico(pGrafico->getGerenciadorGrafico()),
    pEvento(pEvento->getGerenciadorEvento())
{
    sf::Vector2f tam(50.f, 50.f);
    jogador1 = new Jogador();
    jogador1->setBody(tam);
    fase1 = new FaseUm(jogador1);
    lPersonagens = fase1->getListaPersonagens();
    lObstaculos = fase1->getListaObstaculos();
   
    executar();
}


Jogo::~Jogo()
{

}

void Jogo::executar()
{
    //Conferir qual a fase a ser executada  
        pEvento->setListas(lPersonagens, lObstaculos);
        pEvento->executar();

}
