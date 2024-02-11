#include <stdio.h>
#include <stdlib.h>

// Desafio 2:
// Crie uma função que duplique uma lista encadeada.
// A funçao deverá receber a Lista encadeada a ser duplicada.
// A função irá alocar e criar os nós, os mesmos nós deverão conter os mesmos elementos da lista origem.
// A função retornará o topo da lista duplicada.

typedef struct node{
	int valor;
	struct node *prox;
} Node;


// Node *duplicaLista(Node *topo_L1, Node *topo_L2);   ITERATIVO
Node *duplicaLista(Node *topo);
Node *inserirInicio(Node *topo, int novoValor);
void exibirLista(Node *topo);


int main(void){
	Node *Lista1 = NULL, *Lista2 = NULL;

	printf("Lista 1:\n");
	Lista1 = inserirInicio(Lista1, 5);
	Lista1 = inserirInicio(Lista1, 4);
	Lista1 = inserirInicio(Lista1, 0);
	Lista1 = inserirInicio(Lista1, 8);
	Lista1 = inserirInicio(Lista1, 11);
	exibirLista(Lista1);
	printf("\nLista 2:\n");
	Lista2 = duplicaLista(Lista1);
	exibirLista(Lista2);
	return 0;
}

Node *duplicaLista(Node *topo){
	if(topo == NULL) return NULL;
	
	Node *novo = (Node*) calloc(1,sizeof(Node));
	novo->valor = topo->valor;
	novo->prox = duplicaLista(topo->prox);
	return novo;
}

// Iterativo..
/*Node *duplicaLista(Node *topo_L1, Node *topo_L2){
	Node *atual_L1 = topo_L1;
	Node *atual_L2 = (Node*) calloc(1,sizeof(Node));
	topo_L2 = atual_L2;
	while(atual_L1->prox != NULL){
		atual_L2->valor = atual_L1->valor;
		Node *novo = (Node*) calloc(1,sizeof(Node));
		atual_L2->prox = novo;
		atual_L2 = novo;
		atual_L1 = atual_L1->prox;
	}
	// Último nó:
	atual_L2->valor = atual_L1->valor;
	
	return topo_L2;
}*/





Node *inserirInicio(Node *topo, int novoValor){
	Node *novoNode = calloc(1, sizeof(Node)); 
	novoNode->valor = novoValor;
	if (topo == NULL) return novoNode;
	else{
		Node *atual = topo;
		while(atual->prox != NULL) 
			atual = atual->prox; 
		atual->prox = novoNode; 
		return topo;
	}
}

void exibirLista(Node *topo){
	Node *atual;
	atual = topo;
	int i = 0;
	
	while(atual != NULL){
		printf("Node %d: %d\n", i, atual->valor);
		++i;
		atual = atual->prox;
	}
}
