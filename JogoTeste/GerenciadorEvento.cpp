#include "GerenciadorEvento.h"

GerenciadorEvento* GerenciadorEvento::pEventos(NULL); // Atributo STATIC

GerenciadorEvento::GerenciadorEvento() :
    pGrafico(pGrafico->getGerenciadorGrafico()),
    pColisao(pColisao->getGerenciadorColisao()),
    listaJogadores(nullptr),
    listaInimigos(nullptr),
    listaObstaculos(nullptr),
    menuPrincipal(menuPrincipal->getMenuPrincipal())
{

}

GerenciadorEvento::~GerenciadorEvento()
{
    pGrafico = NULL;
}

GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento()
{
    if (pEventos == NULL)
        return new GerenciadorEvento();
    return pEventos;
}

void GerenciadorEvento::setListas(Lista<Jogador>* listaJog, Lista<Inimigo>* listaInim, Lista<Obstaculo>* listaObst)
{
    listaJogadores = listaJog;
    listaInimigos = listaInim;
    listaObstaculos = listaObst;
}

void GerenciadorEvento::verificaTeclaPressionada(sf::Keyboard::Key tecla)
{
    //TO DO: Implementar interações do usuario
}

void GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla)
{
    //TO DO: Implementar interações do usuário
}

void GerenciadorEvento::executarMenuPrincipal()
{
    menuPrincipal->executar();
}

void GerenciadorEvento::executarFaseUm()
{
    Entidade* temp = nullptr;
    int i = 0;
    while (pGrafico->verificarJanela())
    {
        sf::Event event;
        while (pGrafico->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                {
                    
                    return;
                }
            if (event.type == sf::Event::Closed)
                pGrafico->fecharJanela();
        }

        pGrafico->limparJanela();
        for (i = 0; i < listaJogadores->getLen(); i++) 
        {
            temp = static_cast<Entidade*>(listaJogadores->getItem(i));
            temp->executar();
            pGrafico->desenharElemento(*temp->getBody());
        }
        for (i = 0; i < listaInimigos->getLen(); i++)
        {
            temp = static_cast<Entidade*>(listaInimigos->getItem(i));
            temp->executar();
            pGrafico->desenharElemento(*temp->getBody());
        }
        for (i = 0; i < listaObstaculos->getLen(); i++) 
        {
            temp = static_cast<Entidade*>(listaObstaculos->getItem(i));
            temp->executar();
            pGrafico->desenharElemento(*temp->getBody());
        }
        pColisao->executar();
        pGrafico->mostrarElementos();
    }
}

void GerenciadorEvento::executar()
{
    //pColisao->setListas(listaJogadores, listaInimigos, listaObstaculos);
    while (pGrafico->verificarJanela())
    {
        executarMenuPrincipal();
        if (menuPrincipal->getIniciar())
            executarFaseUm();
    }
    
}