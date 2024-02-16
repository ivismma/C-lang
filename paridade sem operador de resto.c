#include <stdio.h>

// Par ou ímpar sem operador divisão e resto.
// Um número par sempre possui o bit menos significativo = zero.
// Ex: 8 - 1000 | 4 - 0100 | 10 - 1010 |    Ímpar --> 11 - 1011

int main(void){
	int num;
	
	printf("Digite um numero: ");
	scanf("%d", &num);
	
	if(!(num & 1)) // operador AND.
		printf("Par.\n"); // Bit 0.
	else
		printf("Impar.\n"); // Bit 1.
	
	return 0;
}
