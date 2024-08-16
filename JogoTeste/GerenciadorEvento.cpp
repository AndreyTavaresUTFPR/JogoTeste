#include "GerenciadorEvento.h"

GerenciadorEvento* GerenciadorEvento::pEventos(NULL);

GerenciadorEvento::GerenciadorEvento() :
    pGrafico(pGrafico->getGerenciadorGrafico())
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

void GerenciadorEvento::setLista(ListaEntidades* lista)
{
    pLista = lista;
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
        for (int i = 0; i < pLista->LEs.getLen(); i++) {
            Entidade* temp = pLista->LEs.getItem(i); //Pensar em como usar .at(i) para fazer isso, se for possível
            temp->executar();
            pGrafico->desenharElemento(temp->getBody());
        }
        pGrafico->mostrarElemento();
    }
}