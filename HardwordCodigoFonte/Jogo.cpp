#include "Jogo.h"

#define LARGURA_JANELA 1280
#define ALTURA_JANELA 720

/* 
  construtor: inicializa a janela(1280x720), carrega a fonte pelo método carregaFonte, usa o construtor da classe OperacoesDoJogo para 
inicializar o objeto com os limites e fonte
*/
Jogo::Jogo()
	: janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Hardword", sf::Style::Titlebar | sf::Style::Close),
	fonte(carregaFonte()), operacoes(sf::IntRect(0, 0, LARGURA_JANELA, ALTURA_JANELA), fonte)
{
}

// loop: abre a janela e coloca o jogo em loop, lidando com cada evento neceesário ao jogo, atualizando e desenhando as interfaces
void Jogo::loop()
{
	sf::Clock relogio;
	while (janela.isOpen())
	{
		sf::Time tempoDecorrido = relogio.restart();
		float tempoDelta = tempoDecorrido.asSeconds();
		sf::Event evento;
		if (janela.waitEvent(evento))
		{
			if (evento.type == sf::Event::Closed) { // sair
				janela.close();
			}
			else if (evento.type == sf::Event::MouseButtonPressed) { // mouse pressionado
				operacoes.lidaComMousePressionado(sf::Vector2i(evento.mouseButton.x, evento.mouseButton.y), evento.mouseButton.button == sf::Mouse::Left);
			}
			else if (evento.type == sf::Event::MouseMoved) { // mouse movido
				operacoes.lidaComMouseMovido(sf::Vector2i(evento.mouseMove.x, evento.mouseMove.y));
			}
			else if (evento.type == sf::Event::KeyPressed) {  // tecla pressionada
				operacoes.lidaComTeclaPressionada(evento.key.code);
			}
		}
		operacoes.atualiza(tempoDelta); // atualiza as interfaces

		janela.clear(sf::Color::Black);
		operacoes.desenha(janela);
		janela.display();

		if (operacoes.getRequisicaoDeSaida()) { // finaliza o jogo quando a requisição de saída é ativada
			janela.close();
		}
	}
}

// carregaFonte: carrega a fonte e a retorna, verificando se a operação ocorreu com sucesso ou não
sf::Font Jogo::carregaFonte()
{
	sf::Font fonte;
	if (!fonte.loadFromFile("Fonte.ttf"))
	{
		throw("Falha ao carregar a fonte");  // erro no carregamento
	}

	return fonte;
}