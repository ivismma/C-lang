#include <stdio.h>
#include <locale.h>

// Exercício 6 - Lista 3 (Estruturas de Repetição)

int potencia(int x, int y);

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int b, e;
	
	printf("Insira x e y: ");
	scanf("%d %d", &b, &e);

	if(b == 0 || e < 0){
		printf("Entrada invalida.");
		return -1;
	}
	
	printf("%d", potencia(b,e) );
	
	return 0;
}

// x = base | y = expoente.
int potencia(int x, int y){
	int resultado = 1;
	if(y == 0) return resultado;

	while(y--) // <--> while(i < y) declarando i = 0.
		resultado *= x;
	
	return resultado;
}
