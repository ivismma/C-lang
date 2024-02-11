/*Questão 3) Agora sim, modifique o exercício anterior como segue: crie uma função chamada
arvore e que possui a seguinte assinatura:
void arvore(int linhas, int invertida);

Esta função, ao ser chamada, deverá imprimir uma imagem como a do exercício anterior, para o
total de linhas fornecido. Aqui, porém, há duas possibilidades de impressão:
a) Caso o parâmetro invertida seja igual a 0 (isto é, falso), imprimir como no exercício
anterior.
b) Caso contrário, imprimir a imagem “de cabeça para baixo”.

Descrição: Algoritmo que recebe um valor n e um formato, cria uma pirâmide de asteriscos com n linhas de acordo com o formato fornecido.
Entrada: Valor n (Quantidade de linhas da pirâmide) e o formato da pirâmide.
Saída: A pirâmide em formato de asteriscos.
Defesa: Valor n deve ser um número do intervalo [1,10].
*/

#include <stdio.h>

void arvore(int linhas, int invertida);
int lerInt(char s[40]);

int main(){
	int n, formato;
	do{ // DEFESA
		n = lerInt("Digite um valor n entre 1 e 10: ");
	} while(n < 1 || n > 10);
	formato = lerInt("Digite 0 para obter uma pirâmide invertida ou qualquer outro valor para uma pirâmide normal: ");
	printf("\n");
	arvore(n,formato);
	return 0;
}

int lerInt(char s[40]){
	int x;
	printf("%s", s); scanf("%d",&x);
	return x;
}

void arvore(int linhas, int invertida){
	int q = linhas, j=0, k=0; // q recebe a quantidade de linhas.
	if(!invertida){ // Caso (a):
		for(int i=0; i < linhas; i++, j = 0, k = 0, q -= 1){
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
		} return;
	}
	// Caso (b):
	int cont = 0;
	for(int i=linhas; i > 0; i--, j = 0, k = 0, q = 1+i*2, cont++){
		q = -1+i*2;
		while(k < cont){
			printf(" ");
			++k;
		}
		while(j < q){
			printf("*");
			++j;
		}
		printf("\n");
	}
}


