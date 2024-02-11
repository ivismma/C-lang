/*
Atividade 2: Os alunos de uma turma fizeram duas provas. Escreva um programa que leia do teclado
uma única string contendo o nome completo e as duas notas de um aluno, separados por espaço,
calcule a média aritmética dessas duas notas e imprima em seguida o nome do aluno e a média
obtida. Use a função ‘sscanf’, vista em nossa última aula.
Permita que o programa aceite novas entradas até que uma entrada inválida seja fornecida.
*/

/* Maneira de fazer antes de eu ver que o exercício pedia o uso de sscanf.

// Essa função cria a string nome que contém o nome completo e
// retorna o índice seguinte onde termina o nome do aluno.

int obtemNome(char dadosAluno[], char nome[]){
	int i = 0;
	
	while(dadosAluno[i] >= 'A' && dadosAluno[i] <= 'z')
	nome[i++] = dadosAluno[i];
	
	nome[i] = '\0';
	return i;
}
*/

#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificaInput(char v[], int n){
	int letras = 0, numeros = 0;
	for(int i = 0; i < n; ++i){
		// Verifica se possui uma letra, ou espaço
		if( ((v[i] >= 'A' && v[i] <= 'Z') || (v[i] >= 'a' && v[i] <= 'z') || v[i] == ' ' ))
			++letras;
		else if(v[i] >= '0' && v[i] <= '9') // Verifica se é um número.
			++numeros;
	}
	if(!letras || !numeros) 
		return FALSE; // Concluindo... Se não possui letras e/ou não possui números, é inválida.
	return TRUE; // Caso nenhum erro tenha sido encontrado, a string é válida.
}
// Decidi utilizar ponteiros.
int main(){ 
	char *nome, dadosAluno[81]; // Dados Aluno será o que contém o nome completo e duas notas.
	float n1, n2, media;
	nome = (char *) malloc(76 * sizeof(char)); // Nome de até 75 caracteres.
	
	while(1){ // Loop até que uma entrada inválida seja inserida.
		printf("Insira o nome completo do aluno e suas duas notas (separados por espaço):\n");
		gets(dadosAluno);
		
		// "Permita que o programa aceite novas entradas até que uma entrada inválida seja fornecida."
		if( !verificaInput(dadosAluno, strlen(dadosAluno)) ){
			printf("O programa foi encerrado pois o usuário inseriu uma entrada inválida.");
			break;
		} 
		sscanf(dadosAluno, "%[^0-9]", nome);
		nome = (char *) realloc(nome, strlen(nome)+1); // Realocação para otimização de uso de memória.
		sscanf(&dadosAluno[strlen(nome)], "%f %f", &n1, &n2);
		media = (n1+n2)/2;
		
		printf("\nNome do aluno: %s\nMédia aritmética: %.2f\n\n", nome, media);
	}
	
	return 0;
}
