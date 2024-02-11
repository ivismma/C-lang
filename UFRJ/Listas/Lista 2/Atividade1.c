/*
Descrição: Calcular a raíz quadrada de um número através do Método de Newton.
Entrada: Número (n) e um chute inicial de sua raíz (x0).
Saída: A raiz quadrada de n pelo Método de Newton e pelo pow() da biblioteca <math.h>.
Defesa: O valor n deve ser um número racional.
*/

#include <stdio.h>
#include <math.h>

double metodoDeNewton(double n){
	double x = 10, xantes; // x0 é igual a 10.
	 while(fabs(x-xantes) > pow(10,-6)){
	 	xantes = x;
		x = xantes - (pow(xantes,2)-n)/(2*xantes);
	 }
	return x;
}

void exibirResultado(double n, double res){
	printf("\nO número inserido foi: %.3f\n", n);
	printf("O resultado da raiz quadrada utilizando o Método de Newton é: %f\n", res);
	printf("O resultado da raiz quadrada utilizando o pow() da math.h é: %f\n", pow(n,0.5));
}

int main(){
	double res,n;
	do{ // DEFESA
		printf("Digite um valor n racional: ");
		scanf("%lf", &n);
		if(n == 0)
			printf("ERRO - O Número deve ser diferente de zero.\n");
	} while (n == 0);	
	res = metodoDeNewton(n);
	exibirResultado(n, res);
	
	return 0;
}
