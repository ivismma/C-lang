#include <stdio.h>

// Introdução/Demonstração básica
// Criando uma lista encadeada (na stack) e exibindo a lista.

typedef struct node{
	int valor;
	struct node *prox;
} Node;

void exibirLista(Node *topo);

int main(){
	Node a, b ,c; // a = topo | c = início.
	a.valor = 5;
	b.valor = 6;
	c.valor = 7;
	a.prox = &b;
	b.prox = &c;
	c.prox = NULL; // Início da lista, não aponta para nada.

	exibirLista(&a); // &a - topo.
	return 0;
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




