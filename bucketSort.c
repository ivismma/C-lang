// implementa��o do bucket sort considerando apenas
// n�meros inteiros

// bucket sort � um algoritmo de ordena��o O(n), �
// ordena por compara��o, mas por contagem.

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
	// incializa qtd de baldes necess�ria: diff entre (max e min) + 1
	int buckets_amount = max-min+1;
	int *buckets = (int *) calloc(buckets_amount, sizeof(int));
	
	// conta todos d�gitos e soma nos baldes -> O(n)
	for(int i = 0; i < size; ++i)
		++buckets[v[i]-min]; 
		// descontando min: ex.: [2,6] -> valor 2 precisa ser mapeado para �nd. 0 do vetor.
		// que � 2 - min = 0.

	// modifica vetor adicionando buckets[i] vezes cada elemento -> O(n)
	// � O(n) pois a soma dos elementos dos baldes ser� o tam. do vetor.
	int k = 0;
	for(int i = 0; i < buckets_amount; ++i)
		for(int j = 0; j < buckets[i]; ++j)
			v[k++] = i+min;
	free(buckets);
}









void showArray(int *v, int size){
	for(int i = 0; i < size; ++i)
		printf("%d ", v[i]);
	puts("");
}
