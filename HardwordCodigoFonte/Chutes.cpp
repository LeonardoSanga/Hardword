#include "Chutes.h"

// construtor: aloca memória dinamicamente para um nó Header/Atual
Chutes::Chutes() {
	Header = new Node;

	Header->Dir = Header;
	Header->Esq = Header;
	Atual = Header;
}

// insere: Aloca memória dinamicamente para um novo Nó e seta a informação do mesmo com X. Pode-se considerar que operação sempre ocorre com sucesso por se 
// tratar de alocação dinâmica
void Chutes::insere(char X) {
	Node* Aux = new Node;

	Aux->Dir = Header;
	Aux->Esq = Header->Esq;

	Header->Esq->Dir = Aux;
	Header->Esq = Aux; 

	Aux->Info.setLetra(X);
}
 
// insereLetra: modifica a informação (Info) do Nó na posição especificada no parâmetro para conter X. deuCerto recebe true se for uma posição válida e false
// caso contrário
void Chutes::insereLetra(char X, int posicao, bool& deuCerto) {
	int i = 0;

	Atual = Header->Dir;

	if ((posicao > 6) || (Atual == Header)) { // se a posição for maior que o número de nós com letras ou se não houver nós com letra
		deuCerto = false;
	}
	else {
		deuCerto = true;

		while (Atual != Header && i < posicao) {
			i++;
			Atual = Atual->Dir;
		}

		Atual->Info.setLetra(X);
	}
}

// retiraLetra: substitui a letra armazenada no campo Info do último Nó por vazio (' '). deuCerto recebe true, se houver um ou mais Node diferente de Header ou 
// false caso contrário
void Chutes::retiraLetra(char X, int posicao, bool& deuCerto) {
	//if (Header->Esq != Header) {
	//	deuCerto = true; 
	//	Header->Esq->Info.setLetra(' ');
	//}
	//else {
	//	deuCerto = false;
	//}
	int i = 0;
	Atual = Header->Dir;

	if ((posicao > 6) || (Atual == Header)) { // se a posição for maior que o número de nós com letras ou se não houver nós com letra
		deuCerto = false;
	}
	else {
		deuCerto = true;
		while (Atual != Header && i < posicao) {
			i++;
			Atual = Atual->Dir;
		}
	}
	Atual->Info.setLetra(' ');
}

// retira: retira o ultimo Nó da lista, desalocando memória dinamicamente
void Chutes::retira(bool& deuCerto) {
	if (Header->Esq != Header) { // se tem Elementos com letras
		deuCerto = true;

		Node* Aux = Header->Esq;

		Header->Esq = Aux->Esq;
		Aux->Esq->Dir = Header;

		delete Aux;
		Aux = NULL;
	}
	else {
		deuCerto = false;
	}
}

// pegaOPrimeiro: retorna em X a letra do primeiro Nó (aquele a direita do Header) da lista.
void Chutes::pegaOPrimeiro(char& X, bool& temElemento) {
	Atual = Header->Dir;
	if (Atual != Header) {
		temElemento = true; // existe um ou mais elemento na lista
		X = Atual->Info.getLetra();
	}
	else {
		temElemento = false; // não existe nenhum elemento na lista
	}
}

// pegaOProximo: retorna em X a letra do próximo Nó (de acordo o Nó Atual) da lista.
void Chutes::pegaOProximo(char& X, bool& temElemento) {
	Atual = Atual->Dir;
	if (Atual != Header) {
		temElemento = true;
		X = Atual->Info.getLetra(); // existe um próximo elemento na lista
	}
	else {
		temElemento = false;  // não existe um próximo elemento na lista (Atual = Header)
	}
}

// pegaOElementoX: retorna o Node da posição determinada no parâmetro posicao da lista. deuCerto recebe true se for uma posição válida e false
Node* Chutes::pegaOElementoX(int posicao, bool& deuCerto) {
	int i = 0;
	Atual = Header->Dir;

	if ((posicao > 6) || (Atual == Header)) { // se a posição for maior que o número de nós com letras ou se não houver nós com letra
		deuCerto = false;
	}
	else {
		deuCerto = true;
		while (Atual != Header && i < posicao) {
			i++;
			Atual = Atual->Dir;
		}
	}

	return Atual;
}