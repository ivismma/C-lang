#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

// preparação para ESD, estudando ***listas circulares***.

// acostumando a programar em inglês (boas práticas).

// nó que armazena int.
typedef struct node{
	int reg; // registro/dado
	struct node *next;
} Node; // Nó

typedef struct{
	Node *head;
	Node *first;
	int size;
} List; // Lista

// Tamanho em bytes do Nó e Lista para a alocação.
const size_t NodeBytes = sizeof(Node);
const size_t ListBytes = sizeof(List);

// gerenciamento:
void startList(List **list);                   // Aloca lista (alocação a struct)
int pop(List *list);                           // op. desempilhar
void push(List *list, int value);              // op. empilhar.
bool insert(List *list, int value, int index); // Inserção de nó (insere no índice).
int removeAtIndex(List *list, int index);      // Remove nó no índice inserido.
int access(List *list, int index);             // Acessa e retorna o dado armazenado no nó do índice inserido.
void showList(List *list);                     // Exibir a lista
void clearList(List *list);                    // Limpa todos os nós da lista, mantém alocada e vazia.
bool empty(List *list);                        // Retorna true se a lista estiver vazia, false caso contrário.
void endList(List **list);                     // Desalocar a lista e limpar os nós caso ainda tenha elementos.

// return:
// código 1: tentou limpar uma lista não inicializada.
// código 11: tentou retornar um nó nulo/lista vazia.
// código 21: falha na alocação

// main() testando casos e funções:
int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	List *lista1 = NULL;
	startList(&lista1);
	
	push(lista1, 6);
	push(lista1, 5);
	push(lista1, 4);
	push(lista1, 3);
	insert(lista1, 100, 2);
	printf("Lista 1:\n");
	showList(lista1);
	printf("\nApós remover List[3] (%d):\n", access(lista1, 3));
	removeAtIndex(lista1, 3);
	showList(lista1);
	
	endList(&lista1);
	
	List *lista2 = NULL;
	startList(&lista2); // incializando lista, adicionando e limpando-a em seguida.
	push(lista2, 5);
	push(lista2, 5);
	clearList(lista2);
	printf("\nLista 2:\n");
	showList(lista2); // vazia.
	endList(&lista2);
	
	return 0;
}

// calloc automaticamente zera os bytes.

List *allocList(){
	return (List *) calloc(1, ListBytes);
}


// Ponteiro de ponteiro para atualização do ponteiro original.
void startList(List **list){  
	*list = allocList();
	if(*list == NULL) exit(21);
}

void endList(List **list){
	if(*list == NULL) exit(1); // caso 1: lista não inicializada.
	if((*list)->size)          // caso 2: ainda contém elementos, limpar a lista.
		clearList(*list);
	
	free(*list);
	*list = NULL; // atualiza ponteiro original
}

void push(List *list, int value){
	Node *newNode = (Node *) calloc(1, NodeBytes); // alocação novo nó
	if(newNode == NULL) exit(21);
	newNode->reg = value;
	
	if(list->head == NULL){ // caso 1: lista vazia.
		list->head = newNode;
		list->head->next = list->head; // o primeiro aponta para ele mesmo.
		list->first = newNode;         // first é o primeiro, será o que aponta para o início.
	}
	else{ // caso 2: lista não vazia.
		newNode->next = list->head;
		list->head = newNode;
		list->first->next = newNode; // atualiza ponteiro para manter lista circular.
	}
	++(list->size);
}

// retorna true se a inserção é válida, false caso contrário.
// Insere nó no indice de 0 até list->size, se index o próprio size, insere novo nó.
// index == size significa inserir nó após o último.
bool insert(List *list, int value, int index){
	if(index < 0 || index > list->size) // caso 1: indice negativo ou maior que tamanho+1
		return false;
	if(list->head == NULL || index == 0){ // caso 2: lista nula(ñ inicializada) ou indice = 0
		push(list, value);
		return true;
	}
	// caso 3: a inserção é válida.
	Node *current = list->head; // percorrer até nó anterior p/ "amarrar o nó" entre antec. e sucessor.
	for(int i = 0; i < index-1; ++i) current = current->next;
	
	if(current->next != NULL){
		Node *newNode = (Node *) malloc(NodeBytes);
		if(newNode == NULL) exit(21);
		newNode->reg = value;
		
		Node *aux = current->next;
		current->next = newNode;
		newNode->next = aux;
		++(list->size);
	}
	return true;
}

int pop(List *list){
	if(list->size == 0) exit(11); // caso 1: lista vazia.
	
	Node *head = list->head;
	int reg = head->reg;
	if(list->size == 1){ // caso 2: lista só tem 1 elemento.
		free(head);
		list->head = NULL;
		list->first = NULL;
		list->size = 0;
	}
	else{ // caso 3: lista tem mais de 1 elemento.
		Node *aux = head->next; // armazena o nó que será o novo topo.
		free(aux); // desaloca o nó.
		list->head = aux;
		list->first->next = aux;
	}
	--(list->size);
	return reg;
}

int access(List *list, int index){
	if(list->size == 0) exit(11);
	
	Node *current = list->head; // percorrer lista até o elemento desejado
	for(int i = 0; i < index; ++i) current = current->next;
	return current->reg;
}

// retorna o elemento do indice inserido e o remove da lista.
int removeAtIndex(List *list, int index){
	if(index < 0 || index > list->size-1) // caso 1: indice inválido
		exit(11); // out of range..
	if(index == 0)  // caso 2: índice 0 (apenas desempilhar).
		return pop(list);
	
	// caso 3: percorrer até índice e reamarrar os nós.
	Node *current = list->head;  // percorrer até nó anterior para amarrar nó.
	for(int i = 0; i < index-1; ++i) current = current->next;
	
	int reg = current->next->reg; // valor a ser retornado.
	Node *removed = current->next;
	Node *aux = removed->next; // armazena próx do próx (nó a ser removido).
	current->next = aux;
	--(list->size);
	
	free(removed); // desaloca o nó.
	return reg;
}

void showList(List *list){
	if(list == NULL){
		printf("Lista não inicializada\n");
		return;
	}
	if(empty(list)){
		printf("Lista vazia\n");
		return;
	}
	
	Node *current = list->head;
	
	for(int i = 0; i < list->size; ++i, current = current->next)
		printf("List[%d] = %d\n", i, current->reg, current->next->reg);
	printf(">> Próximo elemento: List[%d] = %d\n", 0, current->reg);
}

bool empty(List *list){
	return list->size == 0;
}

void clearList(List *list){
	if(empty(list)) return; // caso 1: lista já está vazia.
	
	// caso 2: limpar a lista.
	Node *current = list->head;
	for(int i = 0; i < list->size; ++i){
		Node *aux = current->next;
		free(current);
		current = aux;
	}
	list->size = 0;
	list->head = NULL;
	list->first = NULL;
}
