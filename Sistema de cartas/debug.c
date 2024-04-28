#include "header.h"

// Funções para debug:

void exibirMesa(Mesa mesa){
	int i;
	printf("Mesa:  ");
	for(i = 0; i < cartasViradas-1; ++i){
		exibirCarta(mesa.carta[i], true);
		printf(" | ");
	}
	exibirCarta(mesa.carta[i], true);
	puts("\n");
}

void exibirCarta(Carta carta, bool exibirNaipe){
	if(carta.naipe == '0' || carta.num == 0){
		printf("CORINGA! ");
		return;
	}
	
	if(carta.num <= 10) // Se não for figura..
		printf("%d", carta.num);
	else
		switch(carta.num){ // Figura:
			case 11:
				printf("Valete");
				break;
			case 12:
				printf("Dama");
				break;
			case 13:
				printf("Rei");
				break;
			default:
				printf("Ás");
				break;
		}
	if(!exibirNaipe) return;
	
	printf(" de ");
	switch(carta.naipe){
		case 0:
			printf("Ouros");
			break;
		case 1:
			printf("Copas");
			break;
		case 2:
			printf("Espadas");
			break;
		default:
			printf("Paus");
			break;
	}
	
	return;
}

void exibirJogadores(Jogador *jogador){
	for(int i = 0; i < qtdJogadores; ++i){
		printf("Jogador %d: ", i+1);
		exibirCarta(jogador[i].carta[0], true);
		printf(" | ");
		exibirCarta(jogador[i].carta[1], true);
		puts("");
	}
}

void msg1(bool msg){
	if(msg) printf("Embaralhando"); 
	else    printf("Recolhendo"); 
	usleep(400000); printf(".");
	usleep(400000); printf("."); 
	usleep(400000); printf(".\n"); usleep(400000);
}
