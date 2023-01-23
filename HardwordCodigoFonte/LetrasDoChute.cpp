#include "LetrasDoChute.h"

// atribui valores às variáveis static para armazenarem os conteúdos corretos no início do programa
int LetrasDoChute::contador = 0;
int LetrasDoChute::posX = 1280 / 2 - ((60 + 10) * 6) / 2;
int LetrasDoChute::posY = 30;

// construtor
LetrasDoChute::LetrasDoChute()
	: letra(' '), fonte(carregaFonte())
{
	if (contador > 6) { // para começar a incrementar posX e posY só depois que todos os nós (Nodes) header foram alocados (nós possuem objetos LetrasDoChute)

		// retorna à posição inicial X para cada nova palvra (primeira coluna de cada linha da grade de chutes), enquanto a posição Y é incrementada
		if ((contador % 6 == 0 && contador != 0)) { 
			posY += 60 + 10;
			posX = 1280 / 2 - ((60 + 10) * 6) / 2;         
		}

		if (contador % 6 != 0) { // Incremento da posição X para cada letra da palavra
			posX += 60 + 10;
		}
	}

	if (contador == 42) { // atribui os valores iniciais para contador, posX e posY quando um Novo Jogo é requisitado
		contador = 0;
		posX = 1280 / 2 - ((60 + 10) * 6) / 2;
	    posY = 30;
	}

	contador++; // incremento do contador a partir da criação de um objeto

	limites = sf::IntRect(posX, posY, 60, 60);

	textoVisivel = sf::Text(' ', fonte, 30);
	textoVisivel.setFillColor(sf::Color::White);
	textoVisivel.setStyle(sf::Text::Bold);
	textoVisivel.setPosition(sf::Vector2f(limites.left + limites.width / 2 - textoVisivel.getGlobalBounds().width / 2, limites.top + limites.height / 2 - 20));
	textoVisivel.setString(' ');

	fundo = sf::RectangleShape(sf::Vector2f(limites.width - 2, limites.height - 2));
	fundo.setPosition(sf::Vector2f(limites.left + 1, limites.top + 1));
	fundo.setFillColor(sf::Color(5, 5, 5));
	fundo.setOutlineThickness(1);
	fundo.setOutlineColor(sf::Color::White);

	estadoDoChute = 0; // inicia como "cinza": não está na palavra sorteada
}

void LetrasDoChute::desenha(sf::RenderWindow& janela) const
{
	// desenha as letras
	janela.draw(fundo);
	janela.draw(textoVisivel);
}

char LetrasDoChute::getLetra() const
{
	return letra;
}

void LetrasDoChute::setLetra(const char letraAInserir)
{
	letra = letraAInserir;
	textoVisivel.setString(letraAInserir);
}

void LetrasDoChute::setEstado(int estado) {

	// seta o estado e pinta o fundo do retângulo de acordo com o mesmo
	estadoDoChute = estado;

	switch (estadoDoChute) {
	case 0:
		fundo.setFillColor(sf::Color(40, 40, 40)); // não está na palavra sorteada(cinza)
		break;
	case 1:
		fundo.setFillColor(sf::Color(93, 141, 74)); // está na palavra sorteada e na posicão correta (verde)
		break;
	case 2:
		fundo.setFillColor(sf::Color(141, 141, 74)); // está na palavra sorteada na posição errada (amarelo)
		break;
	}
}

int LetrasDoChute::getEstadoDoChute() const
{
	return estadoDoChute;
}

void LetrasDoChute::setCorDeFundo(const sf::Color& cor)
{
	fundo.setFillColor(cor);
}

sf::Font LetrasDoChute::carregaFonte()
{
	// carrega a fonte
	sf::Font font;
	if (!font.loadFromFile("Fonte.ttf"))
	{
		throw("Falha em carregar a Fonte");
	}

	return font;
}