#include <stdio.h>

// Funções Recursivas - Aula 5.

// O Somatório: i = 1 até n de ( i³ / (i + 1) )
float somatorioRecursivo(int i, int n, float soma);

// Ex de Entrada e Saída:  7 --> 117.28

int main(void){
	int n;
	float res;
	
	printf("Digite o valor n para calcular o somatorio Recursivo: ");
	scanf("%d", &n);
	res = somatorioRecursivo(1, n, 0);
	printf("%.3f", res);
	
	return 0;
	
}

float somatorioRecursivo(int i, int n, float soma){
	if(i == n)
		return soma + (float) (i*i*i)/(i+1);
	else
		return somatorioRecursivo(++i, n, soma + (float) (i*i*i)/(i+1));
}
