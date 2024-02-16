#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define TAM 6

// Vetores de tamanhos iguais.
void intercala1(int vetA[], int tamA, int vetB[], int tamB);
// Vetores de tamanhos iguais ou diferentes.
void intercala2(int vetA[], int tamA, int vetB[], int tamB);

int main(void){
	int 
		vetA[TAM] = {1, 2, 3, 4, 5, 6},
		vetB[TAM] = {10, 20, 30, 40, 50, 60},
		tamA = sizeof(vetA)/sizeof(int),
		tamB = sizeof(vetB)/sizeof(int);
	
	// intercala1(vetA, tamA, vetB, tamB);
	intercala2(vetA, tamA, vetB, tamB);
	
	return 0;
}

// Para vetores de tamanhos iguais.
void intercala1(int vetA[], int tamA, int vetB[], int tamB){
	if(tamA != tamB){
		printf("Tamanho de vetA != vetB.\n");
		exit(1);
	}
	int i = 0, j = 0, cont = 0;
	
	while(cont < tamA+tamB){
		if(cont%2 == 0)
			printf("%d ", vetA[i++]);
		else
			printf("%d ", vetB[j++]);
		++cont;
	}
	
	return;
}

// Para vetores de tamanhos distintos/iguais.
void intercala2(int vetA[], int tamA, int vetB[], int tamB){
	int menor, i = 0, j = 0, cont = 0;
	
	if(menor == tamA || tamA < tamB) menor = tamA*2;
	else menor = tamB*2;
	
	while(cont < menor){
		if(cont%2 == 0)
			printf("%d ", vetA[i++]);
		else
			printf("%d ", vetB[j++]);
		++cont;
	}
	if(tamA == tamB) return;
	
	if(cont%2 == 0) // Restou vetB
		while(i < tamA) printf("%d ", vetB[j++]);
	else            // Restou vetA
		while(j < tamB) printf("%d ", vetA[i++]);

	return;		
}
