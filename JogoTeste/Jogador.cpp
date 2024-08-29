#include "Jogador.h"

int Jogador::n_players(1);

Jogador::Jogador() :
    Personagem(), player(n_players++)
{
    vel.x = VEL_JOGADOR_X;
    vel.y = VEL_JOGADOR_Y;
    setBody(sf::Vector2f(30.f, 60.f));
    if (player == 2)
        body.setFillColor(sf::Color::Cyan);
    atualizarTextura("../Imagens/JogadorD.png");
}

Jogador::~Jogador()
{
    Jogador::n_players--;
}

void Jogador::liberarGravidade()
{
    cair = true;
    vel.y = VEL_JOGADOR_Y;
}

void Jogador::liberarMovimento()
{
    esquerda = true;
    direita = true;
    vel.x = VEL_JOGADOR_X;
}

void Jogador::setBody(sf::Vector2f tam)
{
    sf::RectangleShape b(tam);
    body = b;
}

void Jogador::mudarVelocidade(float fator)
{
    vel.x = VEL_JOGADOR_X * fator;
    vel.y = VEL_JOGADOR_Y * fator;
}

void Jogador::ganharPontos(int pontos)
{
    pontuacao += pontos;
}

// Move o jogardor
void Jogador::move()
{
    if (player == 1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && esquerda) // andar para a Esquerda
        {
            body.move(sf::Vector2f(-vel.x, 0));
            atualizarTextura("../Imagens/JogadorE.png");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && direita)  // andar para a Direita
        {
            body.move(sf::Vector2f(vel.x, 0));
            atualizarTextura("../Imagens/JogadorD.png");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // Pular
        {
            body.move(sf::Vector2f(0, -vel.y));
        }
        if (cair) // Caindo
        {
            body.move(sf::Vector2f(0.f, 9.8f / 2.f * tempo_queda.getElapsedTime().asSeconds() * tempo_queda.getElapsedTime().asSeconds()));
            if (body.getPosition().y > 800.f - body.getSize().y)
            {
                cair = false;
                body.setPosition(sf::Vector2f(body.getPosition().x, 775 - body.getSize().y));
            }

        }
        else
            tempo_queda.restart();
    }

    if (player == 2) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { // para cima
            body.move(sf::Vector2f(0, -vel.y));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && esquerda) { // para esquerda
            body.move(sf::Vector2f(-vel.x, 0));
            atualizarTextura("../Imagens/JogadorE.png");
            if (body.getPosition().x < 0.f)
                body.setPosition(sf::Vector2f(0.f, body.getPosition().y));
            direita = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direita) { // para direita
            body.move(sf::Vector2f(vel.x, 0));
            atualizarTextura("../Imagens/JogadorD.png");
            if (body.getPosition().x > 750.f)
                body.setPosition(sf::Vector2f((800.f - body.getSize().x), body.getPosition().y));
            esquerda = true;
        }
        if (cair) {
            body.move(sf::Vector2f(0.f, 9.8f / 2.f * tempo_queda.getElapsedTime().asSeconds() * tempo_queda.getElapsedTime().asSeconds()));
        }
        else
            tempo_queda.restart();
    }

}
   

void Personagens::Jogador::executar()
{
    move();
}
