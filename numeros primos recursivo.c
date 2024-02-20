#include <stdio.h>
#include <stdbool.h>

// Exibe todos os números primos até o valor n.
// Implementação recursiva.
void npRecursivo(int n, int numAtual, int i, bool primo);

int main(void){
	int n;

	printf("Digite um valor n maior ou igual a 2: ");
	scanf("%d", &n);
	if(n < 2){
		puts("Entrada invalida.");
		return 1;
	} 
	    // 2 é o primeiro primo, o 1(i) é numAtual/2.
	npRecursivo(n, 2, 1, true);

	return 0;
}

void npRecursivo(int n, int numAtual, int i, bool primo){ // RECURSIVO
	if(numAtual > n) return; // caso base: atingir limite n.
	if(i > 1)
		if(numAtual%i == 0)
			npRecursivo(n, numAtual, 1, false); // Define i = 1, como se fosse um break.
		else
			npRecursivo(n, numAtual, i-1, true); // Continua checando.. por enquanto é primo.
	else{ // i == 1
		if(primo){
			printf("%d ", numAtual); // Imprime o nª primo.
			npRecursivo(n, numAtual+1, (numAtual+1)/2, true);
		}
		else     // Não é primo.
			npRecursivo(n, numAtual+1, (numAtual+1)/2, true);
	}
}
