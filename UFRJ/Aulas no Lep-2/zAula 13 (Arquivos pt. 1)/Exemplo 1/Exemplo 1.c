/*
O laboratório da aula 13 (Arquivos pt.1) caiu em um feriado, não houve exercícios até o momento dessa postagem
sendo assim, pratiquei os dois exemplos do PDF da Aula 13 fazendo do meu jeito.

Primeiro exemplo:
1) Escreva um programa em C que crie e inicialize três variáveis (uma
inteiro, outra double e outra cadeia de caracteres) e salve em um
arquivo texto os valores dessas variáveis.
*/

#include <stdio.h>
#define TAM 5

int main(){
	int n = 2023;
	double d = 3.14159265359; // Pi
	char c[TAM] = {'I','v','i','s','\0'};
	FILE *arquivo = fopen("Info.txt", "w"); // Abre o arquivo (tentativa)
	
	if(!arquivo){ // Checa abertura do arquivo, se é NULL, houve um problema ao abrir.
		printf("Não foi possível abrir/criar o arquivo.");
		return -1;
	}
	// Se chegou até aqui, o arquivo foi inicializado.
	int i = 0;
	
	fprintf(arquivo, "%d\n", n);
	fprintf(arquivo, "%lf\n", d);
	while(i < TAM) fprintf(arquivo, "%c", c[i++]);
	fclose(arquivo); // Fecha arquivo. 
		
	return 0;
}
