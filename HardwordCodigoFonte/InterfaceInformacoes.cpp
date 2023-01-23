#include <string>

#include "InterfaceInformacoes.h"

// construtor: defini os elementos visuais, suas cores e disposições no espaço 
InterfaceInformacoes::InterfaceInformacoes(const sf::IntRect& limites, const sf::Font& fonte)
	: InterfacePadrao(limites), 
	botao(sf::IntRect((limites.left + limites.width / 4 + 1) + (limites.width / 2) - 30, limites.top + limites.height / 14, 30, 30), "X", 0, fonte)
{
	estadoAtual = Estado::NenhumEstado; // inicializado como sem estado por padrão

	fundoDaTelaCheia = std::make_unique<sf::RectangleShape>(sf::Vector2f(limites.width, limites.height));
	fundoDaTelaCheia->setFillColor(sf::Color(20, 20, 20, 150)); // torna-se parcialmente transparente para efeito de sobreposição

	// os fundos são inicializados de forma a produzir bordas na interface
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

	tituloDoTexto = std::make_unique<sf::Text>("Informações do Jogo", fonte, 40);
	tituloDoTexto->setPosition(sf::Vector2f(limites.left + limites.width / 2 - tituloDoTexto->getGlobalBounds().width / 2, (limites.top + limites.height / 12) + 40));

	// informações a respeito do jogo

	std::string sInformacao = "";

	sInformacao = "          Hardword é um jogo de advinhação, que cosnsiste em advinhar";
	sInformacao += "\n       uma palavra sorteada. A palavra a advinhar séra relacionada ao ";
	sInformacao += "\n       fascinante universo da computação.\n\n";
	sInformacao += "          O jogador possuirá seis tentativas, nas quais terá de chutar";
	sInformacao += "\n       palavras relacionadas a computação. O computador, então, ";
	sInformacao += "\n       mostrará quais letras da palavra palpitada estão  na palavra";
	sInformacao += "\n       sorteada e na posição correta (cor verde), estão presentes na";
	sInformacao += "\n       palavra mas na posição errada (cor amarela) ou não estão na ";
	sInformacao += "\n       palavra sorteada (cor cinza). Assim, o jogador poderá realizar";
	sInformacao += "\n       seu próximo palpite de maneira mais acertiva.\n\n";
	sInformacao += "          Hardword foi criado com forte inspiração no famoso jogo";
	sInformacao += "\n       Wordle. A principal diferença entre o jogo original e esse é ";
	sInformacao += "\n       a presença, unicamente, de palavras relacionadas a tecnologia.";
	sInformacao += "\n       Portanto, Hardword é recomendado, principalmente, para ";
	sInformacao += "\n       aqueles que se interessam pela área da computação.";

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
	// lida com o botão pressionado: fecha a interface e retorna ao menu
	if (botao.estaNaPosicao(posicaoDoMouse)) {
		estadoAtual = Estado::Finalizar;
	}
}

void InterfaceInformacoes::lidaComMouseMovido(const sf::Vector2i& posicaoDoMouse)
{
	botao.setCursor(botao.estaNaPosicao(posicaoDoMouse)); // efeito visual a partir da passagem do cursor do mouse sobre o botão
}

Estado InterfaceInformacoes::getEstado() const
{
	return estadoAtual;
}