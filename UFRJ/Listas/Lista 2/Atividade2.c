/*Escreva um programa em C que imprima uma figura como a mostrada abaixo. O
número de linhas da figura deve ser informado pelo usuário, mas não pode ser maior que 10. Não
crie uma função específica para isso (ou seja, simplesmente escreva toda a lógica na main()).

// A imagem é como se fosse uma pirâmide de asteriscos.

Descrição: Algoritmo que recebe um valor n e cria uma pirâmide de asteriscos com n linhas.
Entrada: Valor n (Quantidade de linhas da pirâmide).
Saída: A pirâmide em formato de asteriscos.
Defesa: Valor n deve ser um número do intervalo [1,10].
*/

// Utilizar tudo na main.

#include <stdio.h>

int main(){
	int n,q,j=0, k=0;
	
	do{ // DEFESA
		printf("Digite um valor n entre 1 e 10: ");
		scanf("%d", &n);
	} while(n < 1 || n > 10);
	
	printf("\n");
	q = n; // q recebe a quantidade de linhas.
	
	for(int i=0; i < n; i++, j = 0, k = 0, q -= 1){
		while(j < q){ // Quantidade de espaços inseridos até a colocação dos asteriscos.
			printf(" ");
			++j;
		}
		while (k < 1+2*i){ // Quantidade de asteriscos que serão colocados na iteração atual.
			printf("*");
			++k;
		}
		printf("\n"); // Pula uma linha para próxima iteração de asteriscos.
		 // A cada passo, (i++, j=0, k = 0, q-=1), Nesse último, subtrai 1 do q.
	}

	return 0;
}
