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

void Jogador::setBody(sf::Vector2f tam)
{
    sf::RectangleShape b(tam);
    body = b;
}

void Jogador::mudarVelocidade(float fator)
{
    alteracaoVel *= fator;
}

void Jogador::empurrar(bool esquerda)
{
    float bordaEsquerda = pGrafico->getWindow()->getView().getCenter().x - pGrafico->getWindow()->getView().getSize().x / 2;
    float bordaDireita = pGrafico->getWindow()->getView().getCenter().x + pGrafico->getWindow()->getView().getSize().x / 2;
    if (esquerda && (body.getPosition().x - 50.f > bordaEsquerda))
    {
        body.move(sf::Vector2f(-50.f, 0.f));
    }
    else if (!esquerda && (body.getPosition().x + body.getSize().x + 50.f < bordaDireita))
        body.move(sf::Vector2f(50.f, 0.f));
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
            //body.move(sf::Vector2f(-vel.x, 0));
            vel.x += -VEL_JOGADOR_X;
            atualizarTextura("../Imagens/JogadorE.png");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && direita)  // andar para a Direita
        {
            //body.move(sf::Vector2f(vel.x, 0));
            vel.x += VEL_JOGADOR_X;
            atualizarTextura("../Imagens/JogadorD.png");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // Pular
        {
            //body.move(sf::Vector2f(0, -vel.y));
            vel.y += -VEL_JOGADOR_Y;
        }
        if (cair) // Caindo
        {
            if (tempo_queda.getElapsedTime().asSeconds() > 2.f)
                tempo_queda.restart();
            //body.move(sf::Vector2f(0.f, 9.8f / 2.f * tempo_queda.getElapsedTime().asSeconds() * tempo_queda.getElapsedTime().asSeconds()));
            vel.y += 9.8f / 2 * tempo_queda.getElapsedTime().asSeconds() * tempo_queda.getElapsedTime().asSeconds();
        }
        else
        {
            tempo_queda.restart();
        }

        vel.x *= alteracaoVel;
        vel.y *= alteracaoVel;

        body.move(sf::Vector2f(vel.x, vel.y));

        vel.x = 0.f;
        vel.y = 0.f;
        alteracaoVel = 1.f;
        cair = true;
        esquerda = true;
        direita = true;
    }

    if (player == 2) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { // para cima
            vel.y += -VEL_JOGADOR_Y;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && esquerda) { // para esquerda
            vel.x -= VEL_JOGADOR_X;
            atualizarTextura("../Imagens/JogadorE.png");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direita) { // para direita
            vel.x += VEL_JOGADOR_X;
            atualizarTextura("../Imagens/JogadorD.png");
        }
        if (cair) {
            if (tempo_queda.getElapsedTime().asSeconds() > 2.f)
                tempo_queda.restart();
            //body.move(sf::Vector2f(0.f, 9.8f / 2.f * tempo_queda.getElapsedTime().asSeconds() * tempo_queda.getElapsedTime().asSeconds()));
            vel.y += 9.8f / 2 * tempo_queda.getElapsedTime().asSeconds() * tempo_queda.getElapsedTime().asSeconds();
        }
        else
            tempo_queda.restart();

        vel.x *= alteracaoVel;
        vel.y *= alteracaoVel;

        body.move(sf::Vector2f(vel.x, vel.y));

        vel.x = 0.f;
        vel.y = 0.f;
        alteracaoVel = 1.f;
        cair = true;
        esquerda = true;
        direita = true;
    }

}
   

void Personagens::Jogador::executar()
{
    move();
}
