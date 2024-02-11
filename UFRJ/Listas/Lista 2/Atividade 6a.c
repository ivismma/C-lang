/*
Q6 a) Implemente a versão recursiva da Questão 1 desta lista (método de Newton).

Obs:
Entrada e saída: A entrada é um número racional. A saída são 3 números: (i) o número lido, (ii) a
raiz quadrada calculada com a função sqrt da biblioteca matemática <math.h> e (iii) a raiz quadrada
calculada com o método que você escreveu.
*/
#include <math.h>
#include <stdio.h>

double metodoNewtonRec(double n, double x){
	return (fabs(x*x - n) < pow(10,-6))? x: metodoNewtonRec(n, x-(x*x - n)/(2*x));
}

int main(){
	double n;
	
	printf("Digite um numero para obter a raiz quadrada através do Metodo de Newton: ");
	scanf("%lf", &n);
	printf("\n Número inserido: %f", n);
	printf("\n Raiz quadrada pelo sqrt(): %f", sqrt(n));
	printf("\n Raiz quadrada pelo Metodo de Newton: %f", metodoNewtonRec(n, 10));
	
	return 0;
}
