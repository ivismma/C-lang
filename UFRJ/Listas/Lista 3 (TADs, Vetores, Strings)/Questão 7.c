/*O determinante de uma matriz 3x3 pode ser obtido pela Regra de Sarrus, abaixo:

Imagem no PDF da Lista 3!*
--resumindo a imagem: det M = (aei + bfg + cdh) - (afh + bdi + ceg)
sendo M a matriz --

Escreva um programa em C que, dada uma matriz quadrada 3 x 3 de entrada (do teclado), calcule o seu
determinante.
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
// Função somente 3x3, como diz o enunciado.
#define TAM 3

void exibirMatriz(int M[TAM][TAM]){
	for(int i = 0; i < TAM;++i){
		for(int j = 0; j < TAM;++j)
			printf("%d  ", M[i][j]);
		printf("\n");
	}
}

// Calcula a determinante de uma matriz 3x3 através da Regra de Sarrus.
int calculaDetM_3(int M[TAM][TAM]){
	int i,j;
	int soma, sub; // soma: (aei + bfg + cdh) | subtração: (afh + bdi + ceg)
	
	// O exercício não pede a utilização de um for e especifica que a matriz deve ser 3x3.
	/// Sendo assim, será feita seguindo a regra de Sarrus e sem estrutura de repetição.
	
	soma = (
	M[0][0] * M[1][1] * M[2][2] + 
	M[0][1] * M[1][2] * M[2][0] + 
	M[0][2] * M[1][0] * M[2][1] );
	sub = (
	M[0][0] * M[1][2] * M[2][1] + 
	M[0][1] * M[1][0] * M[2][2] + 
	M[0][2] * M[1][1] * M[2][0] );
	return soma-sub;
}

int main(){
	srand(time(NULL));
	int M[3][3];
	
	// for que inciará matriz com números aleatórios.
	for(int i = 0; i < TAM;++i)
		for(int j = 0; j < TAM;++j)
			M[i][j] = rand()%10;
			
	printf("Matriz:\n\n"); exibirMatriz(M);
	printf("\ndet(M) = %d", calculaDetM_3(M));
	return 0;
}
