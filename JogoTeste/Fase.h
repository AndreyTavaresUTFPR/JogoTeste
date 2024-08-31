#pragma once
#include "Ente.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Projetil.h"
#include "GerenciadorColisao.h"
#include "MenuPausa.h"
#include <SFML/Graphics.hpp>

namespace Fases {
	class Fase : public Ente
	{
	protected:
		ListaEntidades listaEntidades;
		Lista<Jogador>* listaJogadores;
		GerenciadorColisao* pColisao;
		MenuPausa menuPausa; //Menu de Pausa da fase
		vector<sf::FloatRect*> salas; //Regiões da tela onde a fase acontece
		int sala_Atual; //Região da tela onde os jogadores estão

	public:
		Fase(Lista<Jogador>* listaJog);
		virtual ~Fase();

		virtual void criarFase() = 0; //Cria terreno, Inimigos e Obstáculos
		virtual void apagarFase() = 0; //Destroi terreno, Inimigos e Obstáculos
		virtual bool verificarFim() = 0; //Verifica se algum jogador chegou ao fim da fase;

		void incluirElementosColisao(); //Inclui os elementos no Gerenciador de Colisao
		virtual void executar() = 0;
	};
} using namespace Fases;