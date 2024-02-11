/*
Atividade 3: Crie um programa em C que lê do teclado uma base inteira positiva x e
um total de n termos, tal que n é par, e calcula recursivamente o resultado da
expressão
*/
#include <stdio.h>
#include <math.h>

int calculaExpressao(int x, int n, int soma){
	if(n == 1) //Última execução (n é ímpar nesse caso), ou seja, subtraia.
		return soma-x;
	if(n%2 == 0)
		return calculaExpressao(x, n-1, soma + (pow(x,n)));
	// (n%2 != 0):
	return calculaExpressao(x, n-1, soma - (pow(x,n)));
}

int main(){
	int x,n,res;
	
	do{
		printf("Digite um número inteiro x positivo: ");
		scanf("%d", &x);
		printf("\n");
	} while(x < 0);
	do{
		printf("Digite um número n par: ");
		scanf("%d", &n);
		printf("\n");
	} while(n%2 != 0);
	
	res = calculaExpressao(x, n, 0);
	printf("O resultado da expressão é --> %d", res);

	return 0;
}
