#include <stdio.h>
#define TAM_V 5

// Intercalação de arrays --> recursiva.
// Função contemplável por tail call optimization! -O2 no gcc

void intercalaRec(int *v1, int *v2);
void recursao(int *v1, int *v2, int cont); // sem usar i e j.

int main(void){
	int v1[TAM_V] = {1,3,5,7,9};
	int v2[TAM_V] = {2,4,6,8,10};
	
	intercalaRec(v1, v2);
	
	return 0;
}


// Tornar a chamada da func. menos verbosa (=
void intercalaRec(int *v1, int *v2){
	recursao(v1, v2, 0);
}

void recursao(int *v1, int *v2, int cont){
	// Caso Base
	if(cont == 2*TAM_V)
		return;
	
	// Caso geral...
	if(cont%2 == 0){
		printf("%d ", v1[cont/2]);
		recursao(v1,v2,cont+1);
	}
	else{
		printf("%d ", v2[cont/2]);
		recursao(v1,v2,cont+1);
	}	
}





// Obsoletas (menos otimizadas)
/*
void recursao(int *v1, int *v2, int i, int j, int cont){
	// Caso Base
	if(cont == 2*TAM_V)
		return;
	
	// Caso geral...
	if(cont%2 == 0){
		printf("%d ", v1[i]);
		recursao(v1,v2, i+1, j, cont+1);
	}
	else{
		printf("%d ", v2[j]);
		recursao(v1,v2, i, j+1, cont+1);
	}	
}

void recursao2(int *v1, int *v2, int i, int cont){
	// Caso Base
	if(cont == 2*TAM_V)
		return;
	
	// Caso geral...
	if(cont%2 == 0){
		printf("%d ", v1[i]);
		recursao2(v1,v2, i, cont+1);
	}
	else{
		printf("%d ", v2[i]);
		recursao2(v1,v2, i+1,  cont+1);
	}	
}
*/
