#include "Menu.h"

Menu::Menu() :
    Ente(),
    font(),
    titulo(),
    opcoes(),
    n_opcoes(0),
    opcaoSelecionada(0),
    altura(HEIGHT),
    largura(WIDTH)
{
    setBody(sf::Vector2f(800.f, 800.f));
}

Menu::~Menu()
{

}

void Menu::opcaoAcima()
{
    if (opcaoSelecionada > 0)
    {
        sf::Text* temp = opcoes.getItem(opcaoSelecionada);
        temp->setFillColor(sf::Color::White);
        temp->setCharacterSize(30);
        temp->setPosition(sf::Vector2f(largura / 2 - temp->getLocalBounds().width / 2, temp->getPosition().y));
        opcaoSelecionada--;
        temp = opcoes.getItem(opcaoSelecionada);
        temp->setFillColor(sf::Color::Cyan);
        temp->setCharacterSize(50);
        temp->setPosition(sf::Vector2f(largura / 2 - temp->getLocalBounds().width / 2, temp->getPosition().y));
    }
}

void Menu::opcaoAbaixo()
{
    if (opcaoSelecionada < n_opcoes - 1)
    {
        sf::Text* temp = opcoes.getItem(opcaoSelecionada);
        temp->setFillColor(sf::Color::White);
        temp->setCharacterSize(30);
        temp->setPosition(sf::Vector2f(largura / 2 - temp->getLocalBounds().width / 2, temp->getPosition().y));
        opcaoSelecionada++;
        temp = opcoes.getItem(opcaoSelecionada);
        temp->setFillColor(sf::Color::Cyan);
        temp->setCharacterSize(50);
        temp->setPosition(sf::Vector2f(largura / 2 - temp->getLocalBounds().width / 2, temp->getPosition().y));
    }
}