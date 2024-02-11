/*
Questão 6)
b) Escreva outro programa que ofereça a opção de ler um dos dois arquivos criados no exercício
anterior, leia o arquivo informado e então imprima os dados dos três alunos na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct {
	long int dre; // Número de identificação utilizada pela UFRJ.
	char nome[26], sobrenome[26]; // Obs: aumentei o tamanho do vetor, em relação ao que a questão pediu.
	short int idade;
	float peso, altura;
} tAluno;

int main(void){
	int n;
	
	printf("Digite:\n- 0 para ler o arquivo de texto\n- 1 para ler o arquivo binario\n\n--> ");
	scanf("%d", &n);
	
	FILE *arquivo;
	if(!n){ // Leitura de texto
		printf("\nLeitura do arquivo de texto:\n");
		char c;
		arquivo = fopen("dados.txt", "r");
		if(!arquivo){
			printf("Erro na abertura do arquivo."); return -1;
		} 
		// Vai imprimir exatamente como está no arquivo de texto.
		while( (c = fgetc(arquivo)) != EOF) putchar(c);
		fclose(arquivo); // Fechamento do arquivo.
	}
	else{ // Leitura binária (com nova formatação):
		
		printf("\nLeitura do arquivo binario:\n");
		arquivo = fopen("dados.dat", "rb");
		if(!arquivo){
			printf("Erro na abertura do arquivo."); return -1;
		}
		tAluno aluno[TAM]; // Vetor de tAluno.
		
		fread(aluno, sizeof(tAluno), TAM, arquivo); // Leitura dos três alunos, inseridos no vetor aluno.
		printf("Leitura realizada!\n\n");
		fclose(arquivo); // Fechamento do arquivo.
		
		for(int i = 0; i < TAM; ++i){ // Dados imprimidos na tela.
			printf("------- Aluno %d -------\n", i + 1);
			printf("Nome: %s %s\n", aluno[i].nome, aluno[i].sobrenome);
			printf("DRE: %ld\n", aluno[i].dre);
			printf("Idade: %hd anos\n", aluno[i].idade);
			printf("Peso: %.1f Kg\n", aluno[i].peso);
			printf("Altura: %.2fm", aluno[i].altura);
			printf("\n");
		}
	}
	return 0;
}
