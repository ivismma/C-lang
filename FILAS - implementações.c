#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Implementações de uma fila dinâmica.

// Estruturas (Nó e Fila):
typedef struct node{ 
	int dado;
	struct node *prox;
} Node;

typedef struct fila{  
	Node* frente; // Nó do início da fila.
	Node* fim;    // Nó do fim da fila.
} Fila;

// Funções de gerenciamento: 
Node *alocarNode(int valor); // Criar nó.
Fila *inicializarFila();
bool filaVazia(Fila *fila); // Checa se fila está vazia ou se não não existe mais/não inicializada.
void exibirFila(Fila *fila); // Exibição por ordem de chegada (FIFO).
void enfileirar(Fila *fila, int valor); // enfileirar = queue() | liberar = dequeue()         
int liberar(Fila *fila); // Liberar e retornar valor liberado. 
void apagarFila(Fila **fila); // Varre a fila limpando-a, define ptr da fila como nulo usando ponteiros de ponteiros.
int dadoFrente(Fila *fila); // Dado contido na frente da fila.
int dadoFim(Fila *Fila);    // Dado contido no fim da fila.
int tamanhoFila(Fila *fila); // Retorna qtd de nós da fila.

// Testes.
int main(void){
	Fila *fila1 = inicializarFila();
	
	enfileirar(fila1, 1);
	enfileirar(fila1, 2);
	enfileirar(fila1, 3);
	enfileirar(fila1, 5);
	exibirFila(fila1); 
	printf("-----------------\n");
	
	printf("Operacao: Liberar - Elemento liberado: %d\n", liberar(fila1));
	exibirFila(fila1); // 2 3 5
	printf("Operacao: Liberar - Elemento liberado: %d\n", liberar(fila1));
	exibirFila(fila1); // 3 5
	printf("Operacao: Liberar - Elemento liberado: %d\n", liberar(fila1));
	exibirFila(fila1); // 5
	
	printf("Tamanho: %d\n", tamanhoFila(fila1));
	
	apagarFila(&fila1); 
	exibirFila(fila1);
	
	return 0;
}

Fila *inicializarFila(){
	Fila *fila = (Fila *) malloc(sizeof(Fila));
	if(fila == NULL) exit(1); // Falha na alocação da fila.
	
	fila->frente = fila->fim = NULL;
	
	return fila;
}

Node *alocarNode(int valor){
	Node *novo = (Node *) calloc(1, sizeof(Node));
	if(novo == NULL) exit(2); // Falha na alocação do nó
	
	novo->dado = valor;
	return novo;       // o calloc automaticamente seta *prox para NULL/0.
}

// A fila pode estar vazia de duas formas:
// 1º: A fila existe e está inicializada mas não possui elementos
// 2º: O ponteiro da fila é nulo pois ela foi terminada (com limparFila() )
bool filaVazia(Fila *fila){
	return (fila == NULL || fila->frente == NULL);
}
// A função limparFila() usa ponteiro de ponteiro para limpar não só a alocação da fila (free() )
// como definir o ponteiro fila1 da main() como NULL.


void exibirFila(Fila *fila){
	printf("Fila: ");
	if(filaVazia(fila)){
		printf("Vazia\n");
		return;
	}
	
	for(Node *atual = fila->frente; atual != NULL; atual = atual->prox)
		printf("%d ", atual->dado);
	
	printf("\n");
	return;
}

void enfileirar(Fila *fila, int valor){
	Node *novo = alocarNode(valor);
	if(filaVazia(fila))
		fila->frente = fila->fim = novo; // Se é o 1º elemento da fila, será inicio e fim.
	else{
		fila->fim->prox = novo;
		fila->fim = novo;
	} 
	
	return;
}

int liberar(Fila *fila){
	if(filaVazia(fila)) exit(3); // tentou retornar dado de uma fila vazia.
	
	Node *aux = fila->frente;
	int dado = aux->dado;
	fila->frente = aux->prox;
	free(aux);
	if(filaVazia(fila)) fila->fim = NULL;
	
	return dado;
}

void apagarFila(Fila **fila){
	Node *aux;
	while((*fila)->frente != NULL){
		aux = (*fila)->frente;
		(*fila)->frente = aux->prox;
		free(aux);
	}
	(*fila)->fim = NULL;
	free(*fila);
	*fila = NULL;
	return;
}

// exit com valor (3): Tentativa de retornar dado de uma fila vazia.

int dadoFrente(Fila *fila){
	if(filaVazia(fila)) exit(3);
	else return fila->frente->dado;
}
int dadoFim(Fila *fila){
	if(filaVazia(fila)) exit(3);
	else return fila->fim->dado;
}

int tamanhoFila(Fila *fila){
	if(fila == NULL){
		printf("Checagem de fila inexistente, fim da execucao.");
		exit(4); // Encerra execução. O tamanho não é zero porque a fila sequer existe.
	} 
	else if(fila->frente == NULL) return 0; // Fila existe (inicializada) mas está vazia.

	int cont = 0;
	for(Node *atual = fila->frente; atual != NULL; atual = atual->prox){
		++cont;
	}
		
	return cont;
}
