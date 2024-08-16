#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Receber uma string e uma sequência de caracteres, em seguida 
// verificar se está contido na string.

bool palavraAparece(char *str1, char *str2);

int main(void){
	char str1[50];
	char str2[30]; // substring a procurar
	
	printf("Digite uma frase: "); // até 49 caracteres
	fgets(str1,50,stdin);
	str1[strlen(str1)-1] = '\0';
	printf("Digite uma palavra ou sequencia de caracteres: "); // (até 29).
	scanf("%s", str2);
	
	if(palavraAparece(str1, str2))
		printf("\"%s\" aparece na frase.", str2);
	else
		printf("\"%s\" nao aparece na frase.", str2);

	return 0;
}

// Ambos serão transformados em minusculo para melhorar verificação

bool palavraAparece(char *str1, char *str2){
	int tam1 = strlen(str1);
	int tam2 = strlen(str2);
	// tam2 é o tamanho da sequência procurada.
	for(int i = 0, j = 0; i < tam1; ++i){
		char c1 = tolower(str1[i]);
		char c2 = tolower(str2[j]);
		if(c1 == c2)
			++j;
		else
			// se c1 != c2, testa str2[0] p/ o mesmo str1[i] antes de incrementar.
			j = (c1 == str2[0])? 1 : 0;
		
		if(j == tam2) return true;
	}
	return false;  // Não encontrou.
}
