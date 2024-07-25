/*
Questão lista antiga - Prof. Valéria - Prog I grade 2010.

Escreva um programa que gere 6.000.000 números aleatórios entre 1 e 6 e calcule a frequência
(em percentagem) com que cada um destes números foi gerado. Observe que o gerador de números
randômicos gera números entre 0 e um número escolhido e isto pode ser um problema. Como fazer que
ele gere números entre 1 e 6? O que você pode dizer sobre o dado?
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AMOUNT 6000000

int main(void){

	srand(time(NULL));
	int numero[6] = {0}; // 1 2 3 4 5 6
	
	for(int i = 0; i < AMOUNT; ++i){
		int gerado = rand()%6+1; // 1 a 6.
		++numero[gerado-1];
	}

	printf("Frequencia:\n\n");
	for(int i = 0; i < 6; ++i)
		printf("Numero %d: %.4lf\%%\n", i+1, ((double) numero[i]/AMOUNT)*100);

	return 0;
}
