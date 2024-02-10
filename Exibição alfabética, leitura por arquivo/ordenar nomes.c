#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#define N_PESSOAS 18 // Existem 20 nomes no arquivo.
#define N_CHAR 30+1 // Nº máx. de caracteres no nome.

// Exibição de lista de nomes em ordem alfabética, leitura em arquivo textual.

typedef struct {
    char nome[N_CHAR];
    int codigo;
} Pessoa;

void exibirPessoa(Pessoa pessoa);
bool inserirNomes(Pessoa *pessoa, int *tam);
void exibirNomesOrdenados(Pessoa *original, int tam);

int main(void){
    setlocale(LC_ALL, "Portuguese");
	int tam = N_PESSOAS;
	
	Pessoa *pessoa = (Pessoa *) malloc(tam * sizeof(Pessoa));
	if(pessoa == NULL){
		printf("Falha na alocação de memória.");
		return -1;
	}
	
    if(!inserirNomes(pessoa, &tam)){
		printf("Falha na abertura ou localização do arquivo \"pessoas.txt\".");
		return -2;
	}
	exibirNomesOrdenados(pessoa, tam);

	free(pessoa);
	printf("\n"); system("pause");
    return 0;
}

void exibirPessoa(Pessoa pessoa){
    printf("%d      %s\n", pessoa.codigo, pessoa.nome);
}


// O objetivo dessa função é somente imprimir ordenadamente, então é criado
// uma struct auxiliar para ser ordenada sem mexer no vetor dinâmico original.

void exibirNomesOrdenados(Pessoa *original, int tam){
    bool ordenado;
    int fim = tam-1;

	Pessoa pessoa[tam]; // Auxiliar
	for(int i = 0; i < tam; ++i) pessoa[i] = original[i];
	
	// Ordenação:        (Bubble sort c/ FLAG.)
    do{ 
        ordenado = true;
        for(int i = 0; i < fim; ++i) {  //strcmp não case-sensitive...
            if(strcasecmp(pessoa[i].nome, pessoa[i+1].nome) > 0){ 
                Pessoa aux = pessoa[i];
                pessoa[i] = pessoa[i+1];
                pessoa[i+1] = aux;
                ordenado = false;
            }
        }
        --fim; 
    } while(!ordenado);
    
	// Exibição da lista:
	printf("Lista de nomes em ordem alfabética:\n");
    printf("Código    Pessoa\n---------------------\n");
    for(int i = 0; i < tam; ++i)
        exibirPessoa(pessoa[i]);
        
    printf("Nomes lidos: %d", tam);
    return;
}

bool inserirNomes(Pessoa *pessoa, int *tam){
	FILE *arq;
	if( !(arq = fopen("pessoas.txt", "r")) )
		return false;
	
	char c;
	int i = 0;
	
	while( (c = fgetc(arq)) != '{');
	fgetc(arq); // Entra na lista.
	while(i < *tam && (c = fgetc(arq)) != '}'){
		char nome[N_CHAR];
		nome[0] = c; // Já lido no while.
		fscanf(arq, "%[^\n]", &nome[1]); // Escrita a partir de nome[1].
		strcpy(pessoa[i].nome, nome);
		pessoa[i++].codigo = 1000+i;
		fgetc(arq); // Pula p/ linha seguinte.
	}
	if(i < *tam){ // EOF antes de achar tam nomes, significa que N_PESSOAS é maior que a qtd de nomes no arquivo.
		*tam = i;
		printf("Aviso - N_PESSOAS maior que quantidade de nomes no arquivo.\n\n");
	} 
	
	fclose(arq);
	return true; // Não ocorreu nenhum problema.
}
