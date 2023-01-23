#include <string>

#include "InterfaceInformacoes.h"

// construtor: defini os elementos visuais, suas cores e disposi��es no espa�o 
InterfaceInformacoes::InterfaceInformacoes(const sf::IntRect& limites, const sf::Font& fonte)
	: InterfacePadrao(limites), 
	botao(sf::IntRect((limites.left + limites.width / 4 + 1) + (limites.width / 2) - 30, limites.top + limites.height / 14, 30, 30), "X", 0, fonte)
{
	estadoAtual = Estado::NenhumEstado; // inicializado como sem estado por padr�o

	fundoDaTelaCheia = std::make_unique<sf::RectangleShape>(sf::Vector2f(limites.width, limites.height));
	fundoDaTelaCheia->setFillColor(sf::Color(20, 20, 20, 150)); // torna-se parcialmente transparente para efeito de sobreposi��o

	// os fundos s�o inicializados de forma a produzir bordas na interface
	fundo = std::make_unique<sf::RectangleShape>(sf::Vector2f(limites.width / 2, limites.height / 1.2));
	fundo->setFillColor(sf::Color::Black);
	fundo->setOutlineColor(sf::Color::White);
	fundo->setOutlineThickness(1);
	fundo->setPosition(limites.left + limites.width / 4 + 1, limites.top + limites.height / 14);

	fundo2 = std::make_unique<sf::RectangleShape>(sf::Vector2f((limites.width / 2) - 60, (limites.height / 1.2) - 60));
	fundo2->setFillColor(sf::Color(20, 20, 40));
	fundo2->setOutlineColor(sf::Color::White);
	fundo2->setOutlineThickness(1);
	fundo2->setPosition((limites.left + limites.width / 4 + 1) + 30, (limites.top + limites.height / 14) + 30);

	tituloDoTexto = std::make_unique<sf::Text>("Informa��es do Jogo", fonte, 40);
	tituloDoTexto->setPosition(sf::Vector2f(limites.left + limites.width / 2 - tituloDoTexto->getGlobalBounds().width / 2, (limites.top + limites.height / 12) + 40));

	// informa��es a respeito do jogo

	std::string sInformacao = "";

	sInformacao = "          Hardword � um jogo de advinha��o, que cosnsiste em advinhar";
	sInformacao += "\n       uma palavra sorteada. A palavra a advinhar s�ra relacionada ao ";
	sInformacao += "\n       fascinante universo da computa��o.\n\n";
	sInformacao += "          O jogador possuir� seis tentativas, nas quais ter� de chutar";
	sInformacao += "\n       palavras relacionadas a computa��o. O computador, ent�o, ";
	sInformacao += "\n       mostrar� quais letras da palavra palpitada est�o  na palavra";
	sInformacao += "\n       sorteada e na posi��o correta (cor verde), est�o presentes na";
	sInformacao += "\n       palavra mas na posi��o errada (cor amarela) ou n�o est�o na ";
	sInformacao += "\n       palavra sorteada (cor cinza). Assim, o jogador poder� realizar";
	sInformacao += "\n       seu pr�ximo palpite de maneira mais acertiva.\n\n";
	sInformacao += "          Hardword foi criado com forte inspira��o no famoso jogo";
	sInformacao += "\n       Wordle. A principal diferen�a entre o jogo original e esse � ";
	sInformacao += "\n       a presen�a, unicamente, de palavras relacionadas a tecnologia.";
	sInformacao += "\n       Portanto, Hardword � recomendado, principalmente, para ";
	sInformacao += "\n       aqueles que se interessam pela �rea da computa��o.";

	texto = std::make_unique<sf::Text>(sInformacao, fonte, 17);
	texto->setPosition(limites.left + limites.width / 4 + 1, ((limites.top + limites.height / 14) + 20) + 110);
}
void InterfaceInformacoes::desenha(sf::RenderWindow& janela)
{
	// desenha cada elemento visual
	janela.draw(*fundoDaTelaCheia);
	janela.draw(*fundo);
	janela.draw(*fundo2);
	janela.draw(*tituloDoTexto);
	janela.draw(*texto);
	botao.desenha(janela);
}

void InterfaceInformacoes::lidaComMousePressionado(const sf::Vector2i& posicaoDoMouse, bool botaoEsquerdo)
{
	// lida com o bot�o pressionado: fecha a interface e retorna ao menu
	if (botao.estaNaPosicao(posicaoDoMouse)) {
		estadoAtual = Estado::Finalizar;
	}
}

void InterfaceInformacoes::lidaComMouseMovido(const sf::Vector2i& posicaoDoMouse)
{
	botao.setCursor(botao.estaNaPosicao(posicaoDoMouse)); // efeito visual a partir da passagem do cursor do mouse sobre o bot�o
}

Estado InterfaceInformacoes::getEstado() const
{
	return estadoAtual;
}