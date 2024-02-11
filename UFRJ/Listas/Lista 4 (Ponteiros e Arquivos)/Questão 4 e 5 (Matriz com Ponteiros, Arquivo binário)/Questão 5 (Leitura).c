/*
Questão 5) Escreva um programa que leia o arquivo gerado no exercício anterior e exiba a matriz na
tela.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 3

void exibir(float M[][TAM]){
	printf("Leitura do arquivo binario:\n");
	for(int i = 0; i < TAM; ++i){
		for(int j = 0; j < TAM; ++j)
			printf("%.1f  ", M[i][j]);
		printf("\n");
	}
}

int main(){
	FILE *arquivo;
	float M[TAM][TAM]; // Considerando a matriz que criei foi 3x3.
	
	arquivo = fopen("dados.dat", "rb");
	if(!arquivo) return -1;
	
	// Leitura do arquivo binário.
	for(int i = 0; i < TAM; ++i)
		for(int j = 0; j < TAM; ++j)
			fread(&M[i][j], sizeof(float), 1, arquivo);
			
	fclose(arquivo);
	exibir(M);

	return 0;
}
