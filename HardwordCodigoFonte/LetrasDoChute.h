#pragma once

#include <SFML/Graphics.hpp>

/*
  Classe LetrasDoChute: representa cada letra da grade de palpites, sendo exibida visualmente como um ret�ngulo com cores  de fundo que variam dependendo da 
verifica��o do chute e posi��es diversas para uma boa disposi��o no espa�o
*/

class LetrasDoChute
{
public:
	
	LetrasDoChute(); // construtor
	virtual ~LetrasDoChute() = default; // destrutor

	// m�todos

	void desenha(sf::RenderWindow& janela) const;

	char getLetra() const;

	void setLetra(const char letraAInserir);

	void setEstado(int estado);

	static sf::Font carregaFonte();

	int getEstadoDoChute() const;

private:

	int estadoDoChute; // 0 = N�o est� na palavra sorteada (cinza), 1 = est� na palavra sorteada e na posic�o correta (verde), 2 = est� na palavra sorteada na 
//posi��o errada (amarelo)

	sf::RectangleShape fundo;

	sf::IntRect limites;

	char letra;

	static int posX, posY;  // usados para definir as posi��es da cada letra da grade de chutes na tela

	static int contador; // usado para atribuir as posi��es corretas para a disposi��o visual de cada retangulo que representa a letra de um chute

    sf::Font fonte; 

    sf::Text textoVisivel;

	void setCorDeFundo(const sf::Color& cor);
};