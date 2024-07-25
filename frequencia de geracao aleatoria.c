/*
Quest�o lista antiga - Prof. Val�ria - Prog I grade 2010.

Escreva um programa que gere 6.000.000 n�meros aleat�rios entre 1 e 6 e calcule a frequ�ncia
(em percentagem) com que cada um destes n�meros foi gerado. Observe que o gerador de n�meros
rand�micos gera n�meros entre 0 e um n�mero escolhido e isto pode ser um problema. Como fazer que
ele gere n�meros entre 1 e 6? O que voc� pode dizer sobre o dado?
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
