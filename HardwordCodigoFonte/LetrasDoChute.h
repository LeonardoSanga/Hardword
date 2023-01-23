#pragma once

#include <SFML/Graphics.hpp>

/*
  Classe LetrasDoChute: representa cada letra da grade de palpites, sendo exibida visualmente como um retângulo com cores  de fundo que variam dependendo da 
verificação do chute e posições diversas para uma boa disposição no espaço
*/

class LetrasDoChute
{
public:
	
	LetrasDoChute(); // construtor
	virtual ~LetrasDoChute() = default; // destrutor

	// métodos

	void desenha(sf::RenderWindow& janela) const;

	char getLetra() const;

	void setLetra(const char letraAInserir);

	void setEstado(int estado);

	static sf::Font carregaFonte();

	int getEstadoDoChute() const;

private:

	int estadoDoChute; // 0 = Não está na palavra sorteada (cinza), 1 = está na palavra sorteada e na posicão correta (verde), 2 = está na palavra sorteada na 
//posição errada (amarelo)

	sf::RectangleShape fundo;

	sf::IntRect limites;

	char letra;

	static int posX, posY;  // usados para definir as posições da cada letra da grade de chutes na tela

	static int contador; // usado para atribuir as posições corretas para a disposição visual de cada retangulo que representa a letra de um chute

    sf::Font fonte; 

    sf::Text textoVisivel;

	void setCorDeFundo(const sf::Color& cor);
};