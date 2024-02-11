/*
Questão 6) Considere o tipo tAluno definido abaixo:
*/
typedef struct {
	long int dre; // Número de identificação utilizada pela UFRJ.
	char nome[26], sobrenome[26]; // Obs: aumentei o tamanho do vetor, em relação ao que a questão pediu.
	short int idade;
	float peso, altura;
} tAluno;

/*
a) Escreva um programa que leia do teclado os dados de 3 alunos e grave esses dados em um arquivo
binário e também em um arquivo de texto.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 3

int main(void){
	tAluno aluno[TAM];
	
	// Leitura dos 3 alunos.
	for(int i = 0; i < TAM; ++i){
		printf("------- Aluno %d -------\n", i + 1);
		printf("Digite seu nome e sobrenome: "); scanf("%s %s", &aluno[i].nome, &aluno[i].sobrenome);
		printf("Digite seu DRE: "); scanf("%ld", &aluno[i].dre);
		printf("Digite sua idade: "); scanf("%hd", &aluno[i].idade);
		printf("Digite seu peso: "); scanf("%f", &aluno[i].peso);
		printf("Digite sua altura: "); scanf("%f", &aluno[i].altura);
		printf("\n");
	}
	FILE *arquivo; // Declaração do arquivo.
	
	// Escrita textual: 
	arquivo = fopen("dados.txt", "w");
	if(!arquivo) return -1; // Falha na abertura/criacao do arquivo.
	
	for(int i = 0; i < TAM; ++i){
		fprintf(arquivo, "Aluno %d: %s %s | DRE: %ld | Idade: %hd | Peso: %.1f Kg | Altura: %.2fm\n", i + 1, aluno[i].nome, aluno[i].sobrenome,
		aluno[i].dre, aluno[i].idade, aluno[i].peso, aluno[i].altura);
	} fclose(arquivo);
	printf("Dados salvos (texto)\n");
	
	// Escrita binária:
	arquivo = fopen("dados.dat", "wb");
	if(!arquivo) return -1; // Falha na abertura/criacao do arquivo.
	
	for(int i = 0; i < TAM; ++i) fwrite(&aluno[i], sizeof(tAluno), 1, arquivo);
	fclose(arquivo);
	printf("Dados salvos (binario)");
	
	return 0;
}
