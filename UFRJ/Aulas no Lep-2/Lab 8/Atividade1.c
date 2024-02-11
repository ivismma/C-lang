/*Atividade 1: Na Matemática, dados dois vetores v e w (com início na origem) em um espaço de N
dimensões (RN), o produto interno desses dois vetores é o escalar denotado por v.w

definido por:
• v.w = v1 * w1 + v2 * w2, se v = (v1, v2) e w = (w1, w2) são vetores no espaço de duas dimensões;
• v.w = v1 * w1 + v2 * w2 + v3 * w3, se v = (v1, v2, v3) e w = (w1, w2, w3) são vetores no espaço de
três dimensões;
...e assim sucessivamente.
Exemplo: (-5, 2) . (3, 7) = -5*3 + 2*7 = -15 + 14 = -1
Tarefa:
1) Escreva uma função para calcular o produto interno de dois vetores de mesma dimensão N,
sendo 0 < N <= 10. A função deverá receber os dois vetores e sua dimensão como
parâmetros de entrada, e retornar o produto interno calculado.
2) Escreva um programa para testar a sua função usando os casos de teste abaixo. Leia do
teclado a dimensão e o conteúdo dos dois vetores.*/

#include <stdio.h>

float produtoInterno(float v[], float w[], int qtd){
	float soma = 0;
	for(int i = 0; i < qtd; ++i){
		soma += (v[i])*(w[i]);
	} return soma;
}

int main(){
	
	short int dimensoes, i = 0;
	float valor, res;
	do{
		printf("Digite a quantidade de dimensões (Entre 1 e 10) --> ");
		scanf("%d", &dimensoes);
	} while(dimensoes <= 0 && dimensoes > 10);
	float v[dimensoes], w[dimensoes]; printf("\n");
	
	while(i < dimensoes){
		printf("Insira o %d-n-esimo elemento do vetor v: ", i+1);
		scanf("%f", &v[i]);
		++i;
	} i = 0; printf("\n");
	while(i < dimensoes){
		printf("Insira o %d-n-esimo elemento do vetor w: ", i+1);
		scanf("%f", &w[i]);
		++i;
	}

	res = produtoInterno(v,w,dimensoes);
	printf("O resultado do produto interno entre os vetores é: %.2f", res);
	return 0;
}
