#include <string>
#include <random>

#define NUM_PALAVRAS 54

/*
   Classe BancoDePalavras: Armazena o banco de palavras, um vetor com palavras relacionadas a computação que será sorteado para gerar a palavra que deverá ser
advinhada pelo jogador
*/      

class BancoDePalavras {
public:
	BancoDePalavras(std::default_random_engine& maquinaAleatoria);
	virtual ~BancoDePalavras() = default;

	std::string pegaPalavraAleatoria() const;

private:
	std::string* palavras;

	std::default_random_engine& maquinaAleatoria;

	void carregaBancoDePalavras();
};
