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
    for (int i = 0; i < n_jogadores; i++)
    {
        Jogador* temp = new Jogador();
        temp->getBody()->setPosition(50.f, 50.f);
        if (temp != nullptr)
            listaJogadores.push(temp);
    }
}

}

void Jogo::executar()
{
    pEvento->executarMenuPrincipal();
    if (menuPrincipal->getDoisJogadores())
        n_jogadores = 2;
    criarJogadores();
    //Conferir qual a fase a ser executada 
    
    criarFaseUm();

    pEvento->setListas(&listaJogadores, listaInimigos, listaObstaculos);
    pEvento->executar();
}
