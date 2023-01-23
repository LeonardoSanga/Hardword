#pragma once

#include "OperacoesDoJogo.h"

/* 
  Classe Jogo: Cria a janela do jogo e coloca o mesmo em loop, garantindo lidar com os eventos, como pressionamento
em bot�o do mouse, pressionameto em tecla, movimenta��o do mouse e sa�da do jogo, tamb�m atualiza as interfaces e 
desenha-as no momento devido 
*/

class Jogo
{
public:
	Jogo(); // construtor
	virtual ~Jogo() = default; // destrutor padr�o

	// loop do jogo
	void loop(); 

private:
	sf::RenderWindow janela;

	sf::Font fonte; 

	OperacoesDoJogo operacoes;  // objeto da classe OperacoesDoJogo

	static sf::Font carregaFonte(); // m�todo que carrega a fonte
};

