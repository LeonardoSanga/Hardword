#pragma once

#include "InterfacePadrao.h"
#include "Botao.h"

/*
   Classe InterfaceInformacoes: Interface exibida caso, na interface inicial (menu), o usu�rio clique no bot�o informa��es. Abre-se uma tela sobreposta
mostrando um texto com informa��es acerca do jogo.
*/

class InterfaceInformacoes : public InterfacePadrao
{
public:
	InterfaceInformacoes(const sf::IntRect& limites, const sf::Font& fonte); // construtor
	virtual ~InterfaceInformacoes() = default; // destrutor

	// m�todos 

	virtual void atualiza(const float tempoDelta) override {};

	virtual void desenha(sf::RenderWindow& janela) override;

	virtual void lidaComMousePressionado(const sf::Vector2i& posicaoDoMouse, bool botaoEsquerdo) override;

	virtual void lidaComMouseMovido(const sf::Vector2i& posicaoDoMouse) override;

	Estado getEstado() const override;

private:
	Estado estadoAtual; // estado da interface

	Botao botao; // bot�o utilizado para fechar a tela e retornar ao menu

	std::unique_ptr<sf::RectangleShape> fundo;

	std::unique_ptr<sf::RectangleShape> fundo2; // utilizado para criar bordas

	std::unique_ptr<sf::RectangleShape> fundoDaTelaCheia; // cobre a janela toda

	std::unique_ptr<sf::Text> tituloDoTexto;

	std::unique_ptr<sf::Text> texto;
};
