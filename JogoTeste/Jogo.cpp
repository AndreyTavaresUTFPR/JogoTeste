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
    for (int i = listaJogadores.getLen(); i < n_jogadores; i++)
    {
        Jogador* temp = new Jogador();
        temp->getBody()->setPosition(50.f, 50.f);
        if (temp != nullptr)
            listaJogadores.push(temp);
    }
}

void Jogo::criarFaseUm()
{
    fase1 = new FaseUm(&listaJogadores);
    fase1->executar();
    delete fase1;
    pGrafico->limparJanela();
}

void Jogo::executar()
{
    while (pGrafico->verificarJanela())
    {
        menuPrincipal->executar();
        if (menuPrincipal->getDoisJogadores())
            n_jogadores = 2;
        criarJogadores();
        //Conferir qual a fase a ser executada 

        criarFaseUm();
        menuPrincipal->voltarMenu();
    }
}