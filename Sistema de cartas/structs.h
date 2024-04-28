
// Estruturas usadas..

typedef struct{
	int num;
	int naipe;
} Carta;
 
// Nó da pilha que vai conter as cartas do baralho principal do jogo.
typedef struct node{
	Carta carta;
	struct node *prox;
} Node;
typedef Node Pilha;

// Nick e as duas cartas que o jogador está (modalidade Texas Hold'em: 2 cartas na mão, 5 na mesa).
typedef struct{
	char nickname[26]; // Fícticio - Não utilizado nesse programa.
	Carta carta[2];
	int rank; // Classificação da mão atual (de 1 a 10), seguindo ordem em "lógica.c"
	int seq;  // Topo da sequência que ele tiver para exibição de resultado.
} Jogador;

// Struct da mesa e suas 5 cartas.
typedef struct{
	Carta carta[5];
} Mesa;

// Naipe: 1 - ouros | 2 - copas | 3 - espadas | 4 - paus.
// Números: 2, 3, 4, 5, 6, 7, 8, 9, 10.
// Figuras: Valete, Dama, Rei e Ás --> 11, 12, 13 e 14, respectivamente.
