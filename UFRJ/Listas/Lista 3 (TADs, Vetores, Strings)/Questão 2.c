/*
Escreva um programa que inverta uma string qualquer de entrada (do teclado), e
imprima a string invertida. Por exemplo: para a string de entrada “Professor” (9 caracteres + caractere
nulo), deverá ser impresso “rosseforP” pela simples leitura sequencial, a partir do índice 0 da string já
invertida até o índice 9 da mesma.
*/

#include <stdio.h>
#include <string.h>

// Função que inverte e imprime a string.
void inverteString(char s[], int tam){
	int i = 0, j = tam-1; // j = índice anterior ao '\0'.
	char aux[tam]; // Auxiliar que irá guardar a string invertida.
	
	// tam é o tamanho de s[] excluindo o '\0'.
	while(i < tam) aux[i++] = s[j--];
	aux[i] = '\0'; // i já foi incrementado na última iteração p/ o último índice.
	
	// Exercício pede impressão por for() de caracter.
	for(i = 0; i < tam; ++i) printf("%c", aux[i]);
}

int main(){
	char str[20+1];
	puts("Digite uma palavra de ate 20 caracteres:");
	gets(str);
	
	inverteString(str, strlen(str));
	return 0;
}
