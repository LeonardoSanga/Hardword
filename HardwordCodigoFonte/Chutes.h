#pragma once

#include "Node.h"

/*
  Classe chutes: possui dois ponteiros para n�s (Node) e executa opera��es de inser��o, retirada e busca de letras. As letras s�o as informa��es 
 (Info: LetrasDoChute) armazedas em cada Node 
*/
 
class Chutes {
public:
	Chutes(); // construtor/Cria

	// m�todos 
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
