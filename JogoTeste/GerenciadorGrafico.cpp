#include "GerenciadorGrafico.h"

GerenciadorGrafico* GerenciadorGrafico::pGrafico(nullptr);

GerenciadorGrafico::GerenciadorGrafico()
{
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Jogo");
}

GerenciadorGrafico::~GerenciadorGrafico()
{
	if (window != nullptr)
	{
		delete window;
		window = nullptr;
	}
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
{
	if (pGrafico == nullptr)
	{
		pGrafico = new GerenciadorGrafico();
	}
	return pGrafico;
}

sf::RenderWindow* GerenciadorGrafico::getWindow()
{
	return window;
}

void GerenciadorGrafico::limparJanela()
{
	window->clear();
}

void GerenciadorGrafico::desenharMenu(sf::Text text[], int nMenus)
{
	
}

void GerenciadorGrafico::desenharElemento(sf::RectangleShape corpo)
{
	window->draw(corpo);
}

void GerenciadorGrafico::desenharElemento(sf::Text& text)
{
	window->draw(text);
}

void GerenciadorGrafico::mostrarElementos()
{
	window->display();
}

void GerenciadorGrafico::fecharJanela()
{
	window->close();
}

bool GerenciadorGrafico::verificarJanela() const
{
	return (window->isOpen());
}