// Simulação de um for() utilizando goto statement labels... desvio incondicional
// Exemplo: Imprimir uma matriz.

// Não há problemas em usar goto labels, basta saber o que está fazendo.

#include <stdio.h>

#define L 3
#define C 3

int main(void){

	int M[L][C] = { {1,2,3},{4,5,6},{7,8,9} };
	
	// Escopos criados p/ limitar escopo das var. i e j.
	{
		int i = 0; // Declr. inicial
		FOR_I:
		{
			int j = 0; // Declr. inicial
			FOR_J:
			printf("%d ", M[i][j]);
			if(++j < C) goto FOR_J; // Passo e checagem
		}
		printf("\n");
		if(++i < L) goto FOR_I; // Passo e checagem
	}

	return 0;
}
