#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Igualar um ponteiro *alocado* à sua tentativa de realloc() pode implicar em perdê-lo
// em caso de uma falha na realocação, perdendo o ponteiro original para os dados, pois 
// realloc() retorna NULL quando falha na realocação e então seria atribuído NULL a p
// (os dados permanecem lá, alocados, mas você perdeu o endereço do bloco).

// Solução: Criar um ponteiro temporário para armazenar o retorno de realloc(), e caso a
// realocação tenha êxito, atribuir ao ponteiro original =)

int main(void){
	
	int *p = (int*) malloc(100*sizeof(int));
	if(p == NULL){
		printf("Falha na 1a alocacao.\n");
		return 1;
	}
	
	{         // 1ª realocação (1000 ints) - válido.
		int *novo = (int*) realloc(p, 1000*sizeof(int));
		
		if(novo == NULL) printf("Falha na 1a realocacao\n");
		else p = novo; // OK
	}
	
	{        // 2ª realocação (10^40 Bytes) - provável erro.
		int *novo = (int*) realloc(p, (size_t) pow(10,40)); 
		
		if(novo == NULL) printf("Falha na 2a realocacao\n");
		else p = novo; // OK
	}
	
	if(p != NULL)
		printf("O ponteiro original foi preservado: %p\n", p);

	return 0;
}
