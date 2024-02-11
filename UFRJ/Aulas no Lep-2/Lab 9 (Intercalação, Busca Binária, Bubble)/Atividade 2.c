/*Complete o programa em C abaixo, para que ele realize a multiplicação e também a
soma de duas matrizes quadradas e em seguida exiba na tela tanto as matrizes de entrada quanto a
matriz resultante de cada operação.
Copie o código abaixo (onde as matrizes de entrada e a resultante são inicializadas) e
implemente a função reportarOpMatrizes(). Siga as instruções descritas após o código!
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 2 //Alterar esse valor ao testar outras dimensões!

void reportarOpMatrizes(int A[DIM][DIM],int B[DIM][DIM],int C[DIM][DIM],char op);
int main() {
	int A[DIM][DIM] = { {-4, 2}, {3, 7} }; //”Comente” ao testar o caso 3x3
	int B[DIM][DIM] = { {1, -2}, {12, 9} };
	//int A[DIM][DIM] = { {3, 4, 5}, {8, -2, 7}, {9, 0, 5} }; //”Descomente” ao testar
	//int B[DIM][DIM] = { {5, 1, 2}, {-8, 2, 2}, {11, 4, 9} };
	int C[DIM][DIM] = { 0 }; //Inicializa com 0 TODOS os elementos de C!
	/* MULTIPLICAÇÃO */
	//Implementar aqui!
	reportarOpMatrizes(A, B, C, 'X');
	printf("\n");
	/* SOMA */
	// reportarOpMatrizes(A, B, C, '+');
	
	return 0;
}
void reportarOpMatrizes(int A[DIM][DIM],int B[DIM][DIM],int C[DIM][DIM],char op){
	int i, j;
	
	if(op == '+')
	{
		for(i = 0;i < DIM;i++){
			for(j = 0;j < DIM;j++){
				C[i][j] = A[i][j] + B[i][j];
			}
		}
	printf("Resultado da soma: \n\n");
		for(i = 0; i < DIM;i++){
			for(j = 0; j < DIM;j++){
				printf("%d  ", C[i][j]);
			} printf("\n");
		}
	}
	else if(op == 'X' || op == 'x' || op == '*')
	{
		for (int i = 0; i < DIM; ++i) {
        	for (int j = 0; j < DIM; ++j) {
	            for (int k = 0; k < DIM; ++k) {
	                C[i][j] += A[i][k] * B[k][j];
	            }
	        }
	    }
		
		printf("\nResultado da multiplicação: \n\n");
		for(i = 0; i < DIM;i++){
			for(j = 0; j < DIM;j++){
				printf("%d  ", C[i][j]);
			} printf("\n");
		}
	}
	else{
		printf("Operador inválido.");
	}
}
