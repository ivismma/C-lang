#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Implementações de pilha em C.   LIFO.

// Estruturas definidas(Nó e Pilha):
typedef struct node{
	int dado;
	struct node *prox;
} Node;

typedef struct{
	Node *topo;
} Pilha;

// Funções de gerenciamento:
Node *alocarNode(int valor); // Alocar memória p/ nó
Pilha *inicializarPilha(Pilha *pilha); // Alocar e inicializar estrutura Pilha.
Pilha *esvaziarPilha(Pilha *pilha);    // Desalocar/liberar todos elementos da pilha.
bool desalocarPilha(Pilha **pilha);   // Desalocar a struct Pilha, se a pilha não estiver vazia, limpa antes.
Pilha *empilhar(Pilha *pilha, int valor);  // push(), Insere nó no topo.
int desempilhar(Pilha **pilha); // pop(), Retorna o valor desempilhado e atualiza o topo da pilha com *ptr duplo.
int dadoTopo(Pilha *pilha); // Retornar dado atual do topo da pilha (sem desempilhar).
int tamanhoPilha(Pilha *pilha); // Quantidade de nós (elementos) da pilha.
void exibirPilha(Pilha *pilha); // Verifica se pilha foi inicializada ou está vazia. Exibe a pilha verticalmente. 
// Funções c/ parâmetros que usam ponteiro duplo: Função precisa atualizar o ponteiro na main().

int main(void){
	Pilha *pilha1 = NULL, *pilha2 = NULL;
	int n1, n2;
	
	pilha1 = inicializarPilha(pilha1);
	pilha2 = inicializarPilha(pilha2);
	
	pilha1 = empilhar(pilha1, 5);       // Pilha 1: 1 3 5.
	pilha1 = empilhar(pilha1, 3);
	pilha1 = empilhar(pilha1, 1);
	pilha2 = empilhar(pilha2, 10);      // Pilha 2: 10
	n1 = dadoTopo(pilha1);
	n2 = desempilhar(&pilha2);          // Pilha 2: Vazia.
	printf("n1 + n2 = %d\n", n1+n2);    // 1 + 10.
	
	desalocarPilha(&pilha2);
	exibirPilha(pilha1);
	desalocarPilha(&pilha1);
	printf("Apos esvaziar e desalocar...\n");
	exibirPilha(pilha1);
	
	return 0;	
}

Node *alocarNode(int valor){
	Node *novo = calloc(1,sizeof(Node));
	if(novo == NULL){
		printf("Falha na alocacao de memoria.");
		exit(1);
	}
	novo->dado = valor;
	return novo;
}

Pilha *inicializarPilha(Pilha *pilha){
	pilha = malloc(sizeof(Pilha));
	if(pilha == NULL){
		printf("Falha na alocacao da pilha.");
		exit(2);
	} 
	pilha->topo = NULL;
	return pilha;
}

Pilha *esvaziarPilha(Pilha *pilha){ // Esvazia nós da pilha deixando-a vazia. Continuará inicializada.
	if(pilha == NULL){
		printf("Pilha nao inicializada\n");
		return NULL;
	} 
	if(pilha->topo == NULL){
		printf("A pilha ja esta vazia.\n");
		return NULL;
	}
	Node *atual = pilha->topo;
	while(atual != NULL){
		Node *aux = atual;
		atual = atual->prox;
		free(aux); // Desalocar nó.
	}
	pilha->topo = NULL;
	return pilha;
}

bool desalocarPilha(Pilha **pilha){ // Desaloca a pilha. p/ readicionar elementos, inicializá-la novamente.
	if(*pilha == NULL) return false;
	if( (*pilha)->topo != NULL){
		// Se pilha não está vazia, liberar nós (evitar vazamento de memória)
		*pilha = esvaziarPilha(*pilha);
	}
	free((*pilha));
	*pilha = NULL;
	return true;
}

Pilha *empilhar(Pilha *pilha, int valor){
	if(pilha == NULL){
		printf("Pilha nao inicializada.\n");
		return NULL;
	}
	Node *novo = alocarNode(valor);
	if(pilha->topo == NULL) pilha->topo = novo;
	else{
		novo->prox = pilha->topo;
		pilha->topo = novo;
	}
	
	return pilha;
}

int desempilhar(Pilha **pilha){
	if(*pilha == NULL || (*pilha)->topo == NULL){
		printf("Tentativa de retorno em pilha vazia/nao inicializada");
		exit(3);
	}
	int dado = (*pilha)->topo->dado;
	Node *aux = (*pilha)->topo->prox;
	free((*pilha)->topo);
	(*pilha)->topo = aux;
	
	return dado;
}

int tamanhoPilha(Pilha *pilha){
	if(pilha == NULL || pilha->topo == NULL){
		printf("Tentativa de retorno em pilha vazia/nao inicializada");
		exit(3);
	}
	Node *atual = pilha->topo;
	int cont = 0;
	for(; atual != NULL; atual = atual->prox)
		++cont;
	
	return cont;
}

int dadoTopo(Pilha *pilha){
	if(pilha == NULL || pilha->topo == NULL){
		printf("Tentativa de retorno em pilha vazia/nao inicializada");
		exit(3); 
	}
	return pilha->topo->dado;
}

void exibirPilha(Pilha *pilha){
	if(pilha == NULL){
		printf("Pilha nao inicializada.\n");
		return;
	}
	printf("Pilha: ");
	if(pilha->topo == NULL){
		printf("Vazia.\n");
		return;
	}
	printf("\n\n(Topo)\n");
	Node *atual = pilha->topo;
	while(atual != NULL){
		printf("%d\n", atual->dado);
		atual = atual->prox;
	}
	printf("(Inicio)\n");
}
