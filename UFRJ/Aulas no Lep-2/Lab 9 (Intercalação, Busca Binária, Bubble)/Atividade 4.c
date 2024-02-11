/*
Atividade 4:
Crie um novo tipo de dados para representar uma Pessoa com os campos idade e peso.
Agora, implemente uma função que, dado um vetor de Pessoas, ordene esse vetor em
ordem decrescente de idade e imprima o vetor ordenado na tela.
Finalmente, implemente a função main, onde um vetor de Pessoas (máximo de 50) deverá
ser preenchido pelo usuário e em seguida ordenado (chamando a função definida
anteriormente).
*/

#include <stdio.h>
#define TAM 50
#define FALSE 0
#define TRUE 1

typedef struct{
	float peso;
	int idade;
} TPessoa;

void ordenaVetor(int v[]){ // Algoritmo de ordenação: Bubble sort
	const int FALSO = FALSE, VERDADEIRO = TRUE;
	int ordenado = FALSO; //Flag (indicador)
	int fim = TAM; //n é o tamanho do vetor.
		while (!ordenado) { 
		ordenado = VERDADEIRO;
		for (int i = 0; i < fim - 1; i++) {
			if (v[i] > v[i+1]) {
			
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				ordenado = FALSO;
			}
		}
		fim--;
		}
}

void preencheVetor(TPessoa pessoa[], int v[]){
	for (int i = 0; i < TAM; i++)
		v[i] = pessoa[i].idade;
} 

void exibirVetor(int v[]){
	int i = 0;
	while(i < TAM)
		printf("%d ", v[i++]);
} 

void ordenaIdadeDec(int v[], int vOrdenado[]){
	for(int i = 0, j = TAM-1; i < TAM; i++, j--){
		vOrdenado[i] = v[j];
	} return;
}

int main(){
	TPessoa pessoa[TAM];
	int idade[TAM], idadeDec[TAM];
	
	for(int i = 0;i < TAM;i++){
		printf("Pessoa %d - Insira separado por espaço o idade e peso, respectivamente: ", i+1);
		scanf("%d %d", &pessoa[i].idade, &pessoa[i].peso);
	} preencheVetor(pessoa, idade);
	
	printf("\nIdades inseridas:\n");
	exibirVetor(idade);
	
	ordenaVetor(idade);
	ordenaIdadeDec(idade, idadeDec);
	printf("\nIdades em ordem decrescente:\n");
	exibirVetor(idadeDec);
	return 0;
}
