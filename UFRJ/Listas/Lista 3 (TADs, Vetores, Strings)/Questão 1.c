// Lista 3
/*
Questão 1) Um palíndromo é essencialmente uma palavra ou número que, ao se ler “de trás para
frente”, permanece inalterada. Por exemplo: “radar”, “reviver”, 1331, 90209, etc. Escreva um programa
em C que leia uma string do teclado e determine se a mesma trata-se de um palíndromo.
*/

#define FALSE 0
#define TRUE 1
#include <stdio.h>
#include <string.h>

int checaPalindromo(char s[], int tam){
	int i = 0, j = tam-1; // quando j = tam-1, isso significa o último caracter antes do '\0'.
	
	while(i < j) // enquanto i e j não se encontrarem, i percorre pela esquerda e j pela direita. i --> <-- j
		if(s[i++] != s[j--]) // Se s[i] NÃO for igual a s[j] em uma das iterações, então não é palíndromo, retorna FALSE.
			return FALSE;
	return TRUE; // Caso não tenha encontrado nenhuma diferença, significa que é um palíndromo.
}

int main(){
	char str[25+1];
	puts("Teste de palíndromos - Digite uma palavra: ");
	gets(str);
	if(checaPalindromo(str, strlen(str)) )
		printf("%s eh um palindromo!", str);
	else
		printf("%s NÃO eh um palindromo!", str);
	return 0;
}
