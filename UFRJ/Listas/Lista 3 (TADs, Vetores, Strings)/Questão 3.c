/*
Escreva um programa que leia uma string do teclado e chame uma função “totalLetra”
que receberá a string de entrada e também uma letra qualquer e contará quantas vezes essa letra
ocorre no texto lido. A assinatura da função será: 
int totalLetra(char[] texto, char letra);
Imprima o total na função main.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define FALSE 0
#define TRUE 1

int totalLetra(char texto[], char letra); // Assinatura da função, como pode no exercício.
// Funções para DEFESA:
int validaString(char s[]); 
int verificaLetra(char letra);

int main(){
	char str[20+1],
	c;
	
	do{
		puts("Digite uma string de ate 20 caracteres (com letra):");
		gets(str);
	} while(!validaString(str));
	do{
		printf("Ocorrencias de letra na string - Digite uma letra: ");
		scanf("%c", &c); getchar();
	} while(!verificaLetra(c));
	
	printf("\nA letra '%c' aparece %d vez(es) na string.", c, totalLetra(str, c));
	
	return 0;
}

int totalLetra(char texto[], char letra){
	int len = strlen(texto),
	i = 0,
	cont = 0; // Contagem de ocorrências da letra inserida.
	
	// Deixando todas as letras maiúsculas para não diferenciar 'A' de 'a', por exemplo.
	while(i < len) cont += (toupper(texto[i++]) == toupper(letra))? 1:0;
	return cont;
}

int verificaLetra(char letra){
	if( (letra >= 'A' && letra <= 'Z' ) || (letra >= 'a' && letra <= 'z') )
		return TRUE; 
	return FALSE; // Não é uma letra.
}

// O exercício não especifica se a string deve ser repleta apenas de letras ou pode possuir números
// então a defesa partirá do pressuposto que deve existir pelo menos uma letra.

int validaString(char s[]){ 
	int i = 0,
	len = strlen(s);
	while(i < len)
		if(verificaLetra(s[i++])) return TRUE; // Existe letra na string, retorna 1.
}
