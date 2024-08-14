#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // exit()

// Impl. pilha de alocação **estática**

#define PILHA_TAM 50

// armazena ints.
typedef struct{
	int dados[PILHA_TAM];
	int topo; // index do topo (-1 significa vazia).
} Pilha;

// gerenciamento
void inicializaPilha(Pilha *pilha);
bool empilhar(Pilha *pilha, int dado);
int desempilhar(Pilha *pilha);
void exibePilha(Pilha pilha);
void esvaziaPilha(Pilha *pilha);

int main(void){

	Pilha pilha1;
	inicializaPilha(&pilha1);
	
	empilhar(&pilha1, 5);
	empilhar(&pilha1, 4);
	empilhar(&pilha1, 3);
	exibePilha(pilha1);
	
	printf("\nDesempilhando...\n--> %d\n\n", desempilhar(&pilha1));
	
	exibePilha(pilha1);
	
	return 0;
}


void inicializaPilha(Pilha *pilha){
	pilha->topo = -1;
}

bool empilhar(Pilha *pilha, int dado){
	if(pilha->topo < PILHA_TAM-1){ // verif. se pilha está cheia.
		pilha->dados[++pilha->topo] = dado; // empilha em topo+1 pós incrementando.
		return true;
	}
	return false;
}

int desempilhar(Pilha *pilha){
	if(pilha->topo == -1) 
		exit(1); // acesso inválido.
	else
		return pilha->dados[pilha->topo--]; // obtem dado e atualiza topo.
}

// exibe do topo pra baixo.
void exibePilha(Pilha pilha){
	if(pilha.topo == -1){
		printf("Pilha vazia\n");
		return;
	}
	
	puts("------ TOPO ------");
	for(int i = pilha.topo; i >= 0; --i)
		printf("\t%d\n", pilha.dados[i]);
	puts("------ FIM ------");
}

void esvaziaPilha(Pilha *pilha){
	inicializaPilha(pilha);
}
