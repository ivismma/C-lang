// gcc atividade1.c -o atividade1.out -Wall
// ./atividade1.out

#include <stdio.h>

/*
int main() {
	char simbolo;
	printf("Digite um caractere.\n");
	scanf ("%c", &simbolo);
	switch(simbolo) {
		case '!':
			printf("Exclamacao.\n");
			break;
		case '?':
			printf("Interrogacao.\n");
			break;
		case '@':
			printf("O proximo simbolo eh %c.\n", simbolo + 1);
		default:
			printf("Simbolo qualquer.\n");
	}
	return 0;
}
*/

// Código corrigido: 

int main() {
	char simbolo;
	printf("Digite um caractere.\n");
	scanf ("%c", &simbolo);
	switch(simbolo) {
		case '!':
			printf("Exclamacao.\n");
			break;
		case '?':
			printf("Interrogacao.\n");
			break;
		case '@':
			printf("O proximo simbolo eh %c.\n", simbolo + 1);
			break; // Caracter @ + 1 é 'A' na tabela ASCII.
		default:
			printf("Simbolo qualquer.\n");
	}
	return 0;
}
