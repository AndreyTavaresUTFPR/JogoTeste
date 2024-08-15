#include "Jogo.h"
#include <iostream>
using namespace std;


Jogo::Jogo() :
    window(sf::VideoMode(WIDTH, HEIGHT), "Jogo")
{
    temp = nullptr;
    
    jogador1 = new Jogador();
    jogador1->setWindow(&window);
    fase1 = new Fase(jogador1, &window);
    LEs = fase1->getListaEntidades();
   
    executar();
}


Jogo::~Jogo()
{
    temp = nullptr;
}

void Jogo::executar()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /*
        for (int i = 0; i < LEs->LEs.getLen(); i++){ // Executa todas as entidades
            temp = LEs->LEs.getItem(i);
            temp->executar();
        }*/

        window.clear();
        for (int i = 0; i < LEs->LEs.getLen(); i++) { 
            temp = LEs->LEs.getItem(i); // pensar em como usar .at(i) para fazer isso, se for possivel
            temp->executar();
            temp->draw();
        }

        window.display();
    }
}
