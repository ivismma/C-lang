/*Atividade 3 (Desafio!): Escreva um programa em C para ordenar um vetor em ordem crescente. O
programa deverá receber como entrada um vetor de inteiros de dimensão N, ordenar os seus
elementos em ordem crescente e imprimir o resultado na tela.*/

// Criar um algoritmo de ordenação utilizando a própria cabeça (não ser um algoritmo de ordenação "existente").

#include <stdio.h>
#include <limits.h>

void copiaVetor(int v[],int vaux[],int tam){
	for (int i = 0; i < tam; i++)
   		vaux[i] = v[i];
}

int menorVet(int v[],int tam){
	int indicemenor, menor = INT_MAX;
	for(int i = 0; i < tam; i++){
		if(v[i] < menor){
			menor = v[i];
			indicemenor = i;
		}
	} 
	v[indicemenor] = INT_MAX;
	return menor;
}

void ordenaVetor(int v[], int vOrdenado[], short int tam){
	int i = 0, vaux[tam];
	copiaVetor(v, vaux, tam);
	while(i < tam){
		vOrdenado[i] = menorVet(vaux,tam);
		++i;
	}
}

void exibirVetor (int v[], short int tam){
	for(int i = 0; i < tam; ++i) printf("%d ", v[i]);
}

int main(){
	short int tam;
	
	printf("Insira o tamanho do vetor de inteiros a ser ordenado:\n");
	scanf("%d", &tam);
	int v[tam], vOrdenado[tam];
	
	printf("Insira os elementos do vetor, separado por espaços (respeitando o seu tamanho):\n");
	for(int i=0; i < tam; ++i){
		scanf("%d", &v[i]);
	} 
	printf("Vetor inserido: "); exibirVetor(v, tam);
	ordenaVetor(v, vOrdenado, tam);
	printf("\nVetor ordenado: "); exibirVetor(vOrdenado, tam);

	return 0;
}
