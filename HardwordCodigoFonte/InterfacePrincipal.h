#pragma once

#include "InterfacePadrao.h"
#include "Teclado.h"
#include "GradeDeChutes.h"
#include "Botao.h"

/*
  Classe InterfacePrincipal: Possuí o teclado e a grade de chutes que é exibidade na tela de jogo, atualiza quando necessário, desenhando os chutes na grade 
  de acordo com o pressionamento do botão pelo mouse ou de acordo com o pressionamento do teclado
*/

class InterfacePrincipal : public InterfacePadrao
{
public:
	InterfacePrincipal(const sf::IntRect& limites, const sf::Font& fonte, const std::string& palavraSorteada);  // construtor
	virtual ~InterfacePrincipal(); // destrutor

	// métodos

	virtual void atualiza(const float tempoDelta) override;

	virtual void desenha(sf::RenderWindow& janela) override;

	virtual void lidaComMousePressionado(const sf::Vector2i& posicaoDoMouse, bool botaoEsquerdo) override;

	virtual void lidaComMouseMovido(const sf::Vector2i& posicaoDoMouse) override;

	virtual void lidaComTeclaPressionada(const sf::Keyboard::Key tecla) override;

	const GradeDeChutes& getGradeDeChutes() const;

	Estado getEstado() const override;

private:
	const sf::Font& fonte;

	sf::Text tituloDoJogo;

	Teclado teclado; // instancia do classe Teclado representado o teclado no canto interior da tela

	GradeDeChutes gradeDeChutes; // instancia da classe GradeDeChutes representando a grade de chutes no centro da tela

	Botao botaoMenu;

	bool voltarAoMenu;

	Estado estadoAtual; // estado da interface

	std::unique_ptr <sf::RectangleShape> fundo;
};
