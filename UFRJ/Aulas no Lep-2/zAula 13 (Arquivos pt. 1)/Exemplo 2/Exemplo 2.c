/*
O laboratório da aula 13 (Arquivos pt.1) caiu em um feriado, não houve exercícios até o momento dessa postagem
sendo assim, pratiquei os dois exemplos do PDF da Aula 13 fazendo do meu jeito.

Segundo exemplo:
2) Agora escreva outro programa que abra e leia o conteúdo do arquivo de
texto gerado e imprima na tela os valores lidos.
*/

#include <stdio.h>
#define TAM 5

int main(){
	FILE *arquivo = fopen("Info.txt", "r"); // Abre o arquivo para leitura (tentativa)
	
	if(!arquivo){ // Checa abertura do arquivo, se é NULL, houve um problema ao abrir.
		printf("Não foi possível abrir/criar o arquivo.");
		return -1;
	}
	// Se chegou até aqui, o arquivo foi inicializado.
	int i = 0;
	
	int n; double d; char c[TAM];
	fscanf(arquivo, "%d\n%lf\n%s", &n, &d, c);
	i = 0;
	
	// Imprime
	printf("%d\n%lf\n%s", n, d, c);
	
	
	fclose(arquivo); // Fecha arquivo. 
		
	return 0;
}
