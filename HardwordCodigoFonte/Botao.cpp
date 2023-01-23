#include "Botao.h"

// construtor: define as características principais do botão para que seja exibido de forma correta na tela
Botao::Botao(const sf::IntRect& limites, const std::string& texto, const int IDAcao, const sf::Font& fonte)
	: limites(limites), texto(texto), IDAcao(IDAcao),
	fundo(sf::Vector2f(limites.width - 2, limites.height - 2)),
	textoVisivel(texto, fonte, 30)
{
	textoVisivel.setFillColor(sf::Color::White);
	textoVisivel.setStyle(sf::Text::Bold); 
	textoVisivel.setPosition(sf::Vector2f(limites.left + limites.width / 2 - textoVisivel.getGlobalBounds().width / 2, limites.top + limites.height / 2 - 20));

	fundo.setPosition(sf::Vector2f(limites.left + 1, limites.top + 1));
	fundo.setFillColor(sf::Color(5, 5, 5));
	fundo.setOutlineThickness(1);
	fundo.setOutlineColor(sf::Color::White);

	IDCor = 0; // ID da cor padrão
	pairando = false;
}

void Botao::desenha(sf::RenderWindow& janela) const
{
	// desemha o botão
	janela.draw(fundo);
	janela.draw(textoVisivel);
}

int Botao::getIDAcao() const
{
	return IDAcao;
}

void Botao::setCursor(const bool estaPairando)
{
	pairando = estaPairando;
	fundo.setOutlineThickness(pairando ? 3 : 1); // expande bordas do botão quando o mouse é passado sobre o mesmo, para efeito visual
}

bool Botao::estaNaPosicao(const sf::Vector2i& posicaoDoMouse) const
{
	return limites.contains(posicaoDoMouse); // verifica se a posição do cursor do mouse está nos limites do botão (sobre ele)
}

void Botao::setCorDeFundo(const sf::Color& cor)
{
	fundo.setFillColor(cor);
}

void Botao::aplicaIDCor(const int IDCorAPintar)
{
	// pinta o botão de acordo com o ID da cor
	if (IDCorAPintar > IDCor) {
		IDCor = IDCorAPintar;
		switch (IDCor) {
		case 1:
			fundo.setFillColor(sf::Color(40, 40, 40)); // não está na palavra
			break;
		case 2:
			fundo.setFillColor(sf::Color(141, 141, 74)); // posição errada
			break;
		case 3: 
			fundo.setFillColor(sf::Color(93, 141, 74)); // posição correta
			break;
		}
	}
}