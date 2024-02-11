#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Aula 10:
// Teste de performance - Tempo de realização de tarefa
// Lista encadeada vs Vetor alocado dinâmicamente.

typedef struct node{
	int valor;
	struct node *prox;
} Node;

Node *inserirTopo(Node *topo, int novoValor);
Node *deletarTopo(Node *topo);


int main(void){
	int qtd_elementos = 3000;
	clock_t t1, t2;
	
	int *vetor = malloc(qtd_elementos * sizeof(int));
	for(int i = 0; i <= qtd_elementos; ++i)
		vetor[i] = i;
	
	t1 = clock();
	for(int i = 1; i < qtd_elementos;++i){
		int *novoVetor = malloc((qtd_elementos - i) * sizeof(int));
		for(int j = 0; j < qtd_elementos - i;++j)
			novoVetor[j] = vetor[j+i];
	free(vetor);
	vetor = novoVetor;
	}
	t2 = clock();
	printf("Tempo com vetor alocado dinâmicamente: %f segundos.\n", (double)(t2-t1)/CLOCKS_PER_SEC);
	
	Node *Lista = NULL;
	for(int i = 0; i < qtd_elementos; ++i) Lista = inserirTopo(Lista, i);
	
	t1 = clock();
	for(int i = 0; i < qtd_elementos; ++i) Lista = deletarTopo(Lista);
	t2 = clock();
	printf("Tempo com Lista encadeada: %f segundos.\n", (double)(t2-t1)/CLOCKS_PER_SEC);
	
	return 0;
}


Node *inserirTopo(Node *topo, int novoValor){
	Node *novoNode = calloc(1, sizeof(Node)); // Novo nó.
	novoNode->valor = novoValor;
	if(topo == NULL) return novoNode; // Se lista vazia, o novo nó é o primeiro elemento.
	else{
		novoNode->prox = topo;
		return novoNode;
	}
}

Node *deletarTopo(Node *topo){
	if(topo == NULL) return NULL; // Se lista vazia, retorna ponteiro nulo, não há o que remover nem para onde apontar.
	else{ // Lista não está vazia..
		Node *retorno = topo->prox;  // Topo da lista agora é o sucessor do elemento a ser removido.
		free(topo);                  // Topo antigo removido.
		return retorno;              // Retorna ponteiro para o novo topo da lista.
	}
}
