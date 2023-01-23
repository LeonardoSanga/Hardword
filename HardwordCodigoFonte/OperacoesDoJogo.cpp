#include <chrono>     

#include "OperacoesDoJogo.h"   
#include "InterfacePrincipal.h"
#include "InterfacePosJogo.h"
#include "InterfaceInicial.h"
#include "InterfaceInformacoes.h"

// constutor
OperacoesDoJogo::OperacoesDoJogo(const sf::IntRect& limites, const sf::Font& fonte)
	: limites(limites), fonte(fonte), banco(maquinaAleatoria)
{
	// Sorteia uma palavra do banco de palavras
	unsigned semente = std::chrono::system_clock::now().time_since_epoch().count();
	maquinaAleatoria = std::default_random_engine(semente);

	jogoFinalizado = false;
	interfaceAtiva = NULL;
	interfaceSecundaria = NULL;
	interfaceTelaInicial = NULL;
	interfaceInformacoes = NULL;

	interfaceTelaInicial = new InterfaceInicial(limites, fonte);
	//interfaceAtiva = new InterfacePrincipal(limites, fonte, banco.pegaPalavraAleatoria()); // inicia a interface principal
}

// destrutor: utilizado para desalocar memória dinamicamente
OperacoesDoJogo::~OperacoesDoJogo()
{
	if (interfaceTelaInicial != NULL) {
		delete interfaceTelaInicial;
	}
	if (interfaceAtiva != NULL) {
		delete interfaceAtiva;
	}
}

// atualiza: inicia as interfaces de acordo com a necessidade
void OperacoesDoJogo::atualiza(const float tempoDelta)
{
	if (interfaceSecundaria != NULL) { // interface principal é iniciada se a secundária não estiver ativada
		interfaceSecundaria->atualiza(tempoDelta);
		if (interfaceSecundaria->getEstado() == Estado::Reiniciar) { // No caso de requirida uma nova palavra
			delete interfaceSecundaria;
			interfaceSecundaria = NULL;
			delete interfaceAtiva;
			interfaceAtiva = new InterfacePrincipal(limites, fonte, banco.pegaPalavraAleatoria());
		}
		else if (interfaceSecundaria->getEstado() == Estado::Sair) {
			jogoFinalizado = true;
		}
	}
	else if (interfaceAtiva != NULL) { // interface secundária é iniciada se a principal não estiver ativada
		interfaceAtiva->atualiza(tempoDelta);
		if (interfaceAtiva->getEstado() == Estado::Finalizar && interfaceSecundaria == NULL) {
			auto gradeDeChutes = dynamic_cast<InterfacePrincipal*>(interfaceAtiva)->getGradeDeChutes();
			std::string palavraSorteada = gradeDeChutes.getPalavraSorteada();

			//interfaceAtiva = NULL;
			interfaceSecundaria = new InterfacePosJogo(limites, fonte, palavraSorteada, gradeDeChutes.getResolvido());
		}
		else if (interfaceAtiva->getEstado() == Estado::Menu && interfaceSecundaria == NULL) {
			delete interfaceAtiva;
			interfaceAtiva = NULL;

			interfaceTelaInicial = new InterfaceInicial(limites, fonte);
		}
	}
	else if (interfaceInformacoes != NULL) {
		interfaceInformacoes->atualiza(tempoDelta);

		if (interfaceInformacoes->getEstado() == Estado::Finalizar) {
			delete interfaceInformacoes;
			interfaceInformacoes = NULL;
			delete interfaceTelaInicial;
			interfaceTelaInicial = new InterfaceInicial(limites, fonte);
		}
	}
	else if (interfaceTelaInicial != NULL) {
		interfaceTelaInicial->atualiza(tempoDelta);

		if (interfaceTelaInicial->getEstado() == Estado::Finalizar) {

			interfaceTelaInicial = NULL;
			interfaceAtiva = new InterfacePrincipal(limites, fonte, banco.pegaPalavraAleatoria()); // inicia a interface principal

		}
		else if (interfaceTelaInicial->getEstado() == Estado::Menu && interfaceInformacoes == NULL) {

			//interfaceTelaInicial = NULL;
			interfaceInformacoes = new InterfaceInformacoes(limites, fonte); // inicia a interface principal
		}
	}
}

// desenha: desenha a interface de acordo com a ocasião
void OperacoesDoJogo::desenha(sf::RenderWindow& janela) const
{
	if (interfaceTelaInicial != NULL) {
		interfaceTelaInicial->desenha(janela);
	}
	if (interfaceInformacoes != NULL) {
		interfaceInformacoes->desenha(janela);
	}
	if (interfaceAtiva != NULL) {
		interfaceAtiva->desenha(janela);
	}
	if (interfaceSecundaria != NULL) {
		interfaceSecundaria->desenha(janela);
	}
}

// lidaComMousePressionado: lida com o pressionamento do mouse para uma das interface de acordo com a ocasião
void OperacoesDoJogo::lidaComMousePressionado(const sf::Vector2i& posicaoDoMouse, bool botaoEsquerdo)
{
	if (interfaceSecundaria != NULL) {
		interfaceSecundaria->lidaComMousePressionado(posicaoDoMouse, botaoEsquerdo);
	}
	else if (interfaceAtiva != NULL) {
		interfaceAtiva->lidaComMousePressionado(posicaoDoMouse, botaoEsquerdo);
	}
	else if (interfaceInformacoes != NULL) {
		interfaceInformacoes->lidaComMousePressionado(posicaoDoMouse, botaoEsquerdo);
	}
	else if (interfaceTelaInicial != NULL) {
		interfaceTelaInicial->lidaComMousePressionado(posicaoDoMouse, botaoEsquerdo);
	}
}

// lidaComMouseMovido: lida com o movimento do mouse para uma das interface de acordo com a ocasião
void OperacoesDoJogo::lidaComMouseMovido(const sf::Vector2i& posicaoDoMouse)
{
	if (interfaceSecundaria != NULL) {
		interfaceSecundaria->lidaComMouseMovido(posicaoDoMouse);
	}
	else if (interfaceAtiva != NULL) {
		interfaceAtiva->lidaComMouseMovido(posicaoDoMouse);
	}
	else if (interfaceInformacoes != NULL) {
		interfaceInformacoes->lidaComMouseMovido(posicaoDoMouse);
	}
	else if (interfaceTelaInicial != NULL) {
		interfaceTelaInicial->lidaComMouseMovido(posicaoDoMouse);
	}
}

// lidaComTeclaPressionada: lida com o pressionamento da tecla para uma das interface de acordo com a ocasião
void OperacoesDoJogo::lidaComTeclaPressionada(const sf::Keyboard::Key tecla)
{
	if (interfaceSecundaria != NULL) {
		interfaceSecundaria->lidaComTeclaPressionada(tecla); //////////////////////////////////
	}
	else if (interfaceAtiva != NULL) {
		interfaceAtiva->lidaComTeclaPressionada(tecla);
	}
}

// getRequisicaoDeSaida: retorna a requisição de sáida
bool OperacoesDoJogo::getRequisicaoDeSaida()
{
	return jogoFinalizado;
}