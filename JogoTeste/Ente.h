#pragma once
#include "GerenciadorGrafico.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

class Ente 
{
protected:
	GerenciadorGrafico* pGrafico;
	sf::Texture textura;
	sf::RectangleShape body;
	//int id;

public:
	Ente();
	~Ente();

	void atualizarTextura(sf::Texture texture);
	virtual void setBody(sf::Vector2f tam);
	sf::RectangleShape* getBody();
	virtual void executar() = 0;
	//virtual void desenhar() = 0;
};