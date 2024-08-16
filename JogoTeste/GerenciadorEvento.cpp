#include "GerenciadorEvento.h"

GerenciadorEvento* GerenciadorEvento::pEventos(NULL); // Atributo STATIC

GerenciadorEvento::GerenciadorEvento() :
    pGrafico(pGrafico->getGerenciadorGrafico()), pJogador(nullptr), listaPersonagens(nullptr), listaObstaculos(nullptr)
{
}

GerenciadorEvento::~GerenciadorEvento()
{
    pGrafico = NULL;
    pJogador = NULL;
}

GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento()
{
    if (pEventos == NULL)
        return new GerenciadorEvento();
    return pEventos;
}

void GerenciadorEvento::setJogador(Jogador* pJog)
{
    pJogador = pJog;
}

void GerenciadorEvento::setListaPersonagens(ListaEntidades* lista)
{
    listaPersonagens = lista;
}

void GerenciadorEvento::setListaObstaculos(ListaEntidades* lista)
{
    listaObstaculos = lista;
}

void GerenciadorEvento::verificaTeclaPressionada(sf::Keyboard::Key tecla)
{
    //TO DO: Implementar interações do usuário
}

void GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla)
{
    //TO DO: Implementar interações do usuário
}

void GerenciadorEvento::executar()
{
    while (pGrafico->verificarJanela())
    {
        sf::Event event;
        while (pGrafico->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGrafico->fecharJanela();
        }

        pGrafico->limparJanela();
        for (int i = 0; i < listaPersonagens->LEs.getLen(); i++) {
            Entidade* temp = listaPersonagens->LEs.getItem(i); //Pensar em como usar .at(i) para fazer isso, se for possível
            temp->executar();
            pGrafico->desenharElemento(temp->getBody());
        }
        for (int i = 0; i < listaObstaculos->LEs.getLen(); i++) {
            Entidade* temp = listaObstaculos->LEs.getItem(i);
            temp->executar();
            pGrafico->desenharElemento(temp->getBody());
        }
        pGrafico->mostrarElemento();
    }
}