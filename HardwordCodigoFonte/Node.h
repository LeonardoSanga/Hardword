#pragma once

#include "LetrasDoChute.h"

/*
  Estrutura Node: possui dois ponteiros para Node, um para um Node a esquerda e outro para um Node a direita. Além disso, possui um objeto da classe 
LetrasDoChute
*/

struct Node {
	LetrasDoChute Info;
	Node* Dir;
	Node* Esq;
};
