#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*
Questão antiga Prog I

A série infinita mostrada abaixo pode ser usada para estimar o valor de log(1+x), 
sendo -1 < x <= 1. Usando essa série, escreva uma função recursiva em C para estimar log(1+x).
Tanto o valor de x quanto número n de elementos da série deverão ser passados como argumentos para
a função. É permitido usar a função pow() da biblioteca <math.h>.

            log(1+x) = x - x²/2 + x³/3 - ... + ... - ... n vezes

*/

bool par(int i){ return (!(i & 1))? true : false; }
double rserie(double x, int n, int i, double soma);
double serie(double x, int n) { return rserie(x, n, 1, 0); }

int main(void){
	double x;
	int n;
	
	printf("Digite x (-1 < x <= 1)\n--> ");
	scanf("%lf", &x);
	if(x <= -1 || x > 1) return 1;
	
	printf("Digite n\n--> ");
	scanf("%d", &n);
	
	double res = serie(x, n);
	printf("Resultado da série log(%.3lf): %.3lf", 1+x, res);
	
	return 0;
}

double rserie(double x, int n, int i, double soma){
	if(i > n) return soma;

	if(par(i))
		return rserie(x, n, i+1, soma-pow(x, i)/i);
	else
		return rserie(x, n, i+1, soma+pow(x, i)/i);
}
