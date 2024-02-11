#include <stdio.h>
#include <stdlib.h>

// Aula 3:
// Removendo o nó do topo de uma lista encadeada.
// Removendo o nó início de uma lista encadeada.

typedef struct node{
	int valor;
	struct node *prox;
} Node;

void exibirLista(Node *topo);
Node *inserirTopo(Node *topo, int novoValor);
Node *inserirInicio(Node *topo, int novoValor);
Node *deletarTopo(Node *topo);
Node *deletarInicio(Node *topo);

int main(){
	Node *lista1_topo = NULL; // Declaração de lista vazia.
	
	lista1_topo = inserirTopo(lista1_topo, 5);
	lista1_topo = inserirTopo(lista1_topo, 8);
	lista1_topo = inserirTopo(lista1_topo, 10);
	lista1_topo = inserirTopo(lista1_topo, 2);
	
	exibirLista(lista1_topo);
	lista1_topo = deletarInicio(lista1_topo); // Deleta o elemento 5.
	printf("Apos a remocao do inicio da lista:\n");
	exibirLista(lista1_topo);
	printf("----------\nNumero deletado: 5");
	
	return 0;
}

Node *deletarTopo(Node *topo){
	if(topo == NULL) return NULL; // Se lista vazia, retorna ponteiro nulo, não há o que remover nem para onde apontar.
	else{ // Lista não está vazia..
		Node *retorno = topo->prox;  // Topo da lista agora é o sucessor do elemento a ser removido.
		free(topo);                  // Topo antigo removido.
		return retorno;              // Retorna ponteiro para o novo topo da lista.
	}
}

Node *deletarInicio(Node *topo){
	if(topo == NULL) return NULL; // 1ª caso: lista vazia
	else if(topo->prox == NULL){ // 2º caso: Só existe um elemento na lista (o próximo aponta para nulo).
		free(topo);
		return NULL;
	} // 3º caso: A lista possui mais de um elemento, percorrer a lista..
	Node *atual = topo;
	Node *anterior = NULL; // Percorre a lista até o início sempre armazenando "anterior" para saber quem é o nó antes do último.
	
	while(atual->prox != NULL){
		anterior = atual;     // <-- Exemplo do comentário acima.
		atual = atual->prox;
	}
	anterior->prox = NULL; // O penúltimo passa a ser o último (último então não aponta para ninguém).
	free(atual); // Deleta o início (tail);
	return topo;
}

Node *inserirTopo(Node *topo, int novoValor){
	Node *novoNode = calloc(1, sizeof(Node));
	novoNode->valor = novoValor;
	if(topo == NULL) return novoNode; // Se lista vazia, o novo nó então é o primeiro.
	else{ // Lista não vazia
		novoNode->prox = topo;
		return novoNode;
	}
	
}

Node *inserirInicio(Node *topo, int novoValor){
	Node *novoNode = calloc(1, sizeof(Node));
	novoNode->valor = novoValor;
	if (topo == NULL) return novoNode; // Se lista vazia, o novo nó então é o primeiro.
	else{ // Lista não vazia
		Node *atual = topo;
		while(atual->prox != NULL) // Enquanto não chegou no INÍCIO da lista..
			atual = atual->prox;   // Percorre até.
		atual->prox = novoNode;    // Atual início da lista vira penúltimo e aponta para o novo inserido que é o último (início).
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
