#include <stdio.h>
#include <stdlib.h>

// Desafio 1:
// Crie uma função que soma elementos entre duas listas encadeadas.
// Se uma lista for maior que a outra, os nós restantes devem permanecer normalmente.
// A lista que terá os nós somados será a maior.

typedef struct node{
    int valor;
    struct node *prox;
} Node;

Node *inserirInicio(Node *topo, int novoValor);
void exibirLista(Node *topo);
int tamanhoLista(Node *topo);
// int somaListas(Node *topo1, Node *topo2); <-- Método menos eficiente
void somaListas(Node *Lista1, Node *Lista2); // Recursivo

int main(){
    Node *Lista1 = NULL;
    Node *Lista2 = NULL;
    Lista1 = inserirInicio(Lista1, 2);
    Lista1 = inserirInicio(Lista1, 4);
    Lista1 = inserirInicio(Lista1, 4);
    Lista1 = inserirInicio(Lista1, 6);
	exibirLista(Lista1);
    printf("---------------\n");
    Lista2 = inserirInicio(Lista2, 0);
    Lista2 = inserirInicio(Lista2, 1);
    Lista2 = inserirInicio(Lista2, 5);
    Lista2 = inserirInicio(Lista2, 4);
    Lista2 = inserirInicio(Lista2, 9);
    exibirLista(Lista2);
    printf("\nLista somada:\n");
    somaListas(Lista1, Lista2);
	exibirLista(Lista1);
    
    return 0;
}

// A função retorna qual das listas virou o resultado da soma (1 ou 2), sempre será a maior, ou Lista 1 caso tamanhos iguais.
// A lista 1 será a lista somada caso o tamanho da Lista 1 > Lista2 ou Lista 1 == Lista2
// A lista 2 será a lista somada caso o tamanho da Lista 2 > Lista1

/*   Método menos eficiente, mas intuitivo:

int somaListas(Node *topo1, Node *topo2){
	Node *atual1 = topo1;
	Node *atual2 = topo2;
	short int 
	tam1 = tamanhoLista(topo1), 
	tam2 = tamanhoLista(topo2);
	if(tam1 > tam2){
		CASO_INICIAL: // Acontecerá se Lista1 > Lista2 ou Lista1 == Lista2
		while(atual2 != NULL){
			atual1->valor += atual2->valor;
			atual1 = atual1->prox;
			atual2 = atual2->prox;
		}
		return 1; 
	}
	else if(tam1 < tam2){
		while(atual1 != NULL){
			atual2->valor += atual1->valor;
			atual1 = atual1->prox;
			atual2 = atual2->prox;
		}
		return 2;
	}                       // else (tam Lista 1 == tam Lista 2)
	else goto CASO_INICIAL;
} */

// Método recursivo:

void somaListas(Node *Lista1, Node *Lista2){
	if (Lista1 == NULL || Lista2 == NULL) return;
	
	Lista1->valor += Lista2->valor;
	somaListas(Lista1->prox, Lista2->prox);
}








int tamanhoLista(Node *topo){ // Versão ITERATIVA - Tamanho da lista.
	Node *atual = topo;
	int i = 0;
	
	while(atual){ // Enquanto nó existe.
		++i;
		atual = atual->prox;
	}
	return i;
}

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
