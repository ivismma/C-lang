#include <stdio.h>
#include <stdbool.h>

// Exibe todos os números primos até o valor n.
// Implementação recursiva.
void npRecursivo(int n, int numAtual, int i, bool primo);
void recursao(int n, int numAtual, int i, bool primo);

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

// Essa função auxiliar serve para exibir o único número par e evitar percorrer
// pares desnecessariamente na recursão, já que 2 é o único par.
// Ou seja, ao invés de fazer numAtual+1, o passo recursivo será numAtual+2

void npRecursivo(int n, int numAtual, int i, bool primo){
	printf("2 "); // Considerando chamada da função n sempre >= 2:
	
	if(n >= 3) recursao(n, 3, 1, true);
	
	return;
}

void recursao(int n, int numAtual, int i, bool primo){
	if(numAtual > n) return; // caso base: atingir limite n.
	if(i > 1)
		if(numAtual%i == 0)
			recursao(n, numAtual, 1, false); // Define i = 1, como se fosse um break.
		else
			recursao(n, numAtual, i-1, true); // Continua checando.. por enquanto é primo.
	else{ // i == 1
		if(primo){
			printf("%d ", numAtual); // Imprime o nª primo.
			recursao(n, numAtual+2, (numAtual+2)/2, true);
		}
		else     // Não é primo.
			recursao(n, numAtual+2, (numAtual+2)/2, true);
	}
}
