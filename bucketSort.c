// implementação do bucket sort considerando apenas
// números inteiros

// bucket sort é um algoritmo de ordenação O(n), ñ
// ordena por comparação, mas por contagem.

#include <stdio.h>
#include <stdlib.h>

void bucketSort(int *v, int size, int min, int max);
void showArray(int *v, int size);

int main(void){
	int v[] = {8,1,5,7,0,-1,3,2,-2,7,9,1,-3,3,8,3,2,11};
	int size = sizeof(v)/sizeof(v[0]);
	
	showArray(v, size);
	bucketSort(v, size, -3, 11);
	showArray(v, size);

	return 0;
}


void bucketSort(int *v, int size, int min, int max){
	// inicializa qtd de baldes necessários (r): diff entre (max e min) + 1
	int r = max-min+1;
	int *buckets = (int *) calloc(r, sizeof(int)); // -> O(r)
	
	// conta todos dígitos e soma nos baldes -> O(n)
	for(int i = 0; i < size; ++i)
		++buckets[v[i]-min]; 
		// descontando min: ex.: [2,6] -> valor 2 precisa ser mapeado para índ. 0 do vetor.
		// que é 2 - min = 0.

	// modifica vetor adicionando buckets[i] vezes cada elemento -> O(n)
	// é O(n) pois a soma dos elementos dos baldes será o tam. do vetor.
	int k = 0;
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < buckets[i]; ++j)
			v[k++] = i+min;
	free(buckets);
}









void showArray(int *v, int size){
	for(int i = 0; i < size; ++i)
		printf("%d ", v[i]);
	puts("");
}
