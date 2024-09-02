#include "Jogador.h"

int Jogador::n_players(1);

Jogador::Jogador() :
    Personagem(VIDA_JOGADOR), player(n_players++), imune(false)
{
    tipo = 1;
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

void Jogador::operator++()
{
    pontuacao += 10;
}

void Jogador::setPulando()
{
    cair = true;
    tempo_queda.restart();
    pulando = true;
}


void Jogador::pular()
{
    vel.y = -VEL_JOGADOR_Y;
    if (player == 1)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // para a Esquerda
            atualizarTextura("../Imagens/JogadorPE.png");
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))  // para a Direita
            atualizarTextura("../Imagens/JogadorPD.png");
    }
    else if (player == 2)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // para a Esquerda
            atualizarTextura("../Imagens/JogadorPE.png");
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))  // para a Direita
            atualizarTextura("../Imagens/JogadorPD.png");
    }
}

void Jogador::reviver()
{
    noJogo = true;
    vida = VIDA_JOGADOR;
}

void Jogador::receberDano(int dano)
{
    if (!imune)
    {
        vida -= dano;
        if (vida <= 0)
            noJogo = false;
        imune = true;
        body.setFillColor(sf::Color::Red);
        tempo_imune.restart();
    }
}

void Jogador::operator--()
{
    if (!imune)
    {
        vida--;
        if (vida <= 0)
            noJogo = false;
        imune = true;
        body.setFillColor(sf::Color::Red);
        tempo_imune.restart();
    }
}

// Move o jogardor
void Jogador::move()
{
    if (player == 1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && esquerda) // andar para a Esquerda
        {
            vel.x += -VEL_JOGADOR_X;
            atualizarTextura("../Imagens/JogadorE.png");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && direita)  // andar para a Direita
        {
            vel.x += VEL_JOGADOR_X;
            atualizarTextura("../Imagens/JogadorD.png");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !pulando) // Pular
        {
            pulando = true;
        }
    }

    if (player == 2) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && esquerda) { // para esquerda
            vel.x -= VEL_JOGADOR_X;
            atualizarTextura("../Imagens/JogadorE.png");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direita) { // para direita
            vel.x += VEL_JOGADOR_X;
            atualizarTextura("../Imagens/JogadorD.png");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pulando) { // para cima
            pulando = true;
        }
    }

    if (pulando)
        pular();
    if (cair) // Caindo
    {
        if (tempo_queda.getElapsedTime().asSeconds() > 2.f)
            tempo_queda.restart();
        vel.y += 9.8f / 2 * tempo_queda.getElapsedTime().asSeconds() * tempo_queda.getElapsedTime().asSeconds();
    }
    else
    {
        tempo_queda.restart();
        pulando = false;
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
   

void Personagens::Jogador::executar()
{
    move();

    //Se passou de 1 segundo após tomar dano, volta ao normal e perde a imunidade
    if (tempo_imune.getElapsedTime().asSeconds() > 1.f)
    {
        imune = false;
        if (player == 2)
            body.setFillColor(sf::Color::Cyan);
        else
            body.setFillColor(sf::Color::White);
    }
}
