#include <stdio.h>
#include <math.h>

// Exercício 1 - Lista 4 (Estruturas de Repetição parte 2).

int potencia(int x, int y);
float somatorio(int n);

int main(void){
	int n;
	float res;
	
	printf("Digite o valor n para calcular o somatorio da Questão 1: ");
	scanf("%d", &n);
	res = somatorio(n);
	printf("%.3f", res);
	
	return 0;
}

// Somatório de i = 1 até n de --> ( i³/(i+1) )
float somatorio(int n){
	float soma = 0;
	
	for(int i = 1; i <= n; ++i)
		soma += (float) (potencia(i,3))/(i+1);

	return soma;
}




// Cópia da função do exercício 6 - Lista 3.

int potencia(int x, int y){
	int resultado = 1;
	if(y == 0) return resultado;

	while(y--) // <--> while(i < y) declarando i = 0.
		resultado *= x;
	
	return resultado;
}
