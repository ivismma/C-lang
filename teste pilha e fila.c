#include <stdio.h>
#include <stdlib.h>

#define Pilha Lista 
#define Fila Lista
					// Impl. genérica usando mesma estrutura (Fila s/ ponteiro para início e fim).

typedef struct node{
	int valor;
	struct node *prox;
} Lista;

Pilha *empilhar(Pilha *topo, int valor);  // push()
Pilha *desempilhar(Pilha *topo);          // pop()

Fila *enfileirar(Fila *topo, int valor);
Fila *liberar(Fila *topo);

void exibirLista(Pilha *topo); // Exibição Lista encadeada

int main(void){
	
	Pilha *pilha = NULL;     // LIFO

	printf("Pilha:\n");
	pilha = empilhar(pilha, 3);
	pilha = empilhar(pilha, 5);
	pilha = empilhar(pilha, 10);
	pilha = empilhar(pilha, 4);
	pilha = desempilhar(pilha); // Desempilhar elem. 4.
	exibirLista(pilha);
	
	
	Fila *fila = NULL;        // FIFO
	printf("\n\nFila:\n");
	fila = enfileirar(fila, 5); 
	fila = enfileirar(fila, 3);
	fila = enfileirar(fila, 2);
	fila = enfileirar(fila, 1);
	fila = liberar(fila);       // Liberar elem. 5.
	exibirLista(fila);
	
	return 0;
}

Pilha *empilhar(Pilha *topo, int valor){
	Pilha *novo = (Pilha*) calloc(1,sizeof(Pilha));
	novo->valor = valor;
	
	if(topo == NULL) return novo;
	else{
		novo->prox = topo;
		return novo;
	}
}

Pilha *desempilhar(Pilha *topo){
	if(topo == NULL) return NULL;
	else{
		Pilha *prox = topo->prox;
		free(topo);
		return prox;
	}
}

Fila *enfileirar(Fila *topo, int valor){
	Fila *novo = (Fila*) calloc(1,sizeof(Fila));
	novo->valor = valor;
	
	if(topo == NULL) return novo;
	else{
	Fila *atual = topo;

	// Sem ponteiro para o final da fila (Percorre até fim da fila).
	
	while(atual->prox != NULL) atual = atual->prox;
	atual->prox = novo; // Adiciona no fim da fila.
	
	return topo; // Fila sempre retornará topo.
	}
}

Fila *liberar(Fila *topo){
	if(topo == NULL) return NULL;
	else{
		Fila *aux = topo->prox;
		free(topo);
		return aux;
	}
}

void exibirLista(Pilha *topo){
	if(topo == NULL) return;
	else{
		Pilha *atual = topo;
		
		while(atual != NULL){
			printf("%d\n", atual->valor);
			atual = atual->prox;
		}
		return;
	}
}
