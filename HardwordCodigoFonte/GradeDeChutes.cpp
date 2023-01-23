#include "GradeDeChutes.h"
#include <sstream>

// construtor
GradeDeChutes::GradeDeChutes(const sf::IntRect& limites, const sf::Font& fonte, const std::string& palavraSorteada, const int tentativas)
	: InterfacePadrao(limites), palavraSorteada(palavraSorteada)
{
	for (int i = 0; i < 6; i++) { // seis palavras/tentativas
		gradeDeChutes.emplace_back(Chutes()); 
	} 

	for (int j = 0; j < 6; j++) {
	    for (int i = 0; i < 6; i++) {
			// aloca memória para cada nó (Node), que representa uma letra da grade de chutes, para poder desenhá-la no inicio do jogo
			gradeDeChutes.at(j).insere(' '); 
	    }
	}

	resolvido = false;
	indiceDaPalavraAtual = 0;
	posicaoDeInserirLetra = 0;
	chaveDeVerificacao = false;
}

void GradeDeChutes::desenha(sf::RenderWindow& janela) 
{
	bool temElemento;

	// desenha a grade de palpites
	for (int linha = 0; linha < gradeDeChutes.size(); linha++) {
		for (int letra = 0; letra < 6; letra++) {
			gradeDeChutes.at(linha).pegaOElementoX(letra, temElemento)->Info.desenha(janela);
		}
	}
}

void GradeDeChutes::lidaComTeclaPressionada(const sf::Keyboard::Key tecla)
{
	int codigoDaTecla = static_cast<int>(tecla);
	if (codigoDaTecla >= 0 && codigoDaTecla <= 25) {
		tentaInserirLetra(static_cast<char>(codigoDaTecla + 'A')); // insere a letra
	}
	else if (tecla == sf::Keyboard::Backspace) {
		apagar(); // retira a letra chutada
	}
	else if (tecla == sf::Keyboard::Enter) {
		verificaChute(); // verifica o chute
		chaveDeVerificacao = true;
	}
}

void GradeDeChutes::tentaInserirLetra(const char letra)
{
	// se a posição onde inserir a letra for 6 (Mais que o número de letras possíveis) ou se já estiver resolvido, a operação não ocorre
	if (indiceDaPalavraAtual == gradeDeChutes.size() || resolvido  || posicaoDeInserirLetra == 6)
		return;

	bool deuCerto;
	gradeDeChutes.at(indiceDaPalavraAtual).insereLetra(letra, posicaoDeInserirLetra, deuCerto); // insere a letra chutada
	++posicaoDeInserirLetra;
}

void GradeDeChutes::apagar()
{
	// se a posição da letra é 0, ou seja, não tem letras chutas, ou se já está resolvido, não acontece a operação
	if (resolvido || posicaoDeInserirLetra == 0 || indiceDaPalavraAtual == gradeDeChutes.size())
		return;

	bool deuCerto;
	--posicaoDeInserirLetra;
	gradeDeChutes.at(indiceDaPalavraAtual).retiraLetra(' ', posicaoDeInserirLetra, deuCerto); // apaga a letra, ou seja, ela volta a guardar ' ' 
}

