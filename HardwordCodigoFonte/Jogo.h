#pragma once

#include "OperacoesDoJogo.h"

/* 
  Classe Jogo: Cria a janela do jogo e coloca o mesmo em loop, garantindo lidar com os eventos, como pressionamento
em botão do mouse, pressionameto em tecla, movimentação do mouse e saída do jogo, também atualiza as interfaces e 
desenha-as no momento devido 
*/

class Jogo
{
public:
	Jogo(); // construtor
	virtual ~Jogo() = default; // destrutor padrão

	// loop do jogo
	void loop(); 

private:
	sf::RenderWindow janela;

	sf::Font fonte; 

	OperacoesDoJogo operacoes;  // objeto da classe OperacoesDoJogo

	static sf::Font carregaFonte(); // método que carrega a fonte
};

