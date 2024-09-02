#pragma once
#include "GerenciadorGrafico.h"
#include <ctime>
#include <Windows.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

class Ente 
{
protected:
	GerenciadorGrafico* pGrafico;
	sf::Texture textura;
	sf::RectangleShape body;
	static int n_entes;
	int id;

public:
	Ente();
	~Ente();

	void atualizarTextura(const std::string& caminho);
	virtual void setBody(sf::Vector2f tam);
	sf::RectangleShape* getBody();
	virtual void executar() = 0;
	void desenhar();
};