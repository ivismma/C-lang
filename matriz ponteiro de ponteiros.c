#include <stdio.h>
#include <time.h> // gerar matrizes pseudo-aleatorias
#include <stdlib.h>

// Criando matrizes utilizando pointer pra pointer...
// alocação dinâmica usando ponteiro de ponteiros.

void entrada(int *L, int *C);
int **cria_matriz(int L, int C);
void randomiza_matriz(int **matriz, int L, int C);
void exibe_matriz(int **matriz, int L, int C);

int main(void){
	srand(time(NULL));
	
	int L, C;
	
	entrada(&L, &C);
	int **matriz = cria_matriz(L, C);
	randomiza_matriz(matriz, L, C);
	exibe_matriz(matriz, 3, 3);

	return 0;
}

/*
int main(void){
	// visualizando de outra forma
	int aux[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int *matriz[3] = {aux[0], aux[1], aux[2]}; // <-- matriz é, naturalmente: (int **)
	exibe_matriz(matriz, 3, 3);
}
*/

int **cria_matriz(int L, int C){
	    // aloca L linhas (arrays de int pointers) no ponteiro de ponteiro
	int **matriz = (int **) malloc(L * sizeof(int*));
	if(matriz == NULL) exit(1);
	
		// aloca C colunas em cada linha
	for(int i = 0; i < L; ++i){  // aloca array de ints em cada int pointer dos arrays.
		matriz[i] = (int *) malloc(C * sizeof(int));
		if(matriz[i] == NULL) exit(2);
	}
	
	return matriz;
}

/* demonstração
	aloca **matriz pra L = 3, C =3 ...
	
	matriz -> {int* 0, int* 1, int* 2}
	matriz[0] -> pointer pra int 0
	matriz[1] -> pointer pra int 1
	matriz[2] -> pointer pra int 2
	
	...
	percorre e aloca os matriz[ ... ] pra int
	...
	
	agora cada um virou array de pointer com C elementos.
	matriz[0] = {int 0, int 1, int 2} 
	matriz[0] = {int 0, int 1, int 2}
	matriz[0] = {int 0, int 1, int 2}
	
	matriz[0][1] = int 1...
	
	matriz[2][2] = int 2...
*/

void randomiza_matriz(int **matriz, int L, int C){
	for(int i = 0; i < L; ++i)
		for(int j = 0; j < C; ++j)
			matriz[i][j] = 1+rand()%9; // gera 1 a 9.
}

void exibe_matriz(int **matriz, int L, int C){
	for(int i = 0; i < L; ++i){
		for(int j = 0; j < C; ++j){
			printf("%d ", matriz[i][j]);
		}
		puts("");
	}
}

void entrada(int *L, int *C){
	do{
		printf("Digite qtd linhas (2 a 10)\n--> ");
		scanf("%d", L);
	} while(*L < 2 || *L > 10);
	
	do{
		printf("Digite qtd colunas (2 a 10)\n--> ");
		scanf("%d", C);
	} while(*C < 2 || *C > 10);
}
