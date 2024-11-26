
// Exibição ordenada com critério de desempate

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TAM_STR 25 // nome de até 25char...

typedef struct{
	char nome[TAM_STR];
	int idade;           // idade
	int codigo;          // código qualquer (matricula/cpf/etc)
} Pessoa; // Struct pessoa.

// 1 - Nome, 2 - Idade, 3 - Código
const int ORDEM[3] = {1,2,3}; // Ordem de critérios
//                   2, 1, 3 seria, por ex: Idade -> Nome -> Codigo
// Obs: Nunca haverá empate se o 1º critério for 3 pq códigos não repetem.

void ordena(Pessoa *v, int tam);
void swap(Pessoa *a, Pessoa *b);
void exibe(Pessoa *v, int tam);
void exibeOrdem();

int main(void){
	
	// Vetor p/ testes.
	Pessoa vet[] = { 
	{"Ronald", 28, 0}, {"Anderson", 18, 1},{"Bernardo", 12, 2},
	{"Andre", 30, 3}, {"Ronald", 25, 4},{"Bernardo", 13, 5},
	{"Giovanna", 30, 6}, {"Mario", 18, 7},{"Claudson", 55, 8},
	{"Roberto", 30, 9}, {"Ronald", 28, 10},{"Joao", 11, 11},
	{"Roberto", 28, 12}, {"Anderson", 18, 13},{"Bernardo", 14, 14},
	{"Julia", 30, 15}, {"Pedro", 18, 16},{"Ronald", 28, 17},
	{"Roberta", 45, 18}, {"Xavier", 42, 19},{"Ronaldo", 35, 20}
	};
	int tam = sizeof(vet)/sizeof(vet[0]);
	
	ordena(vet, tam);
	exibe(vet, tam);
	
	printf("Criterios usados: ");
	exibeOrdem();
	
	return 0;
}

void swap(Pessoa *a, Pessoa *b){
	Pessoa aux = *a;
	*a = *b;
	*b = aux;
}

// Ordenação usada: Insertion 
// (alterado com critério de desempates).
void ordena(Pessoa *v, int tam){
	for(int i = 0; i < tam; ++i){
		for(int j = i+1; j < tam; ++j){
			int criterioAtual = 0; // pra cada comparação começa pelo zero (1º critério)
			REAVALIA: // Checa o próximo critério se necessário desempate.
			switch(ORDEM[criterioAtual]){
				int cmpValor; // valor de comparação
				case 1: // Nome
					cmpValor = strcmp((v+i)->nome, (v+j)->nome);
					if(cmpValor > 0){ // Nome alfabeticamente maior
						swap((v+i),(v+j));
						break;
					}
					else if(cmpValor == 0){ // São iguais, não dá break (e continua no switch-case).
						++criterioAtual;
						goto REAVALIA;
					}
					else break; // é menor, continua no loop.
				case 2: // Idade
					cmpValor = (v+i)->idade - (v+j)->idade;
					if(cmpValor > 0){ // é maior
						swap((v+i),(v+j));
						break;
					}
					else if(cmpValor == 0){ // empate
						++criterioAtual;
						goto REAVALIA;
					}
					else break; // continua no loop.
				case 3: // Código (não é possível igualdade).
					cmpValor = (v+i)->codigo - (v+j)->codigo;
					if(cmpValor > 0) // 1º é maior
						swap((v+i),(v+j));
					break;
			}
		}
	}
}

void exibe(Pessoa *v, int tam){
	printf("Lista com %d pessoas:\n\n", tam);
	printf("Codigo\t\t Nome   \tIdade\n");
	for(int i = 0; i < tam; ++i)
		printf("000%d \t\t %s | %d anos\n", (v+i)->codigo, (v+i)->nome, (v+i)->idade);
	puts("");
}

void exibeOrdem(){
	int i;
	for(i = 0; i < sizeof(ORDEM)/sizeof(ORDEM[0])-1; ++i){
		switch(ORDEM[i]){
		case 1:
			printf("Nome -> "); break;
		case 2:
			printf("Idade -> "); break;
		default:
			printf("Codigo -> ");
		}
	}
	switch(ORDEM[i]){
		case 1:
			printf("Nome\n"); break;
		case 2:
			printf("Idade\n"); break;
		default:
			printf("Codigo\n");
		}
}
