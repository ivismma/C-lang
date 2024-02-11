#include <stdio.h>
#include <stdlib.h>

// Praticando criação de funções sem auxílio do material

typedef struct Lista{
	int valor;
	struct Lista *prox;
} tLista;

tLista *InserirnoTopo(tLista *topo, int novoValor);
void exibirLista(tLista *topo);
int tamanhoLista(tLista *topo);
tLista *InserirnoInicio(tLista *topo, int novoValor);

int main(){
	tLista *L = NULL;
	L = InserirnoTopo(L, 5);
	L = InserirnoTopo(L, 0);
	L = InserirnoTopo(L, 2);
	L = InserirnoTopo(L, 1);
	L = InserirnoInicio(L, 10);
	L = InserirnoInicio(L, 15);
	exibirLista(L);
	printf("\nTamanho da lista: %d", tamanhoLista(L));
	
	return 0;
}

int tamanhoLista(tLista *topo){
	tLista *atual = topo;
	int i = 0;
	
	while(atual){ // atual != NULL
		++i;
		atual = atual->prox;
	}
	return i;
}

void exibirLista(tLista *topo){
	tLista *atual = topo;
	
	printf("Lista: TOPO -> ");
	while(atual){ // atual != NULL
		printf("%d ", atual->valor);
		atual = atual->prox;
	}
	printf("<- INICIO");
}

tLista *InserirnoTopo(tLista *topo, int novoValor){
	tLista *Node = calloc(1, sizeof(tLista));
	Node->valor = novoValor;
	if(!topo) return Node;
	else{
		Node->prox = topo;
		return Node;
	}
}

tLista *InserirnoInicio(tLista *topo, int novoValor){
	tLista *novoNode = calloc(1, sizeof(tLista));
	novoNode->valor = novoValor;
	tLista *atual = topo;
	
	if(!topo) /*topo == NULL*/ return novoNode;
	while(atual->prox != NULL) atual = atual->prox;
	atual->prox = novoNode;
	return topo;
}
