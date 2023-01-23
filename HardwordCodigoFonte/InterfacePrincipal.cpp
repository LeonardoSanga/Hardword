#include "InterfacePrincipal.h"

// contrutor
InterfacePrincipal::InterfacePrincipal(const sf::IntRect& limites, const sf::Font& fonte, const std::string& palavraSorteada)
	: InterfacePadrao(limites), fonte(fonte), tituloDoJogo("Hardword", fonte, 50), 
	botaoMenu(sf::IntRect(5, 85, 105, 45), "Menu", 1, fonte),
	teclado(limites, fonte), gradeDeChutes(limites, fonte, palavraSorteada, 6)
{
	tituloDoJogo.setPosition(sf::Vector2f(5, 5)); 


	estadoAtual = Estado::NenhumEstado; // começa sem estado
	voltarAoMenu = false;

	fundo = std::make_unique<sf::RectangleShape>(sf::Vector2f(limites.width, limites.height));
	fundo->setFillColor(sf::Color(20, 20, 40));
}   

// destrutor
InterfacePrincipal::~InterfacePrincipal()
{
}

void InterfacePrincipal::atualiza(const float tempoDelta)
{
	// finaliza o jogo/interface se não existem mais tentativas ou se a palavra foi resolvida
	if (gradeDeChutes.getResolvido() || !gradeDeChutes.temMaisTentativas()) {
		estadoAtual = Estado::Finalizar; 
	}
	else if (voltarAoMenu) {
		estadoAtual = Estado::Menu;
	}
}

void InterfacePrincipal::desenha(sf::RenderWindow& janela) 
{
	// desenha cada um dos elementos visuais
	janela.draw(*fundo);
	janela.draw(tituloDoJogo);
	teclado.desenha(janela);
	gradeDeChutes.desenha(janela);
	botaoMenu.desenha(janela);
}

void InterfacePrincipal::lidaComMousePressionado(const sf::Vector2i& posicaoDoMouse, bool botaoEsquerdo)
{
	teclado.lidaComMousePressionado(posicaoDoMouse, botaoEsquerdo);
	int acao = teclado.getIDAcaoAnterior();

	if (acao == static_cast<int>('<')) { // apaga a letra chutada da grade de chutes
		gradeDeChutes.apagar();
	}
	else if (acao == 1) { // verifica cada situação das letras do chute
		gradeDeChutes.verificaChute();
	}
	else if (acao != -1) { // insere a letra na grade de chutes
		gradeDeChutes.tentaInserirLetra(static_cast<char>(acao));
	}
	else if (botaoMenu.estaNaPosicao(posicaoDoMouse)) {
		voltarAoMenu = true;
	}
}

void InterfacePrincipal::lidaComMouseMovido(const sf::Vector2i& posicaoDoMouse)
{
	teclado.lidaComMouseMovido(posicaoDoMouse); // chama método do teclado para efeito visual no teclado da tela
	botaoMenu.setCursor(botaoMenu.estaNaPosicao(posicaoDoMouse));
}

void InterfacePrincipal::lidaComTeclaPressionada(const sf::Keyboard::Key tecla)
{
	gradeDeChutes.lidaComTeclaPressionada(tecla); // lida com chute a partir do teclado (teclado do próprio computador)
	if (gradeDeChutes.getChaveDeVerificacaoAnterior()) {
		teclado.aplicaRegras(gradeDeChutes.getTodasRegras()); // verifica os chutes para pintar o teclado da tela
	}
}

const GradeDeChutes& InterfacePrincipal::getGradeDeChutes() const
{
	return gradeDeChutes;
}

Estado InterfacePrincipal::getEstado() const
{
	return estadoAtual;
}
