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
	int n,x;
	printf("Digite de 1 a 5 para escolher da função A até E:\n");
	scanf("%d", &n);
	switch(n){
		case 1:
			printf("%d",funcaoA(2));
			break;
		case 2:
			printf("%f",funcaoB(-2));
			break;
		case 3:
			printf("%f",funcaoC(7,5,3));
			break;
		case 4:
			//printf("%f",funcaoD(4,8,5);
			printf("Esta função ainda não está completa.");
			break;
		case 5:
			printf("%g",funcaoE('S'));
			break;
		default:
			printf("Digite um valor válido (1 a 5).");
	}

	return 0;
}
