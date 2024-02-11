/*
Questão 2) Escreva um programa que receba o nome de 2 arquivos: um binário e o outro de texto, e
então
a) leia 10 racionais do teclado;
b) armazene em ambos os arquivos os valores que foram lidos.
*/

#define TAM 30 // Tamanho máximo do nome do arquivo: 26 caracteres
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char str[TAM], str2[TAM]; // str = texto | str2 = binário
	FILE *arquivo;
	float n[10]; // Racionais
	
	// Armazenamento dos números racionais:
	printf("Digite 10 numeros racionais (separados por espaco):\n");
	for(int i = 0; i < 10; ++i) scanf("%f", &n[i]); getchar();
	// Nome do arquivo de texto:
	printf("Digite o nome do arquivo de texto: "); 
	scanf("%[^\n]", str); strcat(str, ".txt"); getchar();
	
	// Escrita em texto:
	if(!(arquivo = fopen(str, "w"))){
		printf("Erro na criacao/abertura do arquivo.");
		return -1;
	} 
	for(int i = 0; i < 10; ++i) fprintf(arquivo, "%.3f\n", n[i]);
	printf("Dados salvos (%s)", str);
	fclose(arquivo);
	
	// Escrita binária:
	printf("\nAgora digite o nome do arquivo binario: ");
	scanf("%[^\n]", str2); strcat(str2, ".dat");
	
	if(!(arquivo = fopen(str2, "wb"))){
		printf("Erro na criacao/abertura do arquivo.");
		return -1;
	}
	fwrite(n, sizeof(float), 10, arquivo);
 	printf("Dados salvos (%s)", str2);
	
	fclose(arquivo); 
	return 0;
}
