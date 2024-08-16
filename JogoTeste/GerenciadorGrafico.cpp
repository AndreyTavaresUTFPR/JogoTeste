#include "GerenciadorGrafico.h"

GerenciadorGrafico* GerenciadorGrafico::pGrafico(NULL);

GerenciadorGrafico::GerenciadorGrafico() :
	window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Jogo"))
{

}

GerenciadorGrafico::~GerenciadorGrafico()
{
	if (window != NULL)
	{
		delete window;
		window = NULL;
	}
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
{
	if (pGrafico == NULL)
	{
		return new GerenciadorGrafico();

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

void GerenciadorGrafico::desenharElemento(sf::RectangleShape corpo)
{
	window->draw(corpo);
}

void GerenciadorGrafico::mostrarElemento()
{
	window->display();
}

void GerenciadorGrafico::fecharJanela()
{
	window->close();
}

const bool GerenciadorGrafico::verificarJanela()
{
	return (window->isOpen()); // Mais simples!
}