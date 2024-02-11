/*
c) Vimos que a soma dos n primeiros termos de uma série harmônica produz o chamado
número harmônico Hn, definido abaixo

Imagem: Somatório de (k = 1 para n) de 1 / k.

Escreva um programa em C que calcula recursivamente o número Hn, para algum N de
entrada tal que N <= 100. Teste se os valores encontrados pelo seu programa estão corretos. São
exemplos de saídas esperadas:
*/
#include <stdio.h>

double serieHarmonica(int n){
	return (n == 1)? 1:1.0/n + serieHarmonica(n - 1);
}	

int main(){
	int n;
	
	printf("Digite um número para obter sua série harmônica: ");
	scanf("%d", &n); printf("%lf", serieHarmonica(n));
	
	return 0;
}
