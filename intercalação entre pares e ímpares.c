/*
Crie uma função que receba um vetor de inteiros e possui o seguinte objetivo:

A função deverá exibir na tela os elementos do vetor intercalando entre
valores positivos e negativos, começando pelos positivos.

Se houver somente valores positivos, imprimir todos, a mesma regra vale para
somente negativos.

Se houver mais positivos do que negativos, imprimir o restante dos positivos 
após a intercalação, o mesmo vale para caso haja somente negativos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool positivo(int n){ return (n >= 0); }
void intercalar(int *v, short tam);

int main(void){
	int v[] = {-10,3,2,-5,4,6,-1,2};
	short tam = (sizeof(v)/sizeof(v[0]));
	
	intercalar(v, tam);
	
	return 0;
}

void intercalar(int *v, short tam){
	int i = 0, j = 0, cont = 0;
	bool alterna = true; // true -> imprimir positivo | false -> imprimir negativo.
	
	int *positivos = (int*) malloc(tam*sizeof(int));
	int *negativos = (int*) malloc(tam*sizeof(int));
	int tam_p = 0, tam_n = 0;
	
	while(cont < tam){
		if(positivo(v[cont])){
			positivos[i++] = v[cont];
			++tam_p;
		}
		else{
			negativos[j++] = v[cont];
			++tam_n;
		}
		++cont;
	} 
	
	i = 0, j = 0;
	while(i < tam_p && j < tam_n){
		if(alterna){
			printf("%d ", positivos[i++]);
			alterna = false;
		}
		else{
			printf("%d ", negativos[j++]);
			alterna = true;
		}
	}
	
	if(alterna) // Sobrou pares
		while(printf("%d ", positivos[i++]), i < tam_p);
	else // Sobrou impares
		while(printf("%d ", negativos[j++]), j < tam_n);
	
	free(positivos);
	free(negativos);
}

