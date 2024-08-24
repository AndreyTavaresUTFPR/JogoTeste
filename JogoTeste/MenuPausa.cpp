#include "MenuPausa.h"

MenuPausa::MenuPausa() :
	Menu(), pausar(false)
{
    if (!font.loadFromFile("Font.ttf")) {
        cout << "ERRO AO CARREGAR FONTE" << endl;
    }

    titulo.setFont(font);
    titulo.setFillColor(sf::Color::Yellow);
    titulo.setString("Pausado");
    titulo.setCharacterSize(100);
    titulo.setPosition(sf::Vector2f(largura / 2 - titulo.getLocalBounds().width / 2, 80.f));

    sf::Text* temp = new sf::Text();
    temp->setString("Continuar");
    temp->setFillColor(sf::Color::Red);
    opcoes.push(temp);

    temp = new sf::Text();
    temp->setString("Voltar ao Menu");
    temp->setFillColor(sf::Color::White);
    opcoes.push(temp);

    n_opcoes = opcoes.getLen();

    for (int i = 0; i < n_opcoes; i++)
    {
        temp = opcoes.getItem(i);
        temp->setPosition(sf::Vector2f(largura / 2 - temp->getLocalBounds().width / 2, (altura - 300.f) / (n_opcoes + 1) * (i + 1) + 250.f));
    }

}

MenuPausa::~MenuPausa()
{

}

bool MenuPausa::getPausa() const
{
	return pausar;
}

void MenuPausa::desenharMenu()
{
    pGrafico->limparJanela();
    pGrafico->getWindow()->draw(titulo);
    for (int i = 0; i < n_opcoes; i++)
        pGrafico->desenharElemento(*opcoes.getItem(i));
    pGrafico->mostrarElementos();
}

void MenuPausa::selecionarOpcao()
{

}

void MenuPausa::executar()
{

}