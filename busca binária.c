#include <stdio.h>

// Implementação de uma busca binária p/ todos elementos de um array
// busca em vetores ordenados - retorna o índice (se existir).

// complexidade O(log n) -> o algoritmo quebra na metade a cada iteração.
// melhor caso: O(1) -> a busca está no meio do array (1 iteração).

int binarySearch(int *v, int size, int key);

int main(void){

	int v[] = {0,0,1,4,6,8,8,9,10,11,12,14,16,18,19};
	int size = sizeof(v)/sizeof(v[0]);
	
	int toFind = 18; // valor a ser buscado
	int res = binarySearch(v, size, toFind);
	if(res != -1)
		printf("valor buscado: %d -> indice: %d\n", toFind, res);
	else
		printf("Nao encontrado.\n");
	
	return 0;
}

int binarySearch(int *v, int size, int key){
	int left = 0;       // inicio
	int mid;            // meio
	int right = size-1;  // fim
	
	while(left <= right){   // enquanto esq e dir nao se cruzarem..
		mid = (left+right)/2;
		if(key == v[mid])     return mid;     // achou o valor.
		else if(key > v[mid]) left = mid+1;   // é maior que o meio (aumenta esq para depois do meio atual).
		else                  right = mid-1;  // é menor que o meio (diminui direita para antes do meio atual).
	}
	return -1; // se não for encontrado, retornará -1.
}
