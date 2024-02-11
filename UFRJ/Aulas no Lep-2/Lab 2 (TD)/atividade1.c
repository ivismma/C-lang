/*
Autor: Ivis Muzi
Data: 23/08/2023
Descrição: Calcula a média aritmética entre três notas.
Entrada: As três notas para efeito de cálculo.
Saída: A média aritmética entre três notas.
Defesa: Nota inserida fora do intervalo [0, 10].
*/

#include <stdio.h>
#define TAM 3 // Quantidade de notas para a média.

int main(){ 
	float nota, soma = 0;
	int i;
	// Retorna 0 quando houve êxito na execução do programa.
	// Retorna -1 quando há nota inserida é maior do que 10 ou menor do que 0.

	for(i=0;i < TAM;i++){
		printf("Digite o valor da %dº nota: \n", i+1);
		scanf("%f", &nota);
		if(nota < 0 || nota > 10){
			printf("ERRO - Nota inválida.\n");
			return -1;
		}
		soma += nota;
	}
	printf("O resultado da média aritmética das três notas é: %.2f.\n", soma/TAM);
	return 0;
}
