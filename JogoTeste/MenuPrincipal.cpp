#include "MenuPrincipal.h"

MenuPrincipal* MenuPrincipal::pMenuPrincipal(nullptr);

MenuPrincipal::MenuPrincipal() :
    Menu(),
    iniciar(false),
    dois_jogadores(false)
{
    if (!font.loadFromFile("Font.ttf")) {
        cout << "ERRO AO CARREGAR FONTE" << endl;
    }

    titulo.setFont(font);
    titulo.setFillColor(sf::Color::Yellow);
    titulo.setString("MaisMaisMorra");
    titulo.setCharacterSize(100);
    titulo.setPosition(sf::Vector2f(largura / 2 - titulo.getLocalBounds().width / 2, 80.f));

    sf::Text* temp = new sf::Text();
    temp->setString("Iniciar Jogo");
    opcoes.push(temp);
    
    temp = new sf::Text();
    temp->setString("2 Jogadores");
    opcoes.push(temp);

    temp = new sf::Text();
    temp->setString("Escolher Fase");
    opcoes.push(temp);

    temp = new sf::Text();
    temp->setString("Carregar Jogo");
    opcoes.push(temp);

    temp = new sf::Text();
    temp->setString("Ranking");
    opcoes.push(temp);

    temp = new sf::Text();
    temp->setString("Sair");
    opcoes.push(temp);

    n_opcoes = opcoes.getLen();

    for (int i = 1; i < n_opcoes; i++)
    {
        temp = opcoes.getItem(i);
        temp->setFont(font);
        temp->setFillColor(sf::Color::White);
        temp->setPosition(sf::Vector2f(largura / 2 - temp->getLocalBounds().width / 2, (altura - 300.f) / (n_opcoes + 1) * (i + 1) + 250.f));
    }

    temp = opcoes.getItem(0);
    temp->setFont(font);
    temp->setFillColor(sf::Color::Cyan);
    temp->setCharacterSize(50);
    temp->setPosition(sf::Vector2f(largura / 2 - temp->getLocalBounds().width / 2, (altura - 300.f) / (n_opcoes + 1) + 245.f));
}

MenuPrincipal::~MenuPrincipal()
{

}

MenuPrincipal* MenuPrincipal::getMenuPrincipal()
{
    if (pMenuPrincipal == nullptr)
        pMenuPrincipal = new MenuPrincipal();
    return pMenuPrincipal;
}

void MenuPrincipal::voltarMenu()
{
    executar();
    iniciar = false;
}

bool MenuPrincipal::getIniciar() const
{
    return iniciar;
}

bool MenuPrincipal::getDoisJogadores() const {
    return dois_jogadores;
}

void MenuPrincipal::desenharMenu()
{
    pGrafico->limparJanela();
    pGrafico->desenharElemento(titulo);
    for (int i = 0; i < n_opcoes; i++)
        pGrafico->desenharElemento(*opcoes.getItem(i));
    pGrafico->mostrarElementos();
}

void MenuPrincipal::selecionarOpcao()
{
    if (opcaoSelecionada == 0) //Iniciar Jogo
    {
        dois_jogadores = false;
        iniciar = true;
        return;
    }
    else if (opcaoSelecionada == 1) //2 Jogadores
    {
        dois_jogadores = true;
        iniciar = true;
    }
    else if (opcaoSelecionada == 2) //Escolher Fase
        return;
    else if (opcaoSelecionada == 3) //Carregar Jogo
        return;
    else if (opcaoSelecionada == 4) //Ranking
        return;
    else if (opcaoSelecionada == 5) //Sair
        pGrafico->fecharJanela();
}

void MenuPrincipal::executar()
{
    pGrafico->reposicionar();
    while (iniciar == false && pGrafico->verificarJanela())
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
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    iniciar = false;
            }
            else if (evento.type == sf::Event::Closed)
                pGrafico->fecharJanela();
        }
    }
}