/*
Atividade 3: Escreva um programa em C que leia do teclado uma única string no formato
<código> <preço> <desconto>
com: (1) código de um produto (palavra que pode conter letras e números); (2) preço do produto
(valor em reais); e (3) percentual de desconto do produto. Note que os 3 campos são separados por
um espaço. O programa deverá calcular o novo valor do produto com o desconto dado, gerar uma
nova string no formatO <código> <preço com desconto> e exibir essa string na tela.
Use as funções sscanf e sprintf.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){ // Vou utilizar Ponteiros na string para continuar praticando.
	char *str, *str2, codigo[20+1]; // str 2 = string final | código com até 20 caracteres.
	float preco, desconto;
	str = (char *) malloc(50 * sizeof(char));
	str2 = (char *) malloc(50 * sizeof(char));
	
	puts("Insira <código> <preço> <desconto>"); 
	gets(str); // Lê string.
	str = (char *) realloc(str, strlen(str)+1); // Realocação para otimização de memória
	
	// Código | preço | desconto, respeitando a questão --> em percentual, a ser convertido.
	sscanf(str, "%s %f %f", codigo, &preco, &desconto);
	if(!preco || !desconto || !codigo){ // Se uma das entradas é inválida, retorna -1.
		printf("Entrada inválida.");
		return -1;
	}
	desconto /= 100; // Desconto vira percentual. Ex: Insere 12 --> 12% de desconto (0.12).
	preco *= (1-desconto); // Alterando a variável preço, considerando que seu dado antigo não será mais utilizada no futuro.
	
	sprintf(str2, "%s %.2f", codigo, preco); // Criando a string final (saída).
	str2 = (char *) realloc(str2, strlen(str2)+1); // Realocação para otimização de memória.
	printf("Código e preço com desconto aplicado: %s", str2);
	
	return 0;
}
