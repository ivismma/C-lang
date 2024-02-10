#include <stdio.h>
#include <string.h>

#define TAM_STR 8

// Leitura (do teclado) de strings sem oferecer risco de vazamento de buffer para leitura seguinte
// e sem possibilitar escrita em memória fora da string ( defeito do gets() ).

void obterString(char *s, int tam);

int main(void){
	char str[TAM_STR];
	char str2[TAM_STR];
	
	printf("Digite a string de até %d caracteres:\n", TAM_STR-1);
	obterString(str, TAM_STR);
	printf("Digite a string de até %d caracteres:\n", TAM_STR-1);
	obterString(str2, TAM_STR);
	printf("String 1: %s\nString 2: %s", str, str2);

	return 0;
}

void obterString(char *s, int tam){
    fgets(s, tam, stdin);
	int len = strlen(s); 
    
    if(s[len - 1] == '\n') // Se string for menor que tamanho
        s[len - 1] = '\0'; // Substitui o "ENTER" por terminador.
        
	else {  // Senão, limpará buffer para evitar vazamento para outras leituras.
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    return;
}

