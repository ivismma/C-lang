#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Questão muito interessante e bem completa. (5a 5b - P2 antiga 2023.1.pdf)

// Fazendo questão 5 de Prova antiga porém c/ ponteiros.
/*  Anotações:
- Uma carta vale, em pontos, exatamente o seu número se o seu naipe não for copas.
- Cartas de copas valem duas vezes o seu número.
- Não pode ser inserida na mesa carta cujo a pontuação já foi pontuada por outro jogador.
*/

// Defesas para inserção de valores não criada por exercício ser longo, inserir valores válidos.

typedef struct {
	char naipe; //'o','e','c' ou 'p'(ouros, espadas, copas ou paus, respec.).
	int numero; //Número da carta, entre 2 e 10.
	char jogador[100]; //Nome do jogador que a revelou;
} Carta;

void statusRodada(Carta* reveladas, int N);
void ordenaStruct(Carta* carta, int tam); // Bubble
void exibeVetor(Carta* carta, int tam);
int cartaPontos(Carta* carta);
bool checaCartas(Carta* carta, int tam, int pontos);
// bool addVetor(int *v, int tam, Carta carta);
// possivel(jaReveladas[], int t) <-- Função que o item b) pede.

int main(void){
	int n;
	printf("Digite quantidade de jogadores: ");
	scanf("%d", &n); getchar();
	Carta* reveladas = (Carta*) calloc(n, sizeof(Carta));
	// Leitura dos jogadores
	for(int i = 0; i < n;++i){
		bool ok; // FLAG - Se pontuação inserida for repetida, será falsa e continuará loop.
		printf("Jogador %d:\n", i+1);
		printf("Nome: "); scanf("%99[^\n]", reveladas[i].jogador);
		getchar();
		do{ // Enquanto inserir pontuação já pontuada antes, inserir outra carta.
			ok = true;
			printf("Naipe: "); scanf(" %c", &reveladas[i].naipe);
			printf("Numero: "); scanf("%d", &reveladas[i].numero);
			int pontos = cartaPontos(&reveladas[i]);
			if(!checaCartas(reveladas, i, pontos)){
				ok = false;
				printf("Pontuacao ja inserida, insira outra carta:\n");
			}
			getchar();
		} while(!ok);
		printf("---------------------\n");
	}
	// Ordenação dos jogadores em ordem de pontuação e vencedor.
	ordenaStruct(reveladas, n);
	statusRodada(reveladas, n);
	
	free(reveladas);
	return 0;
}

int cartaPontos(Carta* carta){ // Retorna quantos pontos o jogador fez com naipe e nª de sua carta.
	if(carta->naipe == 'c') // Copas = 2x Pontos
		return 2*carta->numero;
	return carta->numero;
}

bool checaCartas(Carta* p, int tam, int pontos){ // Parecido com a função q item (b) pede.
	for(int i = 0; i < tam;++i)
		if(cartaPontos(&p[i]) == pontos) return false;
	return true;
}

void statusRodada(Carta* reveladas, int N){ // Mostra resultado final da rodada e o vencedor.
	int maior = cartaPontos(&reveladas[0]),
	i_pessoa = 0, soma = 0;
	
	for(int i = 1; i < N;++i) // Loop p/ descobrir maior carta e quem a possui.
		if(cartaPontos(&reveladas[i]) > maior){
			maior = cartaPontos(&reveladas[i]);
			i_pessoa = i; // Armazena indice da pessoa que possui maior pontuação.
		}
	for(int i = N-1; i >= 0;--i){ // Exibição dos jogadores em ordem decrescente de pontuação
		int pts = cartaPontos(&reveladas[i]);
		printf("Jogador %s: %d pontos.\n", reveladas[i].jogador, pts);
	}
	for(int i = 0; i < N;++i) // Exibição do vencedor e quanto pontuou.
		soma += cartaPontos(&reveladas[i]);
	printf("O jogador %s ganhou a rodada e levou da mesa o total de %d pontos.", 
	reveladas[i_pessoa].jogador, soma);
}
// Ordenação cresc. de struct com base na pontuação das cartas dos jogadores.
void ordenaStruct(Carta* p, int tam){
	bool ordenado = false;
	int fim = tam-1;
	while(!ordenado){
		ordenado = true;
		for(int i = 0; i <fim;++i){
			if(cartaPontos(&p[i]) > cartaPontos(&p[i+1])){ 
				Carta aux = p[i];
				p[i] = p[i+1];
				p[i+1] = aux;
				ordenado = false;
			}
		}
		--fim;
	}
}
// Função do item (b) Obs: Não utilizei.
/*
int possivel(Carta intencao, Carta reveladas[], int t){
	int ini = 0, meio, fim = t-1;
	pontos = cartaPontos(&intencao);
	// Busca binária (vetor está crescente)
	while (ini <= fim) { //Busca binária
		meio = (ini + fim) / 2;
		if (cartaPontos(reveladas[meio]) == pontos) 
			return 0; // Carta já revelada.
		if (cartaPontos(reveladas[meio]) < pontos) ini = meio + 1;
		else fim = meio - 1;
	}
	return 1; // Pontuação disponível.
}




Outra maneira de salvar pontuações já reveladas (criar vetor a parte):
bool addVetor(int *v, int tam, Carta carta){
	static int cont = 0;
	for(int i = 0; i < cont;++i)
		if(v[cont] == carta->numero)
			return false; // Pontuação equivalente já revelada.
	*(v+cont++) = carta.numero;
	return true;
}*/
