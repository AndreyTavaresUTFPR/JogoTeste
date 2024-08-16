#include "Jogo.h"


Jogo::Jogo() :
    pGrafico(pGrafico->getGerenciadorGrafico()), pEvento(pEvento->getGerenciadorEvento())
{
    // temp = nullptr;
    sf::Vector2f tam(50.f, 50.f);
    jogador1 = new Jogador();
    jogador1->setBody(tam);
    //jogador1->setWindow(pGrafico->getWindow());
    fase1 = new Fase(jogador1, pGrafico->getWindow());
    LEs1 = fase1->getListaPersonagens();
    LEs2 = fase1->getListaObstaculos();
   
    executar();
}


Jogo::~Jogo()
{
    // temp = nullptr;
}

void Jogo::executar()
{
    pEvento->setJogador(jogador1);
    pEvento->setListaPersonagens(LEs1);
    pEvento->setListaObstaculos(LEs2);
    pEvento->executar();

}
