/*
Autor: Ivis Muzi
Data: 23/08/2023
Descrição: Recebe um número inteiro N de 3 dígitos e verifica se a unidade, dezena e centena, 
todas elevadas a 3, somadas equivalem ao número inserido.
Entrada: Um número inteiro N de três dígitos.
Saída: Se o número inserido equivale a propriedade matemática N³ = C³ + D³ + U³.
Defesa: Número deve ser positivo e deve possuir três dígitos.
*/

#include <stdio.h>

int main(){
	// Retorna 0 quando houve êxito na execução do programa.
	// Retorna -1 quando o número inserido é inválido para essa execução.
	
	int n;
	int u,d,c;
	
	printf("Digite um número inteiro de três dígitos:\n");
	scanf("%d", &n);
	if(n < 100 || n > 999){
		printf("ERRO - O número inserido é negativo OU não possui três dígitos.");
		return -1;
	}
	u = n%10;
	d = (n/10)%10;
	c = (n/100)%10;
	if( (u*u*u+d*d*d+c*c*c) == n ){
		printf("O número inserido %d = (%d³ + %d³ + %d³)\n", n, c, d, u);
	}
	else{
		printf("O número inserido não satisfaz a propriedade matemática N³ = C³ + D³ + U³\n");
	}

	return 0;
}
