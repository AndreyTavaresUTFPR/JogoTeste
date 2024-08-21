#include "GerenciadorEvento.h"

GerenciadorEvento* GerenciadorEvento::pEventos(NULL); // Atributo STATIC

GerenciadorEvento::GerenciadorEvento() :
    pGrafico(pGrafico->getGerenciadorGrafico()), listaPersonagens(nullptr), listaObstaculos(nullptr)
{
    pColisao = new GerenciadorColisao();
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
    Entidade* ent;
    for (int i = 0; i < listaPersonagens->LEs.getLen(); i++)
    {
        ent = listaPersonagens->LEs.getItem(i);
        ent->executar();
    }
}

void GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla)
{
    //TO DO: Implementar interações do usuário
}

void GerenciadorEvento::executarMenu()
{
    menujogo.desenharMenu();
}

void GerenciadorEvento::executarFase()
{
    while (pGrafico->verificarJanela())
    {
        sf::Event event;
        while (pGrafico->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                {
                    menujogo.voltarMenu();
                    return;
                }
            if (event.type == sf::Event::Closed)
                    pGrafico->fecharJanela();
        }

        pGrafico->limparJanela();
        for (int i = 0; i < listaPersonagens->LEs.getLen(); i++) 
        {
            Entidade* temp = listaPersonagens->LEs.getItem(i);
            temp->executar();
            pGrafico->desenharElemento(temp->getBody());
        }
        for (int i = 0; i < listaObstaculos->LEs.getLen(); i++) 
        {
            Entidade* temp = listaObstaculos->LEs.getItem(i);
            temp->executar();
            pGrafico->desenharElemento(temp->getBody());
        }
        pColisao->executar();
        pGrafico->mostrarElemento();
    }
}

void GerenciadorEvento::executar()
{
    pColisao->setListas(listaPersonagens, listaObstaculos);
    while (pGrafico->verificarJanela())
    {
        executarMenu();
        if (menujogo.getIniciar())
            executarFase();
    }
    
}