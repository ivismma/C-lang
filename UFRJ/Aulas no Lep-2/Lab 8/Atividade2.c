/*Atividade 2: Uma operação muito comum em computação é a intercalação de dois vetores que já
estão ordenados. Considere um vetor A de tamanho N e outro B de tamanho M. O vetor resultante
C é construído a partir dos dois vetores originais e terá tamanho N + M.
Tarefa:
1) Escreva uma função que receba como entrada um par de vetores já ordenados e seus
respectivos tamanhos, os intercale formando um novo vetor ordenado, e imprima o
resultado.

2) Escreva um programa para testar sua função. Use o exemplo mostrado abaixo e outros que
você mesmo pode criar.
Obs.: explore o fato de que os vetores de entrada já estão ordenados. Simplificará a
implementação da solução.*/

#include <stdio.h>
#include <stdlib.h>

int *ordenaVetoresOrdenados(int *v1, int *v2, int tam1, int tam2);
void exibirVetor (int *v, int tam);

int main(){
	int i;
	int *pV1, *pV2, *pV3; // pV1 - Vetor 1 | pV2 - Vetor 2 | pV3 -> Vetores juntados e ordenados.
	int tam[2]; // tam[0] - Tamanho Vetor 1 | tam[1] - Tamanho Vetor 2
	
	printf("Insira o tamanho do vetor 1 e 2, respectivamente (separado por espaco):\n");
	for(i=0;i < 2;++i) scanf("%d", &tam[i]);
	int tamTotal = tam[0]+tam[1];
	
	pV1 = (int*) calloc(tam[0], sizeof(int));
	pV2 = (int*) calloc(tam[1], sizeof(int));
	
	printf("Obs: Inserir elementos ordenados\n");
	printf("Elementos do vetor 1o vetor ordenado, separado por espacos:\n");
	for(i=0; i < tam[0]; ++i) scanf("%d", &pV1[i]);

	printf("Elementos do vetor 1o vetor ordenado, separado por espacos:\n");
	for(i=0; i < tam[1]; ++i) scanf("%d", &pV2[i]);
	
	pV3 = ordenaVetoresOrdenados(pV1, pV2, tam[0], tam[1]);
	free(pV1);
	free(pV2);
	exibirVetor(pV3,tamTotal);
	free(pV3);
	
	return 0;
}

int *ordenaVetoresOrdenados(int *v1, int *v2, int tam1, int tam2){
	int i = 0, j = 0, k = 0;
	int *v3 = (int*) calloc(tam1+tam2, sizeof(int));
	// Vetor resultado alocado.
	
	// Intercalação de vetores.
	while(i < tam1 && j < tam2)
		if(v1[i] < v2[j])
			v3[k++] = v1[i++];
		else
			v3[k++] = v2[j++];
			
	// Se uma lista for maior que a outra, vê qual é preenche o resto do vetor ordenado:
	if(i == tam1)
		while(j < tam2) v3[k++] = v2[j++]; 
	else if(j == tam2)
		while(i < tam1) v3[k++] = v2[j++]; 
	
	return v3; // Retorna o ponteiro para o vetor ordenado alocado.
}

void exibirVetor (int *v, int tam){
	printf("\n");
	for(int i = 0; i < tam; ++i) printf("%d ", v[i]);
}
