#include "Jogo.h"


Jogo::Jogo() :
    window(sf::VideoMode(600, 600), "Jogo")
{
    jogador1.setWindow(&window);
    inimigo1.setWindow(&window);
    executar();
}

Jogo::~Jogo()
{
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

        jogador1.move();
        window.clear();
        jogador1.draw();
        inimigo1.draw();
        window.display();
    }
}

