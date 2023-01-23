#include "InterfacePosJogo.h" 

// construtor: defini os elementos visuais, suas cores e disposições no espaço 
InterfacePosJogo::InterfacePosJogo(const sf::IntRect& limites, const sf::Font& fonte, const std::string& palavraSorteada, const bool venceuOJogo)
	: InterfacePadrao(limites) 
{
	estado = Estado::NenhumEstado; // inicializado como sem estado por padrão

	fundoDaTelaCheia = std::make_unique<sf::RectangleShape>(sf::Vector2f(limites.width, limites.height));
	fundoDaTelaCheia->setFillColor(sf::Color(20, 20, 20, 150));

	fundo = std::make_unique<sf::RectangleShape>(sf::Vector2f(limites.width / 2, limites.height / 2));
	fundo->setFillColor(sf::Color(60, 60, 60, 230));
	fundo->setOutlineColor(sf::Color::White);
	fundo->setOutlineThickness(1);
	fundo->setPosition(limites.left + limites.width / 4 + 1, limites.top + limites.height / 4 + 1);

	textoPosJogo = std::make_unique<sf::Text>((venceuOJogo ? "Voce conseguiu!" : "Tente novamente!"), fonte, 40);
	textoPosJogo->setPosition(sf::Vector2f(limites.left + limites.width / 2 - textoPosJogo->getGlobalBounds().width / 2, limites.top + limites.height / 4 + 10));
	textoPosJogo->setFillColor(venceuOJogo ? sf::Color(93, 141, 74) : sf::Color(230, 93, 74));

	textoDaPalavraSorteada = std::make_unique<sf::Text>("Palavra: " + palavraSorteada, fonte, 30);
	textoDaPalavraSorteada->setPosition(sf::Vector2f(limites.left + limites.width / 2 - textoDaPalavraSorteada->getGlobalBounds().width / 2, limites.top + limites.height / 4 + 10 + 50));

	botoes.emplace_back(Botao(sf::IntRect(limites.left + limites.width / 2 - 260, limites.top + limites.height * 3 / 4 - 70, 250, 60), "Palavra nova", 0, fonte));
	botoes.emplace_back(Botao(sf::IntRect(limites.left + limites.width / 2 + 25, limites.top + limites.height * 3 / 4 - 70, 200, 60), "Sair", 1, fonte));
}

void InterfacePosJogo::desenha(sf::RenderWindow& janela)
{
	// desenha cada elemento visual
	janela.draw(*fundoDaTelaCheia);
	janela.draw(*fundo);
	janela.draw(*textoPosJogo);
	janela.draw(*textoDaPalavraSorteada);
	for (const auto& botao : botoes) {
		botao.desenha(janela);
	}
}

void InterfacePosJogo::lidaComMousePressionado(const sf::Vector2i& posicaoDoMouse, bool botaoEsquerdo)
{
	// lida com o botão pressionado: reinicia ou termina o jogo
	for (auto& botao : botoes) {
		if (botao.estaNaPosicao(posicaoDoMouse)) {
			if (botao.getIDAcao() == 0) {
				estado = Estado::Reiniciar;
			}
			else if (botao.getIDAcao() == 1) {
				estado = Estado::Sair;
			}
		}
	}
}

void InterfacePosJogo::lidaComMouseMovido(const sf::Vector2i& posicaoDoMouse)
{
	for (auto& botao : botoes) {
		botao.setCursor(botao.estaNaPosicao(posicaoDoMouse)); // efeito visual a partir da passada do cursor do mouse sobre o botão
	}
}

Estado InterfacePosJogo::getEstado() const
{
	return estado;
}