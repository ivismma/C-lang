#include <stdio.h>

#define TAM 3

void exibeMatriz(int M[TAM][TAM], int i, int j);

int main(void){
	
	int M[TAM][TAM] = { {4,7,1},{6,8,0},{0,9,2} };
	
	exibeMatriz(M, 0, 0);
	
	return 0;
}

void exibeMatriz(int M[TAM][TAM], int i, int j){
	// Caso base
	if(i == TAM) return;
	
	// Caso geral
	if(j < TAM){
		printf("%d ", M[i][j]);
		exibeMatriz(M, i,j+1);
	} 
	else{
		printf("\n");
		exibeMatriz(M, i+1,0);
	}
}
