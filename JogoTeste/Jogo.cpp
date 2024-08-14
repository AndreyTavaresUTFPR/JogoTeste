#include "Jogo.h"


Jogo::Jogo() :
    window(sf::VideoMode(800, 800), "SFML works!"),
    shape(sf::Vector2f(100.f, 100.f))
{
    shape.setFillColor(sf::Color::Green);
    shape.setOutlineThickness(21);
    shape.setOutlineColor(sf::Color::Cyan);
    executar();
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            shape.move(sf::Vector2f(0.2f, 0.1f));
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

