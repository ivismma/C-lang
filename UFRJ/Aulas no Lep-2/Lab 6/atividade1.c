#include <stdio.h>

/*Atividade 1: Escreva uma função recursiva que receba um número natural e retorne a
soma de seus dígitos.*/

int obterDigitos(int n, int soma){
	if(n < 10){
		soma += n%10;
		return soma;
	}
		return obterDigitos(n/10, soma += n%10);
}

int main(){
	int n, res;
	
	printf("Digite um número natural: ");
	scanf("%d", &n);
	res = obterDigitos(n, 0);
	printf("O resultado da soma dos dígitos de %d é --> %d\n", n, res);
	
	return 0;
}
