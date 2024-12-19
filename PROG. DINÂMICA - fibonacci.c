
// Fibonacci utilizando programação dinâmica
// recomendado compilar gcc c/ flag -O2

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TAM_VET 30

long long fibonacci(int n);
void init(long long **v, int tam);

long long *v = NULL;

int main(void){
	assert(TAM_VET > 10); // mín. 10
	init(&v, TAM_VET);

	{
		int buffer;
		printf("Digite um valor de 0 a %d (-1 para sair)\n--> ", TAM_VET-1);
		scanf("%d", &buffer);
		while(buffer != -1){
			assert(buffer >= 0 && buffer < TAM_VET); // inseriu fora do intervalo [0, TAM_VET)
			printf("fibonacci(%d) = %lld\n", buffer, fibonacci(buffer));	
			exibeVet(v, TAM_VET);
			printf("\n--> ", TAM_VET-1);
			scanf("%d", &buffer);
		}
	}
	
	printf("\nfim de exec.\n");
	return 0;
}

long long fibonacci(int n){
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	
	if(v[n] != -1)      // já está calculado.. retorna
		return v[n];
	else{               // calcula, guarda e retorna..
		v[n] = fibonacci(n-1) + fibonacci(n-2);
		return v[n];
	}
}

// inicializa vetor q guarda os valores
void init(long long **v, int tam){
	assert(*v == NULL); // 
	
	*v = (long long *) malloc(tam * sizeof(long long));
	if(*v == NULL) exit(1); // falha aloc.
	
	(*v)[0] = 0;
	(*v)[1] = 1;
	(*v)[2] = 1;
	for(int i = 3; i < tam; ++i)
		(*v)[i] = -1;
}

void exibeVet(long long *v, int tam){
	for(int i = 0; i < tam; ++i)
		if(v[i] != -1) 
			printf("%lld ", v[i]);
		else
			printf("N "); // valor -1 -> N: significa que não foi preenchido ainda.
}

