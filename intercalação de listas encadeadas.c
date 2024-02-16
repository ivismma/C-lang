#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

             // Nó
typedef struct node{
	int valor;
	struct node *prox;
} Node;

typedef struct{ // Lista.
	Node *topo; // nó do topo.
} Lista;

Node *inserir(Node *topo, int valor);
bool intercalaLista(Node *topo1, Node* topo2);
void exibirLista(Node *topo);

// Intercalação entre duas listas encadeadas.

// Sem checagem de tamanho de cada listas, ou seja
// Fim de uma lista se dá quando um dos nós forem nulos.

int main(void){
	Lista lista1, lista2;
	
	lista1.topo = inserir(lista1.topo, 5); // Lista 1:
	lista1.topo = inserir(lista1.topo, 3); // 1 3 5
	lista1.topo = inserir(lista1.topo, 1);
	lista2.topo = inserir(lista2.topo, 6); // Lista 2:
	lista2.topo = inserir(lista2.topo, 4); // 2 4 6
	lista2.topo = inserir(lista2.topo, 2);
	
	if(!intercalaLista(lista1.topo, lista2.topo))
		printf("As duas listas estao vazias.");
	
	return 0;
}

// Se uma lista for vazia, irá imprimir somente a lista que contem elementos
// Se uma for maior que a outra, intercalará normalmente e em seguida
// imprimirá a o resto da lista maior.
// Se ambos forem vazias, retornará falso.
bool intercalaLista(Node *topo1, Node* topo2){
	if(!topo1 && !topo2) return false;
	int cont = 0;
	Node *atual1 = topo1, *atual2 = topo2;
	
	while(atual1 != NULL && atual2 != NULL){
		if(cont%2 == 0){ // Lista 1
			printf("%d ", atual1->valor);
			atual1 = atual1->prox;
		}
		else{            // Lista 2
			printf("%d ", atual2->valor);
			atual2 = atual2->prox;
		}
		++cont;
	}
	
	// Verificar se ainda resta algo (tamanhos diferentes).
	if(atual1 != NULL && atual2 == NULL){ // Lista 1 > Lista 2
		while(atual1 != NULL){
			printf("%d " , atual1->valor);
			atual1 = atual1->prox;
		}
	}                                    // Lista 2 > Lista 1
	else if(atual1 == NULL && atual2 != NULL){
		while(atual2 != NULL){
			printf("%d " , atual2->valor);
			atual2 = atual2->prox;
		}
	}
	
	return true; // OK
}



// Outras funções ...

void exibirLista(Node *topo){
	if(topo == NULL) return;
	Node *atual = topo;
	
	while(atual != NULL){
		printf("%d ", atual->valor);
		atual = atual->prox;
	}
	return;
}

// No topo...
Node *inserir(Node *topo, int valor){
	Node *novo = (Node *) malloc(sizeof(Node));
	novo->valor = valor;
	novo->prox = topo;
	
	return novo;
}
