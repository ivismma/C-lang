
// Exibi��o ordenada com crit�rio de desempate

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TAM_STR 25 // nome de at� 25char...

typedef struct{
	char nome[TAM_STR];
	int idade;           // idade
	int codigo;          // c�digo qualquer (matricula/cpf/etc)
} Pessoa; // Struct pessoa.

// 1 - Nome, 2 - Idade, 3 - C�digo
const int ORDEM[3] = {1,2,3}; // Ordem de crit�rios
//                   2, 1, 3 seria, por ex: Idade -> Nome -> Codigo
// Obs: Nunca haver� empate se o 1� crit�rio for 3 pq c�digos n�o repetem.

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

// Ordena��o usada: Insertion 
// (alterado com crit�rio de desempates).
void ordena(Pessoa *v, int tam){
	for(int i = 0; i < tam; ++i){
		for(int j = i+1; j < tam; ++j){
			int criterioAtual = 0; // pra cada compara��o come�a pelo zero (1� crit�rio)
			REAVALIA: // Checa o pr�ximo crit�rio se necess�rio desempate.
			switch(ORDEM[criterioAtual]){
				int cmpValor; // valor de compara��o
				case 1: // Nome
					cmpValor = strcmp((v+i)->nome, (v+j)->nome);
					if(cmpValor > 0){ // Nome alfabeticamente maior
						swap((v+i),(v+j));
						break;
					}
					else if(cmpValor == 0){ // S�o iguais, n�o d� break (e continua no switch-case).
						++criterioAtual;
						goto REAVALIA;
					}
					else break; // � menor, continua no loop.
				case 2: // Idade
					cmpValor = (v+i)->idade - (v+j)->idade;
					if(cmpValor > 0){ // � maior
						swap((v+i),(v+j));
						break;
					}
					else if(cmpValor == 0){ // empate
						++criterioAtual;
						goto REAVALIA;
					}
					else break; // continua no loop.
				case 3: // C�digo (n�o � poss�vel igualdade).
					cmpValor = (v+i)->codigo - (v+j)->codigo;
					if(cmpValor > 0) // 1� � maior
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
