#include "Jogo.h"


Jogo::Jogo() :
    pGrafico(pGrafico->getGerenciadorGrafico()),
    pEvento(pEvento->getGerenciadorEvento())
{
    sf::Vector2f tam(30.f, 50.f);
    jogador1 = new Jogador();
    jogador1->setBody(tam);
    jogador2 = new Jogador();
    jogador2->setBody(tam);
    fase1 = new FaseUm(jogador1, jogador2);
    jogador1->getBody().setPosition(50.f, 0.f);
    jogador2->getBody().setPosition(50.f, 0.f);
    listaJogadores = fase1->getListaJogadores();
    listaInimigos = fase1->getListaInimigos();
    listaObstaculos = fase1->getListaObstaculos();
   
    executar();
}


Jogo::~Jogo()
{

}

void Jogo::executar()
{
    //Conferir qual a fase a ser executada  
        pEvento->setListas(listaJogadores, listaInimigos, listaObstaculos);
        pEvento->executar();

}
