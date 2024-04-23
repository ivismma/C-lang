#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
	int valor;
	struct node *prox;	
} Node;

void bubbleSort(Node *topo);
void exibirLista(Node *topo);
void inserirTopo(Node **topo, int novoValor);

int main(void){
	Node* pilha = NULL;
	
	inserirTopo(&pilha, 1);
	inserirTopo(&pilha, 6);
	inserirTopo(&pilha, 4);
	inserirTopo(&pilha, 2);
	inserirTopo(&pilha, 3);
	inserirTopo(&pilha, 5);
	bubbleSort(pilha);
	exibirLista(pilha);
	
	return 0;
}

void bubbleSort(Node *topo){
	if(!topo || !topo->prox) return;
	
	do{                      // Bubble Sort
		bool ordenado = true;
		Node *atual = topo;
		Node *anterior = NULL;
		
		while(atual->prox != NULL){
			anterior = atual;
			atual = atual->prox;
			if(atual != NULL){
				if(anterior->valor > atual->valor){
					int aux = anterior->valor;
					anterior->valor = atual->valor;
					atual->valor = aux;
					ordenado = false;
				}
			}
		}
	} while(!ordenado);
}

void inserirTopo(Node **topo, int novoValor){
	Node *novoNode = calloc(1, sizeof(Node));
	novoNode->valor = novoValor;
	if(*topo == NULL) 
		*topo = novoNode;
	else{
		novoNode->prox = *topo;
		*topo = novoNode;
	}
}

void exibirLista(Node *topo){
	Node *atual = topo;
	int i = 0;
	
	while(atual != NULL){
		printf("Node %d: %d\n", i++, atual->valor);
		atual = atual->prox;
	}
}
