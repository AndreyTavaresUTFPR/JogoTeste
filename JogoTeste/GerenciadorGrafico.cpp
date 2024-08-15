#include "GerenciadorGrafico.h"

GerenciadorGrafico* GerenciadorGrafico::pGrafico(NULL);

GerenciadorGrafico::GerenciadorGrafico() :
	janela(new sf::RenderWindow(sf::VideoMode(600, 600), "Jogo"))
{

}

GerenciadorGrafico::~GerenciadorGrafico()
{
	if (janela != NULL)
	{
		delete janela;
		janela = NULL;
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

sf::RenderWindow* GerenciadorGrafico::getJanela()
{
	return janela;
}

void GerenciadorGrafico::limparJanela()
{
	janela->clear();
}

void GerenciadorGrafico::desenharElemento(sf::RectangleShape corpo)
{
	janela->draw(corpo);
}

void GerenciadorGrafico::mostrarElemento()
{
	janela->display();
}

void GerenciadorGrafico::fecharJanela()
{
	janela->close();
}

const bool GerenciadorGrafico::verificarJanela()
{
	if (janela->isOpen())
		return true;
	else
		return false;
}