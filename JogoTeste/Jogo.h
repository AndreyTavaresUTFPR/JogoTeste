#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
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
	// Entidade* temp; // Ponteiro temporario auxiliar (SEM USO)
	int lenLEs;     // tamanho da lista de entidades

public:
	Jogo();
	~Jogo();

	void executar();
};

