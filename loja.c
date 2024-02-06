#include <stdio.h>
#include <locale.h>

// Lista 4 - Exercício 4 (Desafio)

void simular(char nivel, float valor);

int main(void){
	char nivel;
	float valor;

	do{
		printf("Digite o valor da compra:\n--> R$ ");
		scanf("%f", &valor);
	} while(valor <= 0);
	getchar();
	printf("Digite o nível do cliente:\nb - Bronze\np - Prata\no - Ouro\n--> ");
	scanf("%c", &nivel);
	
	simular(nivel, valor);

	return 0;
}

void simular(char nivel, float valor){
	setlocale(LC_ALL,"Portuguese");
	
	printf("\n");
	switch(nivel){
		case 'b':
			valor *= 0.96; // 4% de desconto
			printf("Cliente: Bronze\n");
			printf("Valor com desconto: R$ %.2f", valor);
			break;
		case 'p':
			valor *= 0.94; // 6% de desconto
			printf("Cliente: Prata\n");
			printf("Valor com desconto: R$ %.2f", valor);
			break;
		case 'o':
			valor *= 0.92; // 8% de desconto
			printf("Cliente: Ouro\n");
			printf("Valor com desconto: R$ %.2f", valor);
			break;
		default:
			printf("Nível do cliente inserido é inválido.\n");
			break;
	}
	return;
}

/*

9. DESAFIO - Uma loja de eletrônicos possui um sistema de níveis, ele funciona da
seguinte forma: Clientes que já gastaram mais de R$ 300 nos últimos 30 dias
recebem 4% em uma compra, Clientes que já gastaram mais de R$ 800, 6%
em uma compra, e clientes que já gastaram mais de R$ 2000, 8%.
Os níveis são chamados, respectivamente de: bronze, prata e ouro.
Crie um programa que recebe o nível de um determinado cliente e o valor da
sua compra atual no caixa, o programa deverá imprimir na tela:

- O nível atual do cliente (antes da compra).
- O valor da compra atual, com os descontos aplicados.
Ex: simular(‘p’, 1418.22);
Saída:
Cliente: Prata
Valor com desconto: R$ 1333,12.

OBS: Se o valor da compra inserido for menor que zero, o programa deverá
solicitar um novo valor da compra até que seja válido

*/
