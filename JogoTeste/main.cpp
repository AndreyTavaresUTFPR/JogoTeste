#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::RectangleShape shape(sf::Vector2f(100.f, 100.f));


    shape.setFillColor(sf::Color::Green);
    shape.setOutlineThickness(21); 
    shape.setOutlineColor(sf::Color::Cyan);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();

    }

    return 0;
}