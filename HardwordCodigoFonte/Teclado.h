#pragma once

#include "InterfacePadrao.h"
#include "Botao.h"

/*
   Classe Teclado: cria o teclado visual da tela principal e possui m�todos para lidar com a��es sobre ele. Cada tecla do teclado visual � um objeto da classe
Botao
*/

class Teclado : public InterfacePadrao
{
public:
	Teclado(const sf::IntRect& limites, const sf::Font& fonte); // construtor
	virtual ~Teclado() = default; // destrutor

	// m�todos

	virtual void atualiza(const float tempoDelta) override {};

	virtual void desenha(sf::RenderWindow& janela) override;

	virtual void lidaComMousePressionado(const sf::Vector2i& posicaoDoMouse, bool botaoEsquerdo) override;

	virtual void lidaComMouseMovido(const sf::Vector2i& posicaoDoMouse) override;

	int getIDAcaoAnterior();

	void aplicaRegras(std::vector<std::string> regras);

private:
	std::vector<Botao> botoes; // teclas do teclado

	int IDAcao;

	void inicializaBotoes(const sf::Font& fonte); 
};
