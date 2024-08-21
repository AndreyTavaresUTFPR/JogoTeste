#include "Menu.h"

Menu::Menu() :
    altura(800.f),
    largura(800.f),
    opcaoSelecionada(0),
    n_opcoes(3),
    pGrafico(pGrafico->getGerenciadorGrafico())
{

}

Menu::~Menu()
{

}

void Menu::desenharMenu()
{
    pGrafico->getWindow()->clear();
    pGrafico->getWindow()->draw(titulo);
    pGrafico->desenharMenu(opcoes, n_opcoes);
}

void Menu::opcaoAcima()
{
    if (opcaoSelecionada > 0)
    {
        opcoes[opcaoSelecionada].setFillColor(sf::Color::White);
        opcaoSelecionada--;
        opcoes[opcaoSelecionada].setFillColor(sf::Color::Red);
    }
}

void Menu::opcaoAbaixo()
{
    if (opcaoSelecionada < n_opcoes - 1)
    {
        opcoes[opcaoSelecionada].setFillColor(sf::Color::White);
        opcaoSelecionada++;
        opcoes[opcaoSelecionada].setFillColor(sf::Color::Red);
    }
}

void Menu::selecionarOpcao()
{
    
}

void Menu::voltarMenu()
{

}



void Menu::executar()
{
    
}

