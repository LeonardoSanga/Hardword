#pragma once

#include "Node.h"

/*
  Classe chutes: possui dois ponteiros para nós (Node) e executa operações de inserção, retirada e busca de letras. As letras são as informações 
 (Info: LetrasDoChute) armazedas em cada Node 
*/
 
class Chutes {
public:
	Chutes(); // construtor/Cria

	// métodos 
	void insere(char X);

	void insereLetra(char X, int posicao, bool& deuCerto);

	void retira(bool& deuCerto);

	void retiraLetra(char X, int posicao, bool& deuCerto);

	void pegaOPrimeiro(char& X, bool& temElemento);

	void pegaOProximo(char& X, bool& temElemento);

	Node* pegaOElementoX(int posicao, bool& deuCerto);
	
private:
	Node* Header;
	Node* Atual;
};
