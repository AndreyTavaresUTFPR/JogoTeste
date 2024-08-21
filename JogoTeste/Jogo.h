#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "Menu.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "Fase.h"

class Jogo
{
private:	
	GerenciadorGrafico* pGrafico;
	GerenciadorEvento* pEvento;
	Jogador* jogador1;
	ListaEntidades* LEs1;
	ListaEntidades* LEs2;
	Fase* fase1;

public:
	Jogo();
	~Jogo();

	void executar();
};

