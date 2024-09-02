#include "GerenciadorGrafico.h"

GerenciadorGrafico* GerenciadorGrafico::pGrafico(nullptr);

GerenciadorGrafico::GerenciadorGrafico():
	cameraInicial(sf::FloatRect(0.f, 0.f, 800.f, 800.f))
{
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Jogo");
	window->setFramerateLimit(60);
}

GerenciadorGrafico::~GerenciadorGrafico()
{
	if (window != nullptr)
	{
		delete window;
		window = nullptr;
	}
	delete pGrafico;
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

void GerenciadorGrafico::reposicionar()
{
	window->setView(cameraInicial);
}

void GerenciadorGrafico::limparJanela()
{
	window->clear();
}

void GerenciadorGrafico::desenharElemento(sf::RectangleShape corpo)
{
	window->draw(corpo);
}

void GerenciadorGrafico::desenharElemento(sf::Text texto)
{
	window->draw(texto);
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