#include "Jogo.h"


Jogo::Jogo() :
    pGrafico(pGrafico->getGerenciadorGrafico()),
    n_jogadores(1),
    listaJogadores(),
    menuPrincipal(menuPrincipal->getMenuPrincipal())
{
    executar();
}


Jogo::~Jogo()
{
    for (int i = 0; i < listaJogadores.getLen(); i++)
        delete listaJogadores.getItem(i);
}

void Jogo::criarJogadores()
{
    Jogador* aux = nullptr;
    for (int i = listaJogadores.getLen(); i < n_jogadores; i++)
    {
        aux = new Jogador();
        if (aux != nullptr)
        {
            aux->getBody()->setPosition(50.f, 50.f);
            listaJogadores.push(aux);
        }
    }
    if (n_jogadores == 1 && listaJogadores.getLen() == 2)
    {
        aux = listaJogadores.getItem(1);
        listaJogadores.pop(listaJogadores.getItem(1));
        delete aux;
    }
    for (int i = 0; i < listaJogadores.getLen(); i++)
    {
        listaJogadores.getItem(i)->reviver();
    }

}

void Jogo::executarFaseUm()
{
    fase1 = new FaseUm(&listaJogadores);
    fase1->executar();
    delete fase1;
    pGrafico->limparJanela();
}

void Jogo::executarFaseDois()
{
    fase2 = new FaseDois(&listaJogadores);
    fase2->executar();
    delete fase2;
    pGrafico->limparJanela();
}

void Jogo::executar()
{
    while (pGrafico->verificarJanela())
    {
        menuPrincipal->executar();
        if (menuPrincipal->getDoisJogadores())
            n_jogadores = 2;
        else
            n_jogadores = 1;
        criarJogadores();
        
        if (menuPrincipal->getFaseSelecionada() == 1)
            executarFaseUm();
        else if (menuPrincipal->getFaseSelecionada() == 2)
            executarFaseDois();
        menuPrincipal->voltarMenu();
    }
}