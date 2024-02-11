/*Atividade 1: Chama-se Quadrado Mágico uma matriz quadrada de números em que a soma
de cada coluna, de cada linha e das duas diagonais são iguais. Veja o exemplo para uma
matriz 3x3:
2 7 6
9 5 1
4 3 8
Tarefa: Escreva um programa em C que receba como entrada uma matriz quadrada de
ordem N (1 < N < 100) e imprima na tela se trata-se de um quadrado mágico ou não.
Entrada: A entrada contém um inteiro indicando a dimensão da matriz e em seguida os
elementos da matriz.
Saída: O seu programa deve imprimir “Verdadeiro”, quando a matriz de entrada for um
quadrado mágico, ou “Falso” caso contrário.
*/

#include <stdio.h>
#define FALSE 0
#define TRUE 1

void exibirMatriz(int tam, int m[tam][tam]){
	int j;
	for(int i = 0; i < tam; i++){
		for(j = 0; j < tam; j++){
			printf("%d  ", m[i][j]);
		} printf("\n");
	}
}

void checaQuadMagico(int tam, int m[tam][tam]){
	
	int soma = 0, teste, equivalente = FALSE;
	int i, j;
	for(i = 0,j = 0;j < tam;j++){ // Checa o canto de cima
		soma += m[i][j];
	} teste = soma; soma = 0; 
	
	for(i = 0;i < tam;i++){ // Checa o canto direito
		soma += m[i][tam-1];
	} equivalente = (soma == teste);
	if(!equivalente){
		printf("FALSO"); return;
	} soma = 0;
	
	for(i = 0;i < tam;i++){ // Checa o canto esquerdo
		soma += m[i][0];	
	} equivalente = (soma == teste);
	if(!equivalente){
		printf("FALSO"); return;
	} soma = 0;

	for(j = 0;j < tam;j++){ // Checa o canto de baixo
		soma += m[tam-1][j];	
	} equivalente = (soma == teste);
	if(!equivalente){
		printf("FALSO"); return;
	} soma = 0;
	
	for(i = 0, j = 0;i < tam;i++,j++){ // Checa a diagonal da esquerda para direita
		soma += m[i][j];
	} equivalente = (soma == teste);
	if(!equivalente){
		printf("FALSO"); return;
	} soma = 0;
	
	for(i = 0, j = tam-1;i < tam;i++,j--){ // Checa a diagonal da direita para esquerda
		soma += m[i][j];	
	} equivalente = (soma == teste);
	if(!equivalente){
		printf("FALSO"); return;
	} soma = 0;
	
	printf("VERDADEIRO"); return;
}

int main(){
	int tam, j;
	
	do{
		printf("Digite o número n (intervalo ]1,100[ ) que será a ordem da matriz quadrada n x n: ");
		scanf("%d", &tam);
	} while (tam <= 1 || tam >= 100);
	int m[tam][tam];
	
	for(int i = 0, n; i < tam;i++){
		printf("Digite a linha %d da matriz (separada por espaços): \n", i+1);
		for(j = 0; j < tam;j++){
			scanf("%d", &n); m[i][j] = n;
		}
	}
	
	printf("\n");
	exibirMatriz(tam, m); printf("\n");
	checaQuadMagico(tam, m);
	
	return 0;
}
