#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Biblioteca p/ valor booleano.

// Aula 5:
// Removendo ocorrências de um valor em uma lista encadeada (1ª f.) e ...
// removendo de uma lista encadeada todos os nós com o valor dado (2ª f.).
// Próxima aula: Método eficiente da 2ª função.

typedef struct node{
	int valor;
	struct node *prox;
} Node;

Node *del_primeiroEncontrado(Node *topo, int valor, bool *foiDeletado); // 1ª
Node *del_todasOcorrencias(Node *topo, int valor, int *qtd_deletada); // 2ª

void exibirLista(Node *topo);
Node *inserirTopo(Node *topo, int novoValor);

// Apaga da lista encadeada o primeiro valor encontrado que foi inserido para remoção.
Node *del_primeiroEncontrado(Node *topo, int valor, bool *foiDeletado){
	if(topo == NULL){ // 1º caso: Lista vazia.
		*foiDeletado = false;
		return NULL;
	} //2º caso: Primeiro valor (o topo) da lista é o valor a ser removido.
	if(topo->valor == valor){
		Node *aux = topo->prox; // Guarda o ponteiro para o próx. antes de liberar o topo a ser deletado.
		free(topo);             // Topo apagado.
		*foiDeletado = true;
		return aux;             // Retorna para onde o topo apagado apontava.
	} 
	//3º caso: O valor está no meio da lista.
	Node *atual = topo->prox;
	Node *anterior = topo;
	while(atual != NULL){
		if(atual->valor == valor){
			anterior->prox = atual->prox;
			free(atual);
			*foiDeletado = true;
			return topo;   // Topo permanece o mesmo, alteração foi no meio da lista.
		}
		anterior = atual;
		atual = atual->prox;
	}
	// 4º caso: A lista foi percorrida e o valor inserido não está na lista.
	*foiDeletado = false;
	return topo; // A lista encadeada permanece como estava.
}

// Apaga da lista encadeada todas os nós que possuem um dado valor.
Node *del_todasOcorrencias(Node *topo, int valor, int *qtd_deletada){
	Node *atual = topo;
	bool apagado = false;
	*qtd_deletada = 0;
	do{
		atual = del_primeiroEncontrado(atual, valor, &apagado);
		if(apagado) ++(*qtd_deletada);
	} while(apagado); // Enquanto não encontrar mais ocorrências na lista, continuar apagando.
	
	return atual; // Retorna topo/novo topo da lista que a função del_PrimeiroEncontrado retorna.
}

//////// Funções já estudadas ////////

Node *inserirTopo(Node *topo, int novoValor){
	Node *novoNode = calloc(1, sizeof(Node));
	novoNode->valor = novoValor;
	if(topo == NULL) return novoNode;
	else{
		novoNode->prox = topo;
		return novoNode;
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
// MAIN
int main(){
	Node *lista1_topo = NULL; // Declaração de lista vazia.
	
	exibirLista(lista1_topo);
	lista1_topo = inserirTopo(lista1_topo, 4);
	lista1_topo = inserirTopo(lista1_topo, 4);
	lista1_topo = inserirTopo(lista1_topo, 2);
	lista1_topo = inserirTopo(lista1_topo, 4);
	lista1_topo = inserirTopo(lista1_topo, 5);
	
	exibirLista(lista1_topo); // Antes
	int qtd_del;                           // Apagar todos os 4's da lista.
	lista1_topo = del_todasOcorrencias(lista1_topo, 4, &qtd_del);
	printf("----------\n");
	exibirLista(lista1_topo); // Depois
	printf("Quantidade de 4's removidos da lista: %d", qtd_del);
	
	return 0;
}
