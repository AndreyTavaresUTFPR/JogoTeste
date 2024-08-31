#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "Menu.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "FaseUm.h"
#include "FaseDois.h"

class Jogo
{
private:
	GerenciadorGrafico* pGrafico;
	GerenciadorEvento* pEvento;
	int n_jogadores;
	Lista<Jogador> listaJogadores;
	FaseUm* fase1;
	FaseDois* fase2;
	MenuPrincipal* menuPrincipal;

public:
	Jogo();
	~Jogo();

	void criarJogadores();
	void executarFaseUm();
	void executarFaseDois();
	void executar();
};