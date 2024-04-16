#include <stdio.h>

/*
P1 antiga Prog I 2023.1

Questão 1) (3.0 pontos) Um caso particular da distância de Hamming (originalmente utilizada em textos)
é sua aplicação sobre valores numéricos, como segue:
A distância de Hamming entre dois números naturais a e b, tais que a e b possuem a *mesma quantidade
de dígitos*, é o número mínimo de substituições de algarismo necessárias para igualar a e b.

Escreva um programa em C que calcule a distância de Hamming entre dois naturais, conforme as
especificações acima. Ambos os números devem ser lidos do teclado. Seu programa deverá
necessariamente conter 3 funções, cujos nomes e propósitos são:
1) main – Onde será feita a coleta dos números a e b e também a impressão da distância de Hamming
entre eles.
2) numDig – Recebe um único natural de entrada, e retorna sua quantidade de dígitos.
3) hamming – Recebe dois naturais de entrada, ambos com a mesma quantidade de dígitos, e retorna a
distância de Hamming entre eles.
*/

short int numDig(int n); 
int hamming(int n1, int n2, int tam, int i);

int main(void){
	int n1;
	int n2;
	
	printf("Digite n1 e n2: ");
	scanf("%d %d", &n1, &n2);
	if(numDig(n1) != numDig(n2)) return 1;
	short int tam = numDig(n1);
	
	printf("\ndistHamming(%d,%d) = %d", n1, n2, hamming(n1,n2,tam,0));

	return 0;
}

short int numDig(int n){ 
	if(n == 0) return 1;
	n = (n < 0)? -n : n;
	
	short int soma = 1;
	while(n = n/10) 
		++soma;
		
	return soma;
}

int hamming(int n1, int n2, int tam, int i){
	if(i == tam) return 0;
	
	if(n1%10 != n2%10)
		return 1 + hamming(n1/10, n2/10, tam, i+1); 
	
	return hamming(n1/10, n2/10, tam, i+1); 
}
