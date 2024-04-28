#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <locale.h>

#include "structs.h"

extern short int qtdJogadores;
extern short int cartasViradas;

// cartas.c

void iniciarVet(Carta *v);
bool checaCoringa(Carta carta);
void embaralhar(Node **baralho_topo, Carta *aux);
void recolherCartas(Node **baralho_topo, Mesa mesa, Jogador *jogador);
void distribuirCartas(Node **baralho_topo, Jogador *jogador);
void iniciaJogadores(Jogador *jogador);

// pilha.c

void inicializarBaralho(Node **topo);
void embaralhar(Node **baralho_topo, Carta *aux);
void empilhar(Node **topo, Carta carta);
Carta desempilhar(Node **topo);
Pilha *esvaziarPilha(Pilha *topo);

// debug.c

void exibirMesa(Mesa mesa);
void exibirCarta(Carta carta, bool exibirNaipe);
void exibirJogadores(Jogador *jogador);
void msg1(bool msg);
