#include "header.h"

void inicializarBaralho(Node **topo){
	if(*topo != NULL){
		printf("Baralho já inicializado!");
		exit(1);
	}
	const Carta coringa = {0, -1};
	Node *novo = calloc(1, sizeof(Node));
	novo->carta = coringa;
	*topo = novo;
	return;
}

// Colocar carta no baralho.
void empilhar(Node **topo, Carta carta){
	Node *novo = calloc(1, sizeof(Node));
	novo->carta = carta;
	if(*topo == NULL){
		*topo = novo;
	}
	else{
		novo->prox = *topo;
		*topo = novo;
	}
	return;
}

// Pegar carta do baralho.
Carta desempilhar(Node **topo){
	if(*topo == NULL){
		printf("Baralho não inicializado corretamente.");
		exit(2);
	} 
	Carta carta = (*topo)->carta;
	Node *aux = *topo;
	*topo = (*topo)->prox;
	free(aux);
	return carta;
}

Pilha *esvaziarPilha(Pilha *topo){
	if(topo == NULL)
		return NULL;
	else
		desempilhar(&topo);
		esvaziarPilha(topo->prox);
}

// Debugging:
/*
void exibirPilha(Node *baralho_topo){
	if(baralho_topo == NULL) return;
	Node *atual = baralho_topo;
	do{
		exibirCarta(atual->carta);
		atual = atual->prox;
	} while(atual != NULL);
}

int qtdElementos(Node *baralho_topo){
	if(baralho_topo == NULL) return 0;
	int cont = 0;
	Node *atual = baralho_topo;
	do{
		atual = atual->prox;
		cont++;
	} while(atual != NULL);
	return cont;
}*/
