#pragma once

#include "InterfacePadrao.h"
#include "Botao.h"
  
/*
   Classe InterfacePosJogo: Interface exibida conforme o jogo termina. Mostrando frases diferentes de acordo com o acerto ou erro da palavra sorteada
e a palavra sorteada e exibindo botoes para reiniciar o jogo ou sair
*/

class InterfacePosJogo : public InterfacePadrao
{
public:
	InterfacePosJogo(const sf::IntRect& limites, const sf::Font& fonte, const std::string& palavraSorteada, const bool venceuOJogo); // construtor
	virtual ~InterfacePosJogo() = default; // destrutor

	// métodos 

	virtual void atualiza(const float tempoDelta) override {};

	virtual void desenha(sf::RenderWindow& janela) override;

	virtual void lidaComMousePressionado(const sf::Vector2i& posicaoDoMouse, bool botaoEsquerdo) override;

	virtual void lidaComMouseMovido(const sf::Vector2i& posicaoDoMouse) override;

	Estado getEstado() const override;

private:
	Estado estado; // estado da interface

	std::vector<Botao> botoes; // dois botoes, um de reiniciar e outro de sair 

	std::unique_ptr<sf::RectangleShape> fundo;

	std::unique_ptr<sf::RectangleShape> fundoDaTelaCheia;

	std::unique_ptr<sf::Text> textoPosJogo;

	std::unique_ptr<sf::Text> textoDaPalavraSorteada;
};
