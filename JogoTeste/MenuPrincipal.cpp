#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal() :
    Menu(), 
    iniciar(false)
{


    if (!font.loadFromFile("Font.ttf")) {
        cout << "ERRO AO CARREGAR FONTE" << endl;
    }

    titulo.setFont(font);
    titulo.setFillColor(sf::Color::Yellow);
    titulo.setString("Titulo do Jogo");
    titulo.setPosition(sf::Vector2f(largura / 2 - titulo.getLocalBounds().width / 2, 100.f));

    opcoes[0].setFont(font);
    opcoes[0].setFillColor(sf::Color::Red); // A primeira opção está selecionada inicialmente
    opcoes[0].setString("Iniciar Jogo");
    opcoes[0].setPosition(sf::Vector2f(largura / 2 - opcoes[0].getLocalBounds().width / 2, altura / (n_opcoes + 1)));

    opcoes[1].setFont(font);
    opcoes[1].setFillColor(sf::Color::White);
    opcoes[1].setString("2 Jogadores");
    opcoes[1].setPosition(sf::Vector2f(largura / 2 - opcoes[1].getLocalBounds().width / 2, altura / (n_opcoes + 1) * 2));

    opcoes[2].setFont(font);
    opcoes[2].setFillColor(sf::Color::White);
    opcoes[2].setString("Sair");
    opcoes[2].setPosition(sf::Vector2f(largura / 2 - opcoes[2].getLocalBounds().width / 2, altura / (n_opcoes + 1) * 3));

}

MenuPrincipal::~MenuPrincipal()
{

}

void MenuPrincipal::desenharMenu()
{
    pGrafico->getWindow()->clear();
    pGrafico->getWindow()->draw(titulo);
    pGrafico->desenharMenu(opcoes, n_opcoes);
}

void MenuPrincipal::opcaoAcima()
{
    if (opcaoSelecionada > 0)
    {
        opcoes[opcaoSelecionada].setFillColor(sf::Color::White);
        opcaoSelecionada--;
        opcoes[opcaoSelecionada].setFillColor(sf::Color::Red);
    }
}

void MenuPrincipal::opcaoAbaixo()
{
    if (opcaoSelecionada < n_opcoes - 1)
    {
        opcoes[opcaoSelecionada].setFillColor(sf::Color::White);
        opcaoSelecionada++;
        opcoes[opcaoSelecionada].setFillColor(sf::Color::Red);
    }
}

void MenuPrincipal::selecionarOpcao()
{
    if (opcaoSelecionada == 0) //Iniciar Jogo
    {
        iniciar = true;
    }
    else if (opcaoSelecionada == 1) //2 Jogadores
    {
    }
    else if (opcaoSelecionada == 2) //Sair
        pGrafico->fecharJanela();
}

void MenuPrincipal::voltarMenu()
{
    iniciar = false;
}

bool MenuPrincipal::getIniciar()
{
    executar();
    return iniciar;
}

void MenuPrincipal::executar()
{
    sf::Event evento;
    if (pGrafico->getWindow()->pollEvent(evento))
    {
        if (evento.type == sf::Event::KeyPressed)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                selecionarOpcao();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                opcaoAcima();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                opcaoAbaixo();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                iniciar = false;
        }
        else if (evento.type == sf::Event::Closed())
            pGrafico->fecharJanela();
    }
}