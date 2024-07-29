#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

// prepara��o para ESD, estudando ***listas circulares***.

// acostumando a programar em ingl�s (boas pr�ticas).

// n� que armazena int.
typedef struct node{
	int reg; // registro/dado
	struct node *next;
} Node; // N�

typedef struct{
	Node *head;
	Node *first;
	int size;
} List; // Lista

// Tamanho em bytes do N� e Lista para a aloca��o.
const size_t NodeBytes = sizeof(Node);
const size_t ListBytes = sizeof(List);

// gerenciamento:
void startList(List **list);                   // Aloca lista (aloca��o a struct)
int pop(List *list);                           // op. desempilhar
void push(List *list, int value);              // op. empilhar.
bool insert(List *list, int value, int index); // Inser��o de n� (insere no �ndice).
int removeAtIndex(List *list, int index);      // Remove n� no �ndice inserido.
int access(List *list, int index);             // Acessa e retorna o dado armazenado no n� do �ndice inserido.
void showList(List *list);                     // Exibir a lista
void clearList(List *list);                    // Limpa todos os n�s da lista, mant�m alocada e vazia.
bool empty(List *list);                        // Retorna true se a lista estiver vazia, false caso contr�rio.
void endList(List **list);                     // Desalocar a lista e limpar os n�s caso ainda tenha elementos.

// return:
// c�digo 1: tentou limpar uma lista n�o inicializada.
// c�digo 11: tentou retornar um n� nulo/lista vazia.
// c�digo 21: falha na aloca��o

// main() testando casos e fun��es:
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
	printf("\nAp�s remover List[3] (%d):\n", access(lista1, 3));
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


// Ponteiro de ponteiro para atualiza��o do ponteiro original.
void startList(List **list){  
	*list = allocList();
	if(*list == NULL) exit(21);
}

void endList(List **list){
	if(*list == NULL) exit(1); // caso 1: lista n�o inicializada.
	if((*list)->size)          // caso 2: ainda cont�m elementos, limpar a lista.
		clearList(*list);
	
	free(*list);
	*list = NULL; // atualiza ponteiro original
}

void push(List *list, int value){
	Node *newNode = (Node *) calloc(1, NodeBytes); // aloca��o novo n�
	if(newNode == NULL) exit(21);
	newNode->reg = value;
	
	if(list->head == NULL){ // caso 1: lista vazia.
		list->head = newNode;
		list->head->next = list->head; // o primeiro aponta para ele mesmo.
		list->first = newNode;         // first � o primeiro, ser� o que aponta para o in�cio.
	}
	else{ // caso 2: lista n�o vazia.
		newNode->next = list->head;
		list->head = newNode;
		list->first->next = newNode; // atualiza ponteiro para manter lista circular.
	}
	++(list->size);
}

// retorna true se a inser��o � v�lida, false caso contr�rio.
// Insere n� no indice de 0 at� list->size, se index o pr�prio size, insere novo n�.
// index == size significa inserir n� ap�s o �ltimo.
bool insert(List *list, int value, int index){
	if(index < 0 || index > list->size) // caso 1: indice negativo ou maior que tamanho+1
		return false;
	if(list->head == NULL || index == 0){ // caso 2: lista nula(� inicializada) ou indice = 0
		push(list, value);
		return true;
	}
	// caso 3: a inser��o � v�lida.
	Node *current = list->head; // percorrer at� n� anterior p/ "amarrar o n�" entre antec. e sucessor.
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
	if(list->size == 1){ // caso 2: lista s� tem 1 elemento.
		free(head);
		list->head = NULL;
		list->first = NULL;
		list->size = 0;
	}
	else{ // caso 3: lista tem mais de 1 elemento.
		Node *aux = head->next; // armazena o n� que ser� o novo topo.
		free(aux); // desaloca o n�.
		list->head = aux;
		list->first->next = aux;
	}
	--(list->size);
	return reg;
}

int access(List *list, int index){
	if(list->size == 0) exit(11);
	
	Node *current = list->head; // percorrer lista at� o elemento desejado
	for(int i = 0; i < index; ++i) current = current->next;
	return current->reg;
}

// retorna o elemento do indice inserido e o remove da lista.
int removeAtIndex(List *list, int index){
	if(index < 0 || index > list->size-1) // caso 1: indice inv�lido
		exit(11); // out of range..
	if(index == 0)  // caso 2: �ndice 0 (apenas desempilhar).
		return pop(list);
	
	// caso 3: percorrer at� �ndice e reamarrar os n�s.
	Node *current = list->head;  // percorrer at� n� anterior para amarrar n�.
	for(int i = 0; i < index-1; ++i) current = current->next;
	
	int reg = current->next->reg; // valor a ser retornado.
	Node *removed = current->next;
	Node *aux = removed->next; // armazena pr�x do pr�x (n� a ser removido).
	current->next = aux;
	--(list->size);
	
	free(removed); // desaloca o n�.
	return reg;
}

void showList(List *list){
	if(list == NULL){
		printf("Lista n�o inicializada\n");
		return;
	}
	if(empty(list)){
		printf("Lista vazia\n");
		return;
	}
	
	Node *current = list->head;
	
	for(int i = 0; i < list->size; ++i, current = current->next)
		printf("List[%d] = %d\n", i, current->reg, current->next->reg);
	printf(">> Pr�ximo elemento: List[%d] = %d\n", 0, current->reg);
}

bool empty(List *list){
	return list->size == 0;
}

void clearList(List *list){
	if(empty(list)) return; // caso 1: lista j� est� vazia.
	
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
