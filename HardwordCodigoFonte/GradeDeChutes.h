#pragma once

#include "InterfacePadrao.h"
#include "Chutes.h"

/*
   Classe GradeDeChutes: trate-se da grade de chutes exibida na parte superior da tela, desenhando as letra chutadas conforme são escritas. Cuida da inserção e
retirada de letras e da verificação do estado desses chutes de acordo com a palavras sorteada. Cria o conjunto de "regars" utilizada para pintar o teclado 
da tela
*/

class GradeDeChutes : public InterfacePadrao
{
public:
	
	GradeDeChutes(const sf::IntRect& limites, const sf::Font& fonte, const std::string& palavraSorteada, const int tentativas); // construtor
	~GradeDeChutes(); // destrutor

	// métodos

	virtual void atualiza(const float tempoDelta) override {};

	virtual void desenha(sf::RenderWindow& janela) override;
	
	virtual void lidaComTeclaPressionada(const sf::Keyboard::Key tecla) override;

	void tentaInserirLetra(const char letra);

	void apagar();

	void verificaChute();

	bool getResolvido() const;

	bool temMaisTentativas() const;

	std::vector<std::string> getTodasRegras();

	bool getChaveDeVerificacaoAnterior();

	std::string getPalavraSorteada() const;

private:

	std::vector<Chutes> gradeDeChutes; // vetor com 6 objtos da classe chutes (lista cadastral), os quais possuem nós (estruturas chamadas Nodes) 
// que possuem um objeto da classe LetrasDoChute no compo Info. Cada objeto chutes representa uma palavra chutada

	int posicaoDeInserirLetra; // posição onde inserir a letra chutada

	int indiceDaPalavraAtual; // indice da palavra atual

	bool resolvido; // informa se a palavra foi resolvida com sucesso ou não

	bool chaveDeVerificacao;

	const std::string palavraSorteada;
};
