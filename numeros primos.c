#include <stdio.h>
#include <stdbool.h>

// Exibe todos os números primos até o valor n.
void numerosPrimos(int n);

int main(void){
	int n;

	printf("Digite um valor maior ou igual a 2: ");
	scanf("%d", &n);
	if(n < 2){
		puts("Entrada invalida.");
		return 1;
	} 
	
	numerosPrimos(n);

	return 0;
}

void numerosPrimos(int n){            // ITERATIVO
	int numAtual = 2; // 1º número primo.
	
	while(numAtual <= n){
		bool primo = true; // inicia cada nº presumindo que seja primo.
		for(int i = numAtual/2; i > 1; --i){
			if(numAtual%i == 0){ // Encontrou um divisível.
				primo = false;
				break;
			}
		}
		if(primo) printf("%d ", numAtual);
		++numAtual;
	}
	
	return;
}
