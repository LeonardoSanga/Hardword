#pragma once

#include <random>

#include "InterfacePadrao.h"
#include "BancoDePalavras.h"

/*
  Classe OperacoesDoJogo: possu� duas interfaces, a principal e a que � chamada quando o jogo termina. Atualiza essas interfaces, exibindo-as no momento certo.
Trata diferentes eventos tanto para a interface principal quanto para a interface p�s jogo.
*/   
class OperacoesDoJogo
{
public:
	OperacoesDoJogo(const sf::IntRect& limites, const sf::Font& fonte); // construtor
	virtual ~OperacoesDoJogo(); // destrutor

	// m�todos

	void atualiza(const float tempoDelta);

	void desenha(sf::RenderWindow& janela) const;

	void lidaComMousePressionado(const sf::Vector2i& posicaoDoMouse, bool botaoEsquerdo);

	void lidaComMouseMovido(const sf::Vector2i& posicaoDoMouse);

	void lidaComTeclaPressionada(const sf::Keyboard::Key tecla);

	bool getRequisicaoDeSaida();

private:
	const sf::IntRect limites;

	const sf::Font& fonte;

	BancoDePalavras banco; // Objeto da classe BancoDePalavras que possu� um vector com as palvras a serem sorteadas

	std::default_random_engine maquinaAleatoria; // utilizada para sortear a palavra

	InterfacePadrao* interfaceAtiva; // interface principal

	InterfacePadrao* interfaceSecundaria;  // interface p�s jogo

	InterfacePadrao* interfaceTelaInicial;

	InterfacePadrao* interfaceInformacoes;

	bool jogoFinalizado;
};
