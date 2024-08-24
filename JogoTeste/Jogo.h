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
	int n_jogadores;
	Lista<Jogador> listaJogadores;
	Lista<Inimigo>* listaInimigos;
	Lista<Obstaculo>* listaObstaculos;
	FaseUm* fase1;
	MenuPrincipal* menuPrincipal;

public:
	Jogo();
	~Jogo();

	void criarJogadores();
	void criarFaseUm();
	void executar();
};

