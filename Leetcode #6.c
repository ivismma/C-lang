// Leetcode #6   (minha abordagem usando listas)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char KEYTYPE;

// estrutura do n�
typedef struct _ListNode{
	KEYTYPE key;
	struct _ListNode *next;
} ListNode;

// estrutura da lista
typedef struct{
	ListNode *head;
	ListNode *end; // �ltimo elemento
} List;

// fun��es de lista encadeada usada nesse ex.
void init(List *list); // init da lista
void insertAtLast(List *list, KEYTYPE value); // insere no final
void freeList(List *list); // desaloca n�s/limpa lista
////////////////////
char* convert(char* s, int numRows);

int main(void){
	/*
	char *s = convert("PAYPALISHIRING", 3);
	printf("%s", s);
	free(s);
	*/
}

char* convert(char* s, int numRows) {
    int lenght = strlen(s);
    // se � s� uma linha, n�o h� oq fazer. Se (n�m. de linhas > tam. da string) tb n�o pq n�o h� zigzag.
    if(lenght <= numRows || numRows == 1)
    	return strdup(s);
    	
    // aloca��o din. de um vetor de listas:
    List *rowList = (List *) malloc(numRows * sizeof(List));
    for(int i = 0; i < numRows; ++i)
    	init(rowList+i);
    insertAtLast(rowList, s[0]); // previamente insere 1� caracter de s na 1a lista (rowList[0])
    
	int i = 1; // e come�a pelo 2� (i � o indice atual de s)
    
    while(true){
		int j;
		// adiciona na lista de cima pra baixo -> [1...numRows-1]
		for(j = 1; j < numRows; ++j){
			insertAtLast(rowList+j, s[i++]);
			if(i == lenght)
                goto ENDLOOP;
		}
		// adiciona na lista de baixo pra cima -> [numRows-2 ... 0]
		for(j-=2; j >= 0; --j){
			insertAtLast(rowList+j, s[i++]);
			if(i == lenght)
                goto ENDLOOP;
		}
	}
	ENDLOOP: // sair do loop sem precisar de flag e break's
	
	// aloca string resultado:
    char *converted_str = (char *) malloc(lenght+1);
	converted_str[lenght] = '\0';
    
    // cria a string respeitando o zigzag...
    // a string � criada pegando cada caracter das listas [0 at� numRows-1]
    // e desalocando-as quando j� foi toda copiada <- (*)
    
    for(int j = 0, i = 0; j < numRows; ++j){
		ListNode *current = rowList[j].head;
		while(current != NULL){
			converted_str[i++] = current->key;
			current = current->next;
		}
		freeList(rowList+j); // (*)
	}
	
    free(rowList); // libera vetor de listas
    
    return converted_str;
}


//////////////////////////////////////////////////////////////


void init(List *list){
	list->head = NULL;
	list->end = NULL;
}

void insertAtLast(List *list, KEYTYPE value){
	ListNode *head = list->head;
	
	ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
	newNode->key = value;
	newNode->next = NULL;
	
	if(head == NULL)
		list->head = list->end = newNode;
	else{
		list->end->next = newNode;
		list->end = newNode;
	}
}

void freeList(List *list){
	ListNode *current = list->head;
	while(current != NULL){
		ListNode *remove = current;
		current = current->next;
		free(remove);
	}
	list->head = NULL;
	list->end = NULL;
}
