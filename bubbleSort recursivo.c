#include <stdio.h>
#include <stdbool.h>

// algoritmo de ordenação bubble sort, porém, recursivo.
// sei lá deu vontade

void bubbleSort(int *v, int i, int fim, bool ordenado);
void exibir(int *v, int tam);

int main(void){

	int v[] = {4,0,2,7,3,5,10,2,5,9};
	const int tam = sizeof(v)/sizeof(v[0]);
	
	exibir(v, tam);
	puts("\n");
	
	bubbleSort(v, 0, tam-1, true);

	exibir(v, tam);

	return 0;
}

// contemplável para tail call optimization.
void bubbleSort(int *v, int i, int fim, bool ordenado){
	if(i < fim){
		if(v[i] > v[i+1]){
			int aux = v[i];
			v[i] = v[i+1];
			v[i+1] = aux;
			bubbleSort(v,i+1, fim, false);
		}
		else
			bubbleSort(v,i+1, fim, ordenado);
	}
	else{
		if(!ordenado)
			bubbleSort(v,0, fim-1, true);
		else 
			return; // CASO BASE
	}
}

void exibir(int *v, int tam){
	int i = 0;
	while(i < tam) printf("%d ", v[i++]);
}
