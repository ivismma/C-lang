/*
Questão 3) Escreva um programa que receba o nome de um dos arquivos gerados no exercício
anterior (os quais agora já armazenam 10 números em ponto flutuante). O programa deverá então ler
os valores desse arquivo e imprimir na tela o maior número encontrado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 30 // Tamanho máximo do nome do arquivo: 26 caracteres

// Para leitura de dados, vou utilizar o arquivo binário (mais adequado).

// Retorna o maior número de um vetor float.
float vetMaior(float v[]){
	float maior = v[0];
	for(int i = 1;i < 10; ++i) if(v[i] > maior) maior = v[i];
	return maior;
}

int main(){
	char str[TAM];
	FILE *arquivo;
	float n[10];
	
	// Nome do arquivo binário que foi digitado na Q2 (sem incluir a extensão .dat):
	printf("Digite o nome do arquivo binário que foi digitado na Q2: "); 
	scanf("%[^\n]", str); strcat(str, ".dat"); getchar();
	if(!(arquivo = fopen(str, "rb"))){
		printf("Erro na abertura do arquivo - Nome invalido ou acesso negado.");
		return -1;
	}
	// Leitura dos dados binários
	fread(n, sizeof(float), 10, arquivo);
	// Impressão do maior número: 
	float maior = vetMaior(n);
	printf("Maior numero contido no arquivo \"%s\": %f", str, maior);
	
	fclose(arquivo);
	return 0;
}
