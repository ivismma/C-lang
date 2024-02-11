/*Questão 5) Assim como fizemos no Laboratório 9, crie um tipo de dados para representar uma
Pessoa, mas agora, além dos campos idade (inteiro) e peso (float), inclua também o campo nome
(string). Implemente a função main, onde um vetor de Pessoas (máximo de 50) deverá ser preenchido
pelo usuário. Ordene esse vetor em ordem decrescente de idade e imprima o vetor ordenado na tela.
Crie essa lógica de ordenação na própria main.
- Agora, modifique o programa como segue: após a ordenação do vetor, permita que o
usuário insira uma idade. A partir daí, crie uma função que receba de entrada o vetor ordenado e a
idade informada, e então realize uma busca binária no vetor de Pessoas, retornando o índice no vetor
onde a pessoa possui a referida idade, ou -1 se ninguém for encontrado. No caso de duas ou mais
pessoas com idades iguais, basta retornar um único índice. Na main, imprima o nome dessa pessoa.
CUIDADO: o vetor está em ordem decrescente. Sua busca binária leva isso em conta!*/

#include <stdio.h>
#include <stdbool.h>
#define TAM 50
#define FALSE 0
#define TRUE 1

typedef struct{
	char nome[50+1];
	float peso;
	int idade;
} TPessoa;

void preencheVetor(TPessoa pessoa[], int v[]){
	for (int i = 0; i < TAM; i++)
		v[i] = pessoa[i].idade;
} 

void exibirVetor(int v[]){
	int i = 0;
	while(i < TAM)
		printf("%d ", v[i++]);
} 

// Recebe um vetor v1 e o copia em v2.
// Ambos devem ter o mesmo tamanho.
int copiaVetor(int v1[], int v2[]){
	int i = 0;
	for(int i = 0; i < TAM;++i) v2[i] = v1[i];
	return TRUE;
}

int main(){
	TPessoa pessoa[TAM];
	int idade[TAM], idadeDec[TAM];
	
	for(int i = 0;i < TAM;i++){
		printf("Pessoa %d - Insira separado por espaço o nome, a idade e o peso, respectivamente: ", i+1);
		scanf("%s", pessoa[i].nome);
		scanf("%d %d", &pessoa[i].idade, &pessoa[i].peso);
	} preencheVetor(pessoa, idade);
	
	printf("\nIdades inseridas:\n");
	exibirVetor(idade);
	
	/*Ordene esse vetor em ordem decrescente de idade e imprima o vetor ordenado na tela.
	Crie essa lógica de ordenação na própria main.*/
	
	// Usa vetor ordenado decrescentemente a parte para preservar os dados da idade.
	copiaVetor(idade, idadeDec);
	
	// Bubble Sort p/ ordem decrescente | escopo criado para que a variável i, aux, fim e ordenado deixe de ocupar memória depois.
	{
		int i, aux, fim = TAM;
		bool ordenado; // o bool ordenado é uma flag.
		while(!ordenado){
			ordenado = true;
			for(i = 0;i < fim-1;++i){
				if(idadeDec[i] < idadeDec[i+1]){
					aux = idadeDec[i];
					idadeDec[i] = idadeDec[i+1];
					idadeDec[i+1] = aux;
					ordenado = false;
				}
			}
			--fim;
		}
	}
	
	printf("\nIdades em ordem decrescente:\n");
	exibirVetor(idadeDec);
	
	// Parte 2 do exercício. Modificando...
	
	int busca, resultado = -1; // O resultado será iniciado como -1, se não for encontrada a idade, o valor já está pré definido.
	printf("\nInsira uma idade para obter o indice (será retornado -1 caso ela não seja encontrada): ");
	scanf("%d", &busca);
	// Busca binária decrescente:
	{
		int esq, meio, dir;
	    esq = 0;
	    dir = TAM - 1;
	    while (esq <= dir) {
	        meio = (esq + dir) / 2;
	        if (idadeDec[meio] == busca) {
	            resultado = meio; 
	            break; 
	        }
	        if (busca > idadeDec[meio]) // Basta inverter a esquerda com direita no caso de decrescente.
	            dir = meio - 1; 
	        else
	            esq = meio + 1; 
	    }
	}
	// Vale lembrar que por se tratar de uma busca binária, pode haver mais de uma pessoa com mesma idade, então
	// ele retornará o primeiro encontrado.
	
	if(resultado == -1){
		printf("Idade não encontrada.");
		return -1;
	} 
	printf("\nIndice da idade inserida: %d", resultado);
	printf("\nNome da pessoa: %s", pessoa[resultado].nome);
	return 0;
}
