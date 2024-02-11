/*
Atividade 1: Você implementará um TAD para representar (i) um polinômio de grau máximo = 3
e que possui uma única variável e coeficientes racionais, e (ii) um subconjunto de operações a
ele aplicáveis. Também implementará um programa que faça uso desse TAD, oferecendo ao
usuário as operações que você disponibilizou. Para isso, siga as instruções abaixo.
Primeiro: crie 3 arquivos dentro de um mesmo diretório, com os seguintes nomes:
● main.c
● polinomio.c
● polinomio.h
*/

#include "polinomio.h"
#include <stdio.h>

int main(){
	int x;
	polinomio p1, p2, p_res;
	solucao p_raiz;
	// Soma de polinômios: 
	printf("Soma de polinômios:\n");
	printf("Polinomio 1:\n");
	printf("Digite as constantes c3, c2, c1 e c0, respectivamente (separada por espaços):\n");
	scanf("%f %f %f %f", &p1.c3, &p1.c2, &p1.c1, &p1.c0);
	printf("Polinomio 2:\n");
	scanf("%f %f %f %f", &p2.c3, &p2.c2, &p2.c1, &p2.c0);
	printf("Digite as constantes c3, c2, c1 e c0, respectivamente (separada por espaços):\n");
	p_res = somaPolinomio(p1,p2);
	printf("A soma desses polinômios é: \nc3: %.2f\nc2: %.2f\nc1: %.2f\nc0: %.2f\n", p_res.c3, p_res.c2, p_res.c1, p_res.c0);
	// Derivação de polinômio: 
	printf("\nDerivação de polinômio:\n");
	printf("Digite as constantes c3, c2, c1 e c0, respectivamente (separada por espaços):\n");
	scanf("%f %f %f %f", &p1.c3, &p1.c2, &p1.c1, &p1.c0);
	p_res = derivaPolinomio(p1);
	printf("Polinômio derivado: \nc3: %.2f\nc2: %.2f\nc1: %.2f\nc0: %.2f\n", p_res.c3, p_res.c2, p_res.c1, p_res.c0);
	// Raízes de uma eq. do 2º grau (com defesa)
	printf("\nRaízes de polinômio de 2º grau:\n");
	p1.c3 = 0;
	do{
		printf("Digite as constantes c3, c2, c1 e c0, respectivamente (separada por espaços):\n");
		printf("A constante c3 deve ser zero.\n");
		scanf("%f %f %f %f", &p1.c3, &p1.c2, &p1.c1, &p1.c0);
	} while(p1.c3);
	p_raiz = raizesPolinomio(p1);
	printf("As raízes são %.2f e %.2f", p_raiz.x1, p_raiz.x2);
	// Valor de um polinômio dado x
	printf("\nValor de f(x): \n");
	printf("Digite as constantes c3, c2, c1 e c0, respectivamente (separada por espaços):\n");
	scanf("%f %f %f %f", &p1.c3, &p1.c2, &p1.c1, &p1.c0);
	printf("Digite o valor x: ");
	scanf("%d", &x);
	printf("f(%d) = %.2f", x, valorPolinomio(p1, x));
	return 0;
}
