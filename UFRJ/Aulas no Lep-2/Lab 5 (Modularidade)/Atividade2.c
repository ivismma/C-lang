#include <stdio.h>
#define TRUE 1
#define FALSE 0

// Seu programa deverá conter 3 funções:

// 1) main()

/*2) int totalLEDS(int n), que recebe o valor n coletado na main() e
retorna o total de LEDS necessários para reproduzi-lo no painel.*/

/*3) int ledsAlgarismo(int a), que recebe da função ‘totalLEDS’ um único
dígito (isto é, um algarismo entre 0 e 9), e retorna o total de LEDs necessários
para aquele único dígito.*/

int ledsAlgarismo(int a){ // Infelizmente não existe uma maneira mais otimizada de fazer essas verificações.
	if(a == 6 || a == 8 || a == 9 || a == 0)
		return 6;
	else if(a == 2 || a == 3 || a == 5)
		return 5;
	else if(a == 1)
		return 2;
	else if(a == 4)
		return 4;
	else
		return 3;
}

int totalLEDS(int n){
	int total = ledsAlgarismo(n%10), proxD;
	for(proxD = n;n != n%10;n/=10){
		proxD = n%10;
		total += ledsAlgarismo(proxD);
	}
	return total;
}

int main(){
	int n, res; // res = resultado.
	
	printf("Qual o número desejado do LED? --> ");
	scanf("%d", &n);
	res = totalLEDS(n);
	printf("O total de LEDS que serão necessários para compor esse número é: %d\n", res);

	return 0;
}
