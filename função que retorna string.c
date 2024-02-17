#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função que retorna uma string.
//    (alocada dinâmicamente)
// (retorna o endereço do bloco de memória)

char *retornaString(char s[]);

int main(void){

	char *pstr;
	pstr = retornaString("String retornada."); // String literal como argumento
	
	printf("pstr --> %s\n", pstr);
	
	if(pstr[strlen(pstr)] == '\0')
		printf("o C insere o caracter nulo no final de uma str literal (=");
	
	free(pstr);
	return 0;
}

char *retornaString(char s[]){
	const int tam = strlen(s)+1;
	char *p = malloc(tam);
	strcpy(p, s);
	
	return p;
}
