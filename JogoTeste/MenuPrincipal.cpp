#include "MenuPrincipal.h"

MenuPrincipal* MenuPrincipal::pMenuPrincipal(nullptr);

MenuPrincipal::MenuPrincipal() :
    Menu(),
    iniciar(false),
    dois_jogadores(false),
    fase_selecionada(0)
{
    atualizarTextura("../Imagens/BackgroundMenuPrincipal.png");

    if (!font.loadFromFile("Font.ttf")) {
        cout << "ERRO AO CARREGAR FONTE" << endl;
    }

    titulo.setFont(font);
    titulo.setFillColor(sf::Color::Yellow);
    titulo.setString("MaisMaisMorra");
    titulo.setCharacterSize(100);
    titulo.setPosition(sf::Vector2f(largura / 2 - titulo.getLocalBounds().width / 2, 80.f));

    sf::Text* temp = new sf::Text();
    temp->setString("1 Jogador");
    opcoes.push(temp);
    
    temp = new sf::Text();
    temp->setString("2 Jogadores");
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
    delete pMenuPrincipal;
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

bool MenuPrincipal::getDoisJogadores() const 
{
    return dois_jogadores;
}

int MenuPrincipal::getFaseSelecionada() const
{
    return fase_selecionada;
}

void MenuPrincipal::desenharMenu()
{
    pGrafico->limparJanela();
    desenhar();
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
        selecionarFase(); 
    }
    else if (opcaoSelecionada == 1) //2 Jogadores
    {
        dois_jogadores = true;
        selecionarFase();
    }
    else if (opcaoSelecionada == 2) //Carregar Jogo
        return;
    else if (opcaoSelecionada == 3) //Ranking
        return;
    else if (opcaoSelecionada == 4) //Sair
        pGrafico->fecharJanela();
        
}

void MenuPrincipal::selecionarFase()
{
    int opcao = 1;

    sf::Text texto1;
    texto1.setFillColor(sf::Color::Cyan);
    texto1.setCharacterSize(50);
    texto1.setString("Fase Um");
    texto1.setFont(font);
    texto1.setPosition(sf::Vector2f(largura / 2 - texto1.getLocalBounds().width / 2, 400.f));

    sf::Text texto2;
    texto2.setFillColor(sf::Color::White);
    texto2.setCharacterSize(30);
    texto2.setString("Fase Dois");
    texto2.setFont(font);
    texto2.setPosition(sf::Vector2f(largura / 2 - texto1.getLocalBounds().width / 2, 600.f));

    
    while (!iniciar && pGrafico->verificarJanela())
    {
        sf::Event evento;
        if (pGrafico->getWindow()->pollEvent(evento))
        {
            if (evento.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    iniciar = true;
                    if (opcao == 1)
                        fase_selecionada = 1;
                    else if (opcao == 2)
                        fase_selecionada = 2;
                    return;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && opcao == 2)
                {
                    texto1.setFillColor(sf::Color::Cyan);
                    texto1.setCharacterSize(50);
                    texto1.setPosition(sf::Vector2f(largura / 2 - texto1.getLocalBounds().width / 2, texto1.getPosition().y));

                    texto2.setFillColor(sf::Color::White);
                    texto2.setCharacterSize(30);
                    texto2.setPosition(sf::Vector2f(largura / 2 - texto2.getLocalBounds().width / 2, texto2.getPosition().y));

                    opcao--;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && opcao == 1)
                {
                    texto1.setFillColor(sf::Color::White);
                    texto1.setCharacterSize(30);
                    texto1.setPosition(sf::Vector2f(largura / 2 - texto1.getLocalBounds().width / 2, texto1.getPosition().y));

                    texto2.setFillColor(sf::Color::Cyan);
                    texto2.setCharacterSize(50);
                    texto2.setPosition(sf::Vector2f(largura / 2 - texto2.getLocalBounds().width / 2, texto2.getPosition().y));

                    opcao++;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    iniciar = false;
                    return;
                }
            }
            else if (evento.type == sf::Event::Closed)
                pGrafico->fecharJanela();
        }
        pGrafico->limparJanela();
        desenhar();
        pGrafico->desenharElemento(titulo);
        pGrafico->desenharElemento(texto1);
        pGrafico->desenharElemento(texto2);
        pGrafico->mostrarElementos();
        
    }
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