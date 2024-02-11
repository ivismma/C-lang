/*
Crie um tipo de dados para representar uma Pessoa, mas agora, além dos campos idade (inteiro)
e peso (float), o campo nome (string) deverá ser um ponteiro de caractere.
Implemente a função main, onde um vetor de Pessoas com o total de posições que o usuário
informar (máximo de 50) será alocado dinamicamente via ponteiro. O usuário deverá então preencher o
vetor.
Crie uma função para ordenar esse vetor em ordem decrescente de idade e, de volta na main(),
imprima na tela o vetor já ordenado.
Agora, após a ordenação, permita que o usuário insira uma idade na main(). Crie uma função que
receba de entrada o vetor já ordenado e a idade informada, e então realize uma busca binária no vetor de
Pessoas, retornando o índice no vetor onde a pessoa possui a referida idade, ou -1 se ninguém for
encontrado. No caso de duas ou mais pessoas com idades iguais, basta retornar um único índice. Na
main, imprima o nome dessa pessoa.
CUIDADO: o vetor está em ordem decrescente. Sua busca binária leva isso em conta!
*/

#define TAM 50
#define TAM_STR 51
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Vou utilizar leitura por arquivos para praticar Arquivos.

typedef struct{
	char *nome;
	float peso;
	int idade;
} tPessoa;

bool checaArquivo(FILE *arquivo){
	if(arquivo == NULL){
		printf("Não foi possível abrir o arquivo.");
		return false;
	}
	return true;
}

void ordenaDec(int idade[]){ // Bubble Sort adaptado para ordem decrescente
	int i, aux, fim = TAM;
		bool ordenado; 
		while(!ordenado){
			ordenado = true;
			for(i = 0;i < fim-1;++i){
				if(idade[i] < idade[i+1]){
					aux = idade[i];
					idade[i] = idade[i+1];
					idade[i+1] = aux;
					ordenado = false;
				}
			}
			--fim;
		}
}

int buscaBinariaDec(int idade[], int busca){
	int esq, meio, dir;
    esq = 0;
    dir = TAM - 1;
    while (esq <= dir) {
        meio = (esq + dir) / 2;
        if (idade[meio] == busca) 
            return meio; 
        if (busca > idade[meio])
            dir = meio - 1; 
        else
            esq = meio + 1; 
    }
	return -1; // Não encontrado.
}

int main(){
	tPessoa Pessoa[TAM];
	char l; // letra.
	
	for(int i = 0; i < TAM; ++i) // Aloca dinamicamente o nome do vetor de Pessoa.
	Pessoa[i].nome = (char*) malloc(TAM_STR * sizeof(char));
	
	// Declaração e verificação do arquivo:
	FILE *arquivo;
	arquivo = fopen("Pessoas.txt", "r");
	if(!checaArquivo(arquivo)) return -1;
	
	// Leitura do arquivo
	for(int i = 0; i < TAM; ++i){ // Inicializa leitura, separada por espaços de nome, idade e peso
		int j = 0;
		while(j < TAM_STR){
			fscanf(arquivo, "%c", &l);
			if(l == ' ' || l == '\n') break;
			Pessoa[i].nome[j] = l;
			++j;
		}
		Pessoa[i].nome[j] = '\0';
		fscanf(arquivo, "%d", &Pessoa[i].idade);
		fscanf(arquivo, "%f", &Pessoa[i].peso);
		fgetc(arquivo);
	} 
	fclose(arquivo); // Fechamento do arquivo.
	
	// Prosseguindo para a ordenação decrescente
	int idade[TAM]; // Criação do vetor idade que recebe as idades da struct para ordenação decrescente
	for(int i = 0; i < TAM;++i) idade[i] = Pessoa[i].idade;
	ordenaDec(idade);
	
	// Busca binária da busca da idade
	int busca;
	printf("Digite a idade a ser procurada: ");
	scanf("%d", &busca);
	printf("Nome da pessoa com %d anos de idade: %s", busca, Pessoa[buscaBinariaDec(idade,busca)].nome);
	// Será exibido -1 caso a idade não seja encontrada.
	
	// Liberação de memória dos nomes da struct (Pessoa[].nome)
	for(int i = 0; i < TAM; ++i) free(Pessoa[i].nome);
	
	return 0;
}
