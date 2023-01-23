#include "InterfaceInicial.h"

// contrutor: inicializa os elementos visuais, definindo suas caracteir�sticas e posi��es
InterfaceInicial::InterfaceInicial(const sf::IntRect& limites, const sf::Font& fonte)
	: InterfacePadrao(limites), fonte(fonte), tituloDoJogo("Hardword", fonte, 55),
	botaoDePlay(sf::IntRect(550.f, 320.f, 200, 90), "Jogar", 1, fonte),
	botaoDeInformacoes(sf::IntRect(445.f, 440.f, 420, 40), "Informa��es", 1, fonte)
{
	tituloDoJogo.setOrigin(22.f, 1.f);
	tituloDoJogo.setPosition(532.40f, 57.f);
	tituloDoJogo.setFillColor(sf::Color::Black); 

	desenhoDoFundo.loadFromFile("imagemTelaInicial.png");

	fundo.setTexture(desenhoDoFundo);

	botaoDePlay.setCorDeFundo(sf::Color::Green);
	botaoDeInformacoes.setCorDeFundo(sf::Color(20, 20, 55));

	jogar = false;
	lerInformacoes = false;

	estadoAtual = Estado::NenhumEstado; // come�a sem estado
}

// destrutor
InterfaceInicial::~InterfaceInicial()
{
}

void InterfaceInicial::atualiza(const float tempoDelta)
{
	if (jogar) { // finaliza o jogo/interface se n�o existem mais tentativas ou se a palavra foi resolvida
		estadoAtual = Estado::Finalizar;
	}
	else if (lerInformacoes) { // abre a tela das informa��es do jogo caso solicitado
		estadoAtual = Estado::Menu;
	}
}

void InterfaceInicial::desenha(sf::RenderWindow& janela)
{
	// desenha cada um dos elementos visuais
	janela.draw(fundo);
	janela.draw(tituloDoJogo);
	botaoDePlay.desenha(janela);
	botaoDeInformacoes.desenha(janela);
}

void InterfaceInicial::lidaComMousePressionado(const sf::Vector2i& posicaoDoMouse, bool botaoEsquerdo)
{
	if (botaoDePlay.estaNaPosicao(posicaoDoMouse)) { // clique no bot�o de jogar
		jogar = true;
	}
	else if (botaoDeInformacoes.estaNaPosicao(posicaoDoMouse)) {  // clique no bot�o de informa��es
		lerInformacoes = true;
	}
}

void InterfaceInicial::lidaComMouseMovido(const sf::Vector2i& posicaoDoMouse)
{
	botaoDePlay.setCursor(botaoDePlay.estaNaPosicao(posicaoDoMouse)); // passagem do cursor sobre o bot�o de jogar

	botaoDeInformacoes.setCursor(botaoDeInformacoes.estaNaPosicao(posicaoDoMouse)); // passagem do cursor sobre o bot�o de informa��es
}

Estado InterfaceInicial::getEstado() const
{
	return estadoAtual;
}
