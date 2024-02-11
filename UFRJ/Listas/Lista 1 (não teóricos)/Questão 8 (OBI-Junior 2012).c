/*Questão 8) (adaptada da OBI 2012, Fase 2, Nível Júnior):
João deseja fazer bolos usando uma receita que indica que devem ser usadas
2 xícaras de farinha de trigo, 3 ovos e 5 colheres de sopa de leite.
Em casa ele tem A xícaras de farinha de trigo, B ovos e C colheres de sopa de leite.
João não tem muita prática com a cozinha, e portanto ele só se arriscará a fazer
medidas exatas da receita de bolo (por exemplo, se ele tiver material suficiente para
fazer mais do que 2 e menos do que 3 bolos, ele fará somente 2 bolos).
Sabendo disso, escreva um programa que determine qual a quantidade máxima de
bolos que ele consegue fazer. */

#include <stdio.h>

int menor(x,y,z){ // Retorna o menor número entre três.
	return (x < y && x < z)? x: (y < z)? y:z; // if utilizando Operador ternário.
}

int main(){
	int a, b, c, qtd; // a = xícaras de farinha | b = ovos | c = colheres de sopa de leite. | qtd = Quantidade de bolos.
	
	printf("Quantas xícaras de farinha?\n");
	scanf("%d", &a);
	printf("Quantos ovos?\n");
	scanf("%d", &b);
	printf("Quantas colheres de sopa de leite?\n");
	scanf("%d", &c);
	
	a = a/2; b = b/3;c = c/5; // a,b e c são, respectivamente, a quantidade de bolos que são possíveis fazer com o ingrediente (individualmente).
	qtd = menor(a,b,c); // João consegue fazer a quantidade de bolos contanto que todos os ingredientes sejam suficientes --> a quantidade será de quantos bolos fazem o ingrediente que não está sobrando para mais um bolo. <--
	printf("João consegue fazer %d bolo(s) com a quantidade de ingredientes disponíveis.", qtd);
	
	return 0;
}
