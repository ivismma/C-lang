/*
Questão 4) Escreva um programa que receba do teclado a dimensão N e os valores de uma matriz
quadrada de float, N <= 10, e salve essas informações em um arquivo binário.
*/

#include <stdio.h>
#include <stdlib.h>

// Minhas observações:
// Na matriz com ponteiros, o primeiro for() incrementa N ao i para tratar os blocos de dimensões, j percorre o interior dos blocos.
// Pra entender melhor, é só pensar em uma sequência de alocações na heap. Se a matriz for 3x3, por exemplo:
// M[0][0], M[0][1], M[0][2], M[1][0], M[1][1]... com ponteiros: *(M + 0 + 0), *(M + 0 + 1), *(M + 0 + 2), *(M + 3 + 0), ...
// Repare que no último não se faz *(M + 1 + 0) porque isso daria no elemento M[0][1], ou seja, sempre incrementa-se a dimensão ao N.
// Mas é importante levar em conta que esse exercício trata-se de matrizes quadradas (matriz NxN).

void preencheMatriz(float *M, int d){
	printf("Digite do teclado %d numeros separados por espaco para preencher a matriz:\n", d*d);
	for(int i = 0; i < d*d; i += d)
		for(int j = 0; j < d; ++j) 
			scanf("%f", (M + i + j));
}

void exibeMatriz(float *M, int d){
	for(int i = 0; i < d*d; i += d){
		for(int j = 0; j < d; ++j){
			printf("%.1f  ", *(M + i + j) );
		}
		printf("\n");
	}
	return;
}

int main(){
	int N;
	float *pM; // Ponteiro para Matriz.
	
	do{
		printf("Digite o tamanho N (de dimensoes) da Matriz quadrada M, N deve ser de ate 10: ");
		scanf("%d", &N);
	} while(N < 1 || N > 10);
	
	// Alocação do Ponteiro da Matriz
	pM = (float *) malloc(N * N * sizeof(float));
	if(!pM){
		printf("Erro na alocacao de memoria.");
		return -1;
	}
	// Inserir os elementos no teclado
	
	preencheMatriz(pM, N);
	exibeMatriz(pM, N);
	
	// Armazenar em um arquivo binário
	FILE *arquivo;
	arquivo = fopen("dados.dat", "wb");
	
	if(!arquivo){
		printf("Erro na criacao do arquivo.");
		return -1;
	}
	fwrite(pM, sizeof(float), N*N, arquivo);
	
	free(pM); // Liberacao de memoria do ponteiro da matriz.
	fclose(arquivo); // Fechamento do arquivo.
	printf("Dados salvos.");
	
	return 0;
}
