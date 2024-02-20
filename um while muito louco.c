#include <stdio.h>

// dificilmente alguém te ensinou isso...

int main(void){
	
	int i = 8;
	int n = 0; // <--
	
	// e aí? condição (n != 0) ou (n < 5)?
	while(n != 0, ++i, ++n, n < 5)
		printf("%d ", n+i);
	
	printf("| ");
	
	while(++i, n != 5,  --n, n > 0)
		printf("%d ", n - i);
	
	return 0;
}










// *condição* do while'sempre será o último "argumento" na direita.

// mais um pouco e vira um 'for()' :P
