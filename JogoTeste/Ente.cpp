#include "Ente.h"

Ente::Ente() :
	pGrafico(pGrafico->getGerenciadorGrafico()), textura()
{

}

Ente::~Ente()
{

}

void Ente::setBody(sf::Vector2f tam)
{
	sf::RectangleShape b(tam);
	body = b;
}

sf::RectangleShape* Ente::getBody()
{
	return &body;
}

void Ente::atualizarTextura(const std::string& caminho)
{
	if (!this->textura.loadFromFile(caminho))
		cout << "Erro ao carregar textura" << endl;
	else
		this->body.setTexture(&textura);
}