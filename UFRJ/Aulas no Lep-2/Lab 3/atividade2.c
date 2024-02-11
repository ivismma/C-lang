// gcc atividade2.c -o atividade2.out -Wall
// ./atividade2.out

#include <stdio.h>

int funcaoA(int n){
	// Retorna -1 se n é par, 1 se n é ímpar.
	return (n%2 == 0)? -1: 0;
}

float funcaoB(float n){
	// Retorna 1 se for positivo, 0 se for negativo.
	return (n >= 0)? 1: 0;
}

float funcaoC(float n1,float n2,float n3){
	// Retorna o maior número entre os três.
	return (n1 > n2 && n1 > n3)? n1: (n2 > n3)? n2: n3;
}

/*float funcaoD(n1,n2,n3){
	float m1, m2; // maior 1 e maior 2.
	(n1 > n2 && n1 > n3)? (n2 > n3)? (n1+n2)/2: (n2+n3)/2 */

float funcaoE(char c){
	return (c >= 97 && c <= 122)? 'm': (c >= 65 && c <= 90)? 'M': '?';
}

int main(){
	int n;
	char c = funcaoE('S');
	
	printf("%c\n", c);
	printf("Insira um valor n:\n");
	scanf("%d", &n);
	printf("%d", funcaoA(n));
	printf("\n");
	return 0;
}
