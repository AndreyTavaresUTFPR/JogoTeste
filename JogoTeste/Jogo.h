#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"
#include "MenuPrincipal.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "FaseUm.h"
#include "FaseDois.h"

class Jogo
{
private:
	GerenciadorGrafico* pGrafico;
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