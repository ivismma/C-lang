#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define ASCII_NUMS 48 // Início dos números em ASCII
#define TAM_STR 11

// Converter um número decimal para qualquer base (2-9 e hex).
// Uso de pilha para o cálculo da conversão.

typedef struct node{
	char num;
	struct node *prox;
} Node;

void empilhar(Node **topo, char num);
char desempilhar(Node **topo);
bool verifBase(short base);
bool verifNumero(char *s, short tam);
char *converter(char *num1, short base);
char algarismo(int num);
void obterString(char *s, short tam);

int main(void){
	setlocale(LC_ALL, "Portuguese");
	char s[TAM_STR];
	short base;
	
	printf("Insira um número decimal de até 10 dígitos\n--> ");
	obterString(s, TAM_STR);
	while(!verifNumero(s, TAM_STR)){
		printf("Número inválido. Digite um número válido.\n--> ");
		obterString(s, TAM_STR);
	}
	printf("Lido: %s\n", s);
	
	printf("Para qual base converter?\n--> ");
	scanf("%hd", &base);
	while(!verifBase(base)){
		printf("Base inválida. Digite uma base de 2 a 9 ou hexadecimal.\n--> ");
		scanf("%hd", &base);
	}
	
	char *conv = converter(s, base);
	printf("%s(10) = %s(%hd)\n", s, conv, base);
	
	free(conv);
	return 0;
}

// base 1 -> base origem | base 2-> base p/ conversão
char *converter(char *num, short base){
	char *convertido = (char *) malloc(16);
	
	Node *pilha = NULL; // topo da pilha.
	int valor = atoi(num);
	if(!valor) return num; // Se valor inserido é zero, retorna zero.
	
	for(;valor; valor /= base){
		empilhar(&pilha, algarismo(valor%base));
	}
	int i;
	for(i = 0; pilha != NULL; ++i)
		convertido[i] = desempilhar(&pilha);
	
	convertido[i] = '\0';
	
	return convertido;
}

// basicamente um "dicionário" para tratar dos hexadecimais.
char algarismo(int num){
	if(num < 10) 
		return ASCII_NUMS + num;
	switch(num){
		case 10:
			return 'A';
		case 11:
			return 'B';
		case 12:
			return 'C';
		case 13:
			return 'D';
		case 14:
			return 'E';
		default:
			return 'F';
	}
}

bool verifBase(short b){
	return ((b >= 2 && b <= 9) || b == 16);
}

void obterString(char *s, short tam){
    fgets(s, tam, stdin);
	int len = strlen(s); 
    
    if(s[len-1] == '\n')
        s[len-1] = '\0'; 
	else{
        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }
}

bool verifNumero(char *s, short tam){
	for(int i = 0; s[i] != '\0'; ++i)
		if(s[i] < '0' || s[i] > '9') 
			return false;
	return true;
}








// manipulação da pilha

void empilhar(Node **topo, char num){
	Node *novo = (Node *) calloc(1, sizeof(Node));
	novo->num = num;
	
	if(*topo == NULL)
		*topo = novo;
	else{
		novo->prox = *topo;
		*topo = novo;
	}
	
	
}

char desempilhar(Node **topo){
	if(*topo == NULL) exit(2);
	
	char aux = (*topo)->num;
	*topo = (*topo)->prox;
	return aux;
}
