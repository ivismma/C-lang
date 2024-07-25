/*
Questão lista antiga - Prof. Valéria - Prog I grade 2010.

Vamos fazer um teste inicial para verificar se o gerador de números aleatórios tem vícios.
Vamos testar se ele gosta mais dos números pares ou dos ímpares. Escreva um programa que gere 1.000.000
números aleatórios entre 0 e RAND_MAX e calcule quantos destes são pares e quantos são ímpares. Calcule
a frequência (em percentagem) com que cada um destes tipos foi gerado. O que você pode dizer após
este pequeno experimento. Rode o programa diversar vezes e verifique se os resultados levam a mesma
conclusão.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define AMOUNT 1000000

bool par(int n){ return (n%2 == 0); }

int main(void){

	srand(time(NULL));
	int pares = 0;
	
	for(int i = 0; i < AMOUNT; ++i){
		if(par(rand())) 
			++pares;
	}
	const int impares = AMOUNT-pares;

	printf("Frequencia:\n\n");
	printf("Pares: %.4lf%%\nImpares: %.4lf%%", ( (double) pares/AMOUNT*100), (double) impares/AMOUNT*100);

	return 0;
}
