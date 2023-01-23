#pragma once

#include "InterfacePadrao.h"
#include "Botao.h"

/*
  Classe InterfaceInicial: � o menu exibido no inicio da execu��o do jogo. Possui bot�es para come�ar a jogar e exibir as informa��es do jogo.
*/

class InterfaceInicial : public InterfacePadrao
{
public:
	InterfaceInicial(const sf::IntRect& limites, const sf::Font& fonte);  // construtor
	virtual ~InterfaceInicial(); // destrutor

	// m�todos

	virtual void atualiza(const float tempoDelta) override;

	virtual void desenha(sf::RenderWindow& janela) override;

	virtual void lidaComMousePressionado(const sf::Vector2i& posicaoDoMouse, bool botaoEsquerdo) override;

	virtual void lidaComMouseMovido(const sf::Vector2i& posicaoDoMouse) override;

	Estado getEstado() const override;

private:
	const sf::Font& fonte;

	sf::Text tituloDoJogo;

	Botao botaoDePlay;

	Botao botaoDeInformacoes;

	sf::Texture desenhoDoFundo;

	sf::Sprite fundo;

	bool jogar;

	bool lerInformacoes;

	Estado estadoAtual; // estado da interface
};