void GradeDeChutes::verificaChute()
{
	// se já estiver resolvido ou não houver as 6 letras chutads, a verificação não ocorre
	if (resolvido || posicaoDeInserirLetra != 6)
		return;

	char X;
	bool temElemento;

	int contadorDeResolvidos = 0; // utilizado para verificar o acerto ou erro da palavra sorteada

	int i = 0;
	gradeDeChutes.at(indiceDaPalavraAtual).pegaOPrimeiro(X, temElemento);
	while (temElemento) { // loop para percorrer cada letra (armazenada em um nó (Node)) da palavra chutada

		char palpite = X;

		if (palpite == palavraSorteada.at(i)) {
			gradeDeChutes.at(indiceDaPalavraAtual).pegaOElementoX(i, temElemento)->Info.setEstado(1); // posição correta
			++contadorDeResolvidos;
		}
		else {

			int contadorDeLetras = std::count(palavraSorteada.begin(), palavraSorteada.end(), palpite);
			if (contadorDeLetras > 0) {

				int posicaoEmQueDevePintar = 0;
				std::vector<int> foraDasPosicoes;
				for (int j = 0; j < 6; j++) {
					if (palpite == gradeDeChutes.at(indiceDaPalavraAtual).pegaOElementoX(j, temElemento)->Info.getLetra()) {
						if (palpite == palavraSorteada.at(j)) {
							posicaoEmQueDevePintar++;
						}
						else {
							foraDasPosicoes.emplace_back(j);
						}
					}
				}

				while (posicaoEmQueDevePintar + foraDasPosicoes.size() > contadorDeLetras) {
					foraDasPosicoes.pop_back();
				}

				if (std::find(foraDasPosicoes.begin(), foraDasPosicoes.end(), i) != foraDasPosicoes.end()) {
					gradeDeChutes.at(indiceDaPalavraAtual).pegaOElementoX(i, temElemento)->Info.setEstado(2); // posição errada
				}
				else {
					gradeDeChutes.at(indiceDaPalavraAtual).pegaOElementoX(i, temElemento)->Info.setEstado(0); // não está na palavra sorteada
				}
			}
			else {
				gradeDeChutes.at(indiceDaPalavraAtual).pegaOElementoX(i, temElemento)->Info.setEstado(0); // não está na palavra sorteada
			}
		}
		i++;
		gradeDeChutes.at(indiceDaPalavraAtual).pegaOProximo(X, temElemento);
	}

	++indiceDaPalavraAtual; // indice da palavra é incrementado para, em seguida, verificar uma nova palavra
	posicaoDeInserirLetra = 0; // setado para a primeira letra novamente
	if (contadorDeResolvidos == palavraSorteada.length()) {
		resolvido = true; // chute corresponde a palavra sorteada
	}
}

bool GradeDeChutes::getResolvido() const
{
	return resolvido;
}

bool GradeDeChutes::temMaisTentativas() const
{
	return indiceDaPalavraAtual < gradeDeChutes.size(); // retorna se há ou não mais tentativas disponíveis
}

// método utilizado para pintar o teclado da tela
std::vector<std::string> GradeDeChutes::getTodasRegras()
{

	std::vector<std::string> regras; // guarda as letras dos chutes com * (posição correta) e # (posição errada)

	bool temElemento;

	for (int i = 0; i < indiceDaPalavraAtual; i++) {   
		std::stringstream regraCorrente;
		for (int j = 0; j < palavraSorteada.length(); j++) {
			if (gradeDeChutes.at(i).pegaOElementoX(j, temElemento)->Info.getEstadoDoChute() == 1) { // posição correta
				regraCorrente << "*";
			}
			else if (gradeDeChutes.at(i).pegaOElementoX(j, temElemento)->Info.getEstadoDoChute() == 2) { // posião errada
				regraCorrente << "#";
			}
			regraCorrente << gradeDeChutes.at(i).pegaOElementoX(j, temElemento)->Info.getLetra();
		}
		regras.emplace_back(regraCorrente.str());
	}

	return regras;
}

bool GradeDeChutes::getChaveDeVerificacaoAnterior()
{
	bool resultado = chaveDeVerificacao;
	chaveDeVerificacao = false;
	return resultado;
}

std::string GradeDeChutes::getPalavraSorteada() const
{
	return palavraSorteada;
}

// desaloca memória dinamicamente
GradeDeChutes::~GradeDeChutes() {
	bool deuCerto;
	for (int linha = 0; linha < gradeDeChutes.size(); linha++) {
		for (int i = 0; i < 6; i++) {
			gradeDeChutes.at(linha).retira(deuCerto);
		}
	}
}
