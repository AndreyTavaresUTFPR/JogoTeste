#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "Menu.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "FaseUm.h"

class Jogo
{
private:	
	GerenciadorGrafico* pGrafico;
	GerenciadorEvento* pEvento;
	Jogador* jogador1;
	Jogador* jogador2;
	Lista<Jogador>* listaJogadores;
	Lista<Inimigo>* listaInimigos;
	Lista<Obstaculo>* listaObstaculos;
	FaseUm* fase1;

public:
	Jogo();
	~Jogo();

	void executar();
};

