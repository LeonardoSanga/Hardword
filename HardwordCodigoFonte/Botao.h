#pragma once

#include <SFML/Graphics.hpp>

/*
   Classe Botao: desenha um botão (retangulo com limites, cor de fundo e texto) e expande-o quando o cursor do mouse passa sobre ele para gerar um efeito 
visual
*/

class Botao
{
public:
	Botao(const sf::IntRect& limites, const std::string& texto, const int IDAcao, const sf::Font& fonte); // construtor
	virtual ~Botao() = default; // destrutor

	// métodos
	void desenha(sf::RenderWindow& janela) const;

	int getIDAcao() const;

	void setCursor(const bool estaPairando);

	bool estaNaPosicao(const sf::Vector2i& posicaoDoMouse) const;

	void setCorDeFundo(const sf::Color& cor);

	void aplicaIDCor(const int IDCor);

private:
	sf::IntRect limites;

	int IDAcao;

	bool pairando; // determina se o cursor do mouse está pairando sobre determinado botão

	std::string texto;

	sf::RectangleShape fundo;

	sf::Text textoVisivel;

	int IDCor;
};
