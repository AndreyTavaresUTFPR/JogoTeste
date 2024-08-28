#include "MenuPausa.h"

MenuPausa::MenuPausa() :
    Menu(), pausar(false), voltarInicio(false)
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
    temp->setFont(font);
    temp->setString("Continuar");
    temp->setFillColor(sf::Color::Cyan);
    temp->setCharacterSize(50);
    opcoes.push(temp);

    temp = new sf::Text();
    temp->setFont(font);
    temp->setString("Voltar ao Menu");
    temp->setFillColor(sf::Color::White);
    opcoes.push(temp);

    n_opcoes = opcoes.getLen();

    for (int i = 0; i < n_opcoes; i++)
    {
        temp = opcoes.getItem(i);
        temp->setPosition(sf::Vector2f(largura / 2 - temp->getLocalBounds().width / 2, (altura - 300.f) / (n_opcoes + 1) * (i + 1) + 150.f));
    }


}

MenuPausa::~MenuPausa()
{

}

bool MenuPausa::getPausa() const
{
    return pausar;
}

bool MenuPausa::getVoltarInicio() const
{
    return voltarInicio;
}

void MenuPausa::desenharMenu()
{
    pGrafico->limparJanela();
    pGrafico->desenharElemento(titulo);
    for (int i = 0; i < n_opcoes; i++)
        pGrafico->desenharElemento(*opcoes.getItem(i));
    pGrafico->mostrarElementos();
}

void MenuPausa::selecionarOpcao()
{
    if (opcaoSelecionada == 0) //Continuar o Jogo
        pausar = false;
    else if (opcaoSelecionada == 1) //Voltar ao Menu Principal
    {
        pausar = false;
        voltarInicio = true;
    }
    //Poderia ser implementado uma opção 'Reiniciar Fase'
}

void MenuPausa::executar()
{
    pausar = true;
    while (pausar)
    {
        desenharMenu();
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
            }
            else if (evento.type == sf::Event::Closed)
                pGrafico->fecharJanela();
            if (!pausar)
                return;
        }

    }
}