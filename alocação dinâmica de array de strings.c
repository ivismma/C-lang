#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Vetor de strings alocado dinâmicamente.
// aritmética de ponteiros

#define TAM_STR 6 // Tamanho da string
#define TAM_ARR 5 // Tamanho do array.
   // Se fosse aloc. estática --> char strArray[5][6]

void lerArrayStrings(char *s);
void exibirArrayStrings(char *s);

int main(void){
	char *strArray;
	strArray = (char *) malloc(TAM_STR * TAM_ARR);
	
	lerArrayStrings(strArray);
	printf("\n");
	exibirArrayStrings(strArray);

	free(strArray);
	return 0;
}

void lerArrayStrings(char *s){
	// Loop dentro dos blocos de string no bloco de memória.
	for(int i = 0; i < TAM_ARR*TAM_STR; i += TAM_STR){
		// obter string
		fgets(s + i, TAM_STR, stdin);
		
		// limpar buffer...
		int tam = strlen(s+i);
		if(*(s+i+tam-1) == '\n')
			*(s+i+tam-1) = '\0';
		else{
			int c;  
			while(c = getchar() != '\n' && c != EOF);
		}
	}
}

void exibirArrayStrings(char *s){
	for(int i = 0; i < TAM_ARR*TAM_STR; i+= TAM_STR){
		printf("Ptr + i (%d) - %s\n", i, s + i);
	}
}

// Exemplo do bloco de memória com [3][6] -> TAM_STR 6, TAM_ARR 3:

// string 1: 12345678 (limitada a 5 caracteres + \0, buffer limpado).
// string 2: kkk
// string 3: teste

//          ------str 0-----  -------str 1-------  --------str 2---------
// índices: 0  1  2  3  4  5  6  7  8   9  10  11  12  13  14  15  16  17
// memória: 1  2  3  4  5 \0  k  k  k  \0          t    e   s   t   e  \0 
