#include "Chutes.h"

// construtor: aloca mem�ria dinamicamente para um n� Header/Atual
Chutes::Chutes() {
	Header = new Node;

	Header->Dir = Header;
	Header->Esq = Header;
	Atual = Header;
}

// insere: Aloca mem�ria dinamicamente para um novo N� e seta a informa��o do mesmo com X. Pode-se considerar que opera��o sempre ocorre com sucesso por se 
// tratar de aloca��o din�mica
void Chutes::insere(char X) {
	Node* Aux = new Node;

	Aux->Dir = Header;
	Aux->Esq = Header->Esq;

	Header->Esq->Dir = Aux;
	Header->Esq = Aux; 

	Aux->Info.setLetra(X);
}
 
// insereLetra: modifica a informa��o (Info) do N� na posi��o especificada no par�metro para conter X. deuCerto recebe true se for uma posi��o v�lida e false
// caso contr�rio
void Chutes::insereLetra(char X, int posicao, bool& deuCerto) {
	int i = 0;

	Atual = Header->Dir;

	if ((posicao > 6) || (Atual == Header)) { // se a posi��o for maior que o n�mero de n�s com letras ou se n�o houver n�s com letra
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

// retiraLetra: substitui a letra armazenada no campo Info do �ltimo N� por vazio (' '). deuCerto recebe true, se houver um ou mais Node diferente de Header ou 
// false caso contr�rio
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

	if ((posicao > 6) || (Atual == Header)) { // se a posi��o for maior que o n�mero de n�s com letras ou se n�o houver n�s com letra
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

// retira: retira o ultimo N� da lista, desalocando mem�ria dinamicamente
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

// pegaOPrimeiro: retorna em X a letra do primeiro N� (aquele a direita do Header) da lista.
void Chutes::pegaOPrimeiro(char& X, bool& temElemento) {
	Atual = Header->Dir;
	if (Atual != Header) {
		temElemento = true; // existe um ou mais elemento na lista
		X = Atual->Info.getLetra();
	}
	else {
		temElemento = false; // n�o existe nenhum elemento na lista
	}
}

// pegaOProximo: retorna em X a letra do pr�ximo N� (de acordo o N� Atual) da lista.
void Chutes::pegaOProximo(char& X, bool& temElemento) {
	Atual = Atual->Dir;
	if (Atual != Header) {
		temElemento = true;
		X = Atual->Info.getLetra(); // existe um pr�ximo elemento na lista
	}
	else {
		temElemento = false;  // n�o existe um pr�ximo elemento na lista (Atual = Header)
	}
}

// pegaOElementoX: retorna o Node da posi��o determinada no par�metro posicao da lista. deuCerto recebe true se for uma posi��o v�lida e false
Node* Chutes::pegaOElementoX(int posicao, bool& deuCerto) {
	int i = 0;
	Atual = Header->Dir;

	if ((posicao > 6) || (Atual == Header)) { // se a posi��o for maior que o n�mero de n�s com letras ou se n�o houver n�s com letra
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