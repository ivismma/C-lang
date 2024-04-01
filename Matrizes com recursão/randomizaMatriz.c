#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3

// Criar uma matriz com valores aleatórios (de 1 a 10).
void randomizaMatriz(int M[TAM][TAM], int i, int j);

int main(void){
	srand(time(NULL));
	
	int M[TAM][TAM];
	
	randomizaMatriz(M, 0, 0);
	
	return 0;
}

void randomizaMatriz(int M[TAM][TAM], int i, int j){
	if(i == TAM)
		return;
		
	if(j < TAM){
		M[i][j] = rand()%10+1;
		randomizaMatriz(M, i, j+1);
	}
	else
		randomizaMatriz(M, i+1, 0);

}
