#include "Jogo.h"


Jogo::Jogo() :
    pGrafico(pGrafico->getGerenciadorGrafico()),
    pEvento(pEvento->getGerenciadorEvento()),
    n_jogadores(1),
    listaJogadores(),
    menuPrincipal(menuPrincipal->getMenuPrincipal())
{
   
    executar();
}


Jogo::~Jogo()
{

}

void Jogo::criarJogadores()
{
    sf::Vector2f tamJogador(50.f, 50.f);
    for (int i = 0; i < n_jogadores; i++)
    {
        Jogador* temp = new Jogador();
        temp->getBody()->setPosition(sf::Vector2f(30.f, 30.f));
        if (temp != nullptr)
            listaJogadores.push(temp);
    }
}

void Jogo::criarFaseUm()
{
    fase1 = new FaseUm(&listaJogadores);
    listaInimigos = fase1->getListaInimigos();
    listaObstaculos = fase1->getListaObstaculos();
}

void Jogo::executar()
{
    pEvento->executarMenuPrincipal(menuPrincipal);
    if (menuPrincipal->getDoisJogadores())
        n_jogadores = 2;
    criarJogadores();
    //Conferir qual a fase a ser executada  

    criarFaseUm();

    pEvento->setListas(&listaJogadores, listaInimigos, listaObstaculos);
    pEvento->executar();

}
