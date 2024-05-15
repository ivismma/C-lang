#include <stdio.h>
#include <stdlib.h>

#define TAM 3

// Retorna um ponteiro para um vetor dinâmico com a média das TAM colunas, indexadas referente a matriz.
float *mediaColunas(float M[TAM][TAM]); // somente 1 argumento
float *mediaColunasRec(float M[TAM][TAM], int i, int j, float soma, float *p);

void exibeMatriz(float M[TAM][TAM], int i, int j);

int main(void){
	float M[TAM][TAM] = { {4,7,1},{6,8,0},{0,9,2} };
	
	float *p = mediaColunas(M);
	
	exibeMatriz(M,0,0);
	printf("\nMedia das colunas: ");
	for(int i = 0; i < TAM; ++i) printf("%.2f  ", p[i]);
	
	free(p);
	return 0;
}

// alocação e início da recursão (com os argumentos)
float *mediaColunas(float M[TAM][TAM]){
	// Primeira iteração, alocação do vetor.
	float *p = malloc(TAM*sizeof(float));
	if(p == NULL) exit(123);
	
	return mediaColunasRec(M, 0, 0, 0, p);
}

// recursão
float* mediaColunasRec(float M[TAM][TAM], int i, int j, float soma, float *p){
	if(j == TAM) return p; // Caso base
	
	// Caso geral:
	if(i < TAM){
		soma += M[i][j];
		mediaColunasRec(M, i+1, j, soma, p);
	}
	else{
		p[j] = soma/TAM;
		mediaColunasRec(M, 0, j+1, 0, p);
	}
}









void exibeMatriz(float M[TAM][TAM], int i, int j){
	// Caso base
	if(i == TAM) return;
	
	// Caso geral
	if(j < TAM){
		printf("%.1f  ", M[i][j]);
		exibeMatriz(M, i,j+1);
	} 
	else{
		printf("\n");
		exibeMatriz(M, i+1,0);
	}
}
