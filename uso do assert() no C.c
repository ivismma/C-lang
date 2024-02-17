#include <stdio.h>
#include <assert.h>

// Exemplo de uso do assert no C.

int main(void){

	int x = 5;
	int y = 8;
	// Suponha que y nunca deverá ser menor que x durante a execução.
	// Além disso, haverá checagens durante a execução do programa.
	
	assert(y > x); // OK.
	printf("%d\n%d\n", x, y);
	
	// Exemplo de alteração durante execução.
	int i = 0;
	while(i++ < 10){
		x += 2;
		++y;
		printf("Iteracao: %d\n", i);
		assert(y > x); // Checagem.
	}
	// O programa irá ser executado até a terceira iteração, Assertion Failed.
	// x ultrapassou y em uma determinada checagem, quebra de regra.

	return 0;
}
