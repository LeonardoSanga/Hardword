#include "Teclado.h"

// construtor
Teclado::Teclado(const sf::IntRect& limites, const sf::Font& fonte)
	: InterfacePadrao(limites)
{
	inicializaBotoes(fonte);
	IDAcao = -1; // ID padr�o
}

void Teclado::desenha(sf::RenderWindow& janela)
{
	// desenha as teclas que compoem o teclado
	for (const auto& botao : botoes) {
		botao.desenha(janela);
	}
}

void Teclado::lidaComMousePressionado(const sf::Vector2i& posicaoDoMouse, bool botaoEsquerdo)
{
	for (auto& botao : botoes) {
		if (botao.estaNaPosicao(posicaoDoMouse)) { 
			IDAcao = botao.getIDAcao(); // recebe o ID da a��o para determinada a��o
			break;
		}
	}
}

void Teclado::lidaComMouseMovido(const sf::Vector2i& posicaoDoMouse)
{
	for (auto& button : botoes) {
		button.setCursor(button.estaNaPosicao(posicaoDoMouse)); // efeito visual sobre a tecla
	}
}

int Teclado::getIDAcaoAnterior()
{
	int IDAcaoAntigo = IDAcao;
	IDAcao = -1; // ID Padr�o
	return IDAcaoAntigo;
}

void Teclado::aplicaRegras(std::vector<std::string> regras)
{
	// define IDs diferentes de acordo com o estado da letra (chutada): posi��o correta, posi��o errada ou n�o est� na palavra, para pintar a tecla/bot�o
	for (auto regra : regras) {
		for (int i = 0, pos = 0; i < regra.length(); ++i, ++pos) {
			int IDCor = 1; // n�o est� na palavra

			if (regra.at(i) == '*') {
				i++;
				IDCor = 3; // posi��o correta
			}
			else if (regra.at(i) == '#') {
				i++;
				IDCor = 2; // posi��o errada
			}

			int letraFundida = static_cast<int>(regra.at(i));
			auto botao = std::find_if(botoes.begin(), botoes.end(),
				[&](Botao b) { return b.getIDAcao() == letraFundida; });
			if (botao != botoes.end()) {
				botao->aplicaIDCor(IDCor); // aplica as cores aos botoes/teclas
			}
		}
	}
}

// inicializa os bot�es com as letras e posi��es devidas
void Teclado::inicializaBotoes(const sf::Font& font)
{
	std::vector<std::string> textosDosBotoes{ "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Check", "Z", "X", "C", "V", "B", "N", "M", "<" };

	// c�lculo para computo das posi��es das "teclas" no espa�o

	int larguraDoBotao = 60;
	int alturaDoBotao = 60;

	int meio = ((larguraDoBotao + 10) * (3 + 8) - 10) / 2;
	int esquerda = limites.left + limites.width / 2 - meio;

	int posX = esquerda + meio - ((larguraDoBotao + 10) * (10) - 10) / 2;
	int posY = limites.top + limites.height - (alturaDoBotao + 15) * 3;
	int i = 0;


	for (; i < 10; i++, posX += larguraDoBotao + 10) {
		botoes.emplace_back(Botao(sf::IntRect(posX, posY, larguraDoBotao, alturaDoBotao), textosDosBotoes.at(i), static_cast<int>(textosDosBotoes.at(i).at(0)), font));
	}

	posX = esquerda + meio - ((larguraDoBotao + 10) * (9) - 10) / 2;
	posY += 10 + alturaDoBotao;

	for (; i < 19; i++, posX += larguraDoBotao + 10) {
		botoes.emplace_back(Botao(sf::IntRect(posX, posY, larguraDoBotao, alturaDoBotao), textosDosBotoes.at(i), static_cast<int>(textosDosBotoes.at(i).at(0)), font));
	}

	posX = esquerda;
	posY += 10 + alturaDoBotao;

	botoes.emplace_back(Botao(sf::IntRect(posX, posY, larguraDoBotao * 3, alturaDoBotao), textosDosBotoes.at(i), 1, font));

	i++;
	posX += larguraDoBotao * 3 + 10;

	for (; i < textosDosBotoes.size(); i++, posX += larguraDoBotao + 10) {
		botoes.emplace_back(Botao(sf::IntRect(posX, posY, larguraDoBotao, alturaDoBotao), textosDosBotoes.at(i), static_cast<int>(textosDosBotoes.at(i).at(0)), font));
	}
}