#include "header.h"

#define MIN_TROCAS 1500               // Número mínimo de trocas na hora de embaralhar.
#define MAX_TROCAS 3000 - MIN_TROCAS // Número máx de trocas na hora de embaralhar.

// Criar o baralho do jogo, ordenado como se tivesse lacrado.
// Será embaralhado pela função embaralhar().
void iniciarVet(Carta *v){
	int j = 0;
	// Ouros
	for(int i = 2; i <= 14; ++i){
		(v + j)->naipe = 0;
		(v + j++)->num = i;
	}
	// Copas
	for(int i = 2; i <= 14; ++i){
		(v + j)->naipe = 1;
		(v + j++)->num = i;
	}
	// Espadas
	for(int i = 2; i <= 14; ++i){
		(v + j)->naipe = 2;
		(v + j++)->num = i;
	}
	// Paus
	for(int i = 2; i <= 14; ++i){
		(v + j)->naipe = 3;
		(v + j++)->num = i;
	}
}

bool checaCoringa(Carta carta){ // Carta coringa = {0, -1}.
	return (carta.naipe == -1)? true: false;
}
	// O baralho principal é inicializado com uma única carta (o Coringa).
	// Um baralho com um único coringa sinaliza para a função embaralhar()
	// que o baralho está vazio, ou seja: O baralho deve ser inicializado
	// pegando o baralho inicializado por iniciarVet() embaralhando-o.


void embaralhar(Node **baralho_topo, Carta *aux){
	if(checaCoringa((*baralho_topo)->carta))
		desempilhar(baralho_topo); // Retirando coringa do topo e deixando o baralho vazio.
	else{
		// Passar baralho principal para v. aux para embaralhar:
		for(int i = 0; i < 52; ++i)
			aux[i] = desempilhar(baralho_topo);
	}
	
	// Embaralhar:
	for(int i = 0; i < MIN_TROCAS + rand()%MAX_TROCAS; ++i){
		int j1, j2;
		// Definição de índice aleatório:
		j1 = rand()%52; // Carta 1
		j2 = rand()%52; // Carta 2
		while(j1 == j2) j1 = rand()%52;
		
		// TROCA: 
		Carta temp = aux[j1];
		aux[j1] = aux[j2];
		aux[j2] = temp;
	}
	// Passar para baralho principal (pilha) de volta.
	for(int i = 0; i < 52; ++i){
		empilhar(baralho_topo, aux[i]);
	}
		
	return;
}

// Recolher a carta da mesa e dos jogadores, para a próxima rodada.
void recolherCartas(Node **baralho_topo, Mesa mesa, Jogador *jogador){
	// Recolher cartas dos jogadores.
	for(int i = 0; i < qtdJogadores; ++i){
		empilhar(baralho_topo, jogador[i].carta[0]);
		empilhar(baralho_topo, jogador[i].carta[1]);
	}
	// Recolher cartas viradas da mesa.
	for(int i = 0; i < cartasViradas; ++i)
		empilhar(baralho_topo, mesa.carta[i]);
	
	return;
}

// Desempilha do baralho as cartas, distribuindo-as
void distribuirCartas(Node **baralho_topo, Jogador *jogador){
	// Distribuir cartas do baralho circularmente e alternadamente entre jogadores.
	for(int i = 0; i < qtdJogadores; ++i){
		jogador[i].carta[0] = desempilhar(baralho_topo);
		printf("Distribuindo 1ª carta para o jogador %d\n", i+1);
		usleep(150000);
	}
	for(int i = 0; i < qtdJogadores; ++i){
		jogador[i].carta[1] = desempilhar(baralho_topo);
		printf("Distribuindo 2ª carta para o jogador %d\n", i+1);
		usleep(150000);
	} puts("");
	return;
}

void iniciaJogadores(Jogador *jogador){
	for(int i = 0; i < qtdJogadores; ++i){
		jogador[i].carta[0].naipe = -1;
		jogador[i].carta[1].naipe = -1;
		jogador[i].carta[0].num = 0;
		jogador[i].carta[1].num = 0;
		jogador[i].rank = 0;
	}
	return;
}
