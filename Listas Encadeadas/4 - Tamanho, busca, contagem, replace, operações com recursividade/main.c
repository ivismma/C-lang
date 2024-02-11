#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Biblioteca p/ valor booleano.

// Aula 4:
// Tamanho, busca, contagem, replace
// Implementações com recursividade.

typedef struct node{
	int valor;
	struct node *prox;
} Node;

void exibirLista(Node *topo);
Node *inserirTopo(Node *topo, int novoValor);
Node *inserirInicio(Node *topo, int novoValor);
int tamanhoLista(Node *topo);
int tamanhoListaRec(Node *topo); // Função recursiva do Tamanho da lista.
bool verifica_Lista(Node *topo, int busca);
int contagem_Lista(Node *topo, int busca);	
void trocar_Lista(Node *topo, int busca, int troca); // busca: antes | troca: depois

int main(){
	Node *lista1_topo = NULL; // Declaração de lista vazia.
	int busca;
	
	lista1_topo = inserirTopo(lista1_topo, 5);
	lista1_topo = inserirTopo(lista1_topo, 4);
	lista1_topo = inserirTopo(lista1_topo, 3);
	lista1_topo = inserirTopo(lista1_topo, 3);
	lista1_topo = inserirTopo(lista1_topo, 3);
	lista1_topo = inserirTopo(lista1_topo, 1);
	
	/*
	printf("Digite um número de 1 a 5 para obter as ocorrencias na lista: ");
	scanf("%d", &busca);
	printf("Quantidade de %d's na lista encadeada: %d.\n\n", busca, contagem_Lista(lista1_topo, busca));
	exibirLista(lista1_topo);
	*/
	printf("Lista antes da troca: \n"); exibirLista(lista1_topo);
	printf("Digite um numero CONTIDO na lista seguido por espaco do numero a substitui-lo: ");
	scanf("%d", &busca);
	if(!verifica_Lista(lista1_topo, busca)){
		printf("O numero inserido nao esta na lista encadeada.");
		return -1;
	}
	int n;
	scanf("%d", &n);
	trocar_Lista(lista1_topo, busca, n);
	printf("\nLista depois da troca: \n"); exibirLista(lista1_topo);
	
	return 0;
}

/////////////////////////////////////////
////  NOVAS FUNÇÕES E RECURSIVIDADE  ////

int tamanhoLista(Node *topo){ // Versão ITERATIVA - Tamanho da lista.
	Node *atual = topo;
	int i = 0;
	
	while(atual){ // Enquanto nó existe.
		++i;
		atual = atual->prox;
	}
	return i;
}

// Versão RECURSIVA - Tamanho da lista.
int tamanhoListaRec(Node *topo){ // Função recursiva do Tamanho da lista.
	if(topo == NULL) return 0; // Se lista vazia, retorna tamanho 0.
	else return 1 + tamanhoListaRec(topo->prox); // Conta elementos da lista recursivamente até retornar caso base (zero).
}

// Recursiva.
bool verifica_Lista(Node *topo, int busca){ // Busca um valor na lista e retorna se está contido ou não (true/false).
	if(topo == NULL) return false; // 1º caso: Lista vazia OU chegou até último elemento (caso base).
	else if(topo->valor == busca) return true; // 2º caso: O elemento buscado está na iteração atual.
	else{ // Percorre a lista recursivamente até atingir caso base.
		return verifica_Lista(topo->prox, busca);
	}
}
// Existem dois casos bases na função acima, 1º: Lista estar vazia/chegar no último elemento (não encontrou) | 2º: encontrou valor buscado.

// Recursiva.
int contagem_Lista(Node *topo, int busca){ // Parecida com a função acima, porém esta CONTA quantas vezes o valor buscado aparece na lista.
	if(topo == NULL) return 0; // 1º caso: Lista vazia ou chegou no último elemento.
	else if(topo->valor == busca) // 2º caso: Iteração atual encontrou o valor.
		return 1 + contagem_Lista(topo->prox, busca); // Elemento buscado encontrado, incrementa 1 e segue procurando possíveis próximas aparições do valor.
	else // 3º caso: Não encontrou na iteração atual, segue procurando possíveis próximas aparições e NÃO incrementa na contagem.
		return contagem_Lista(topo->prox, busca);
}
// na função acima, o caso base agora é somente o primeiro pois somente ele TERMINA a continuação da recursão.

// Recursiva.
void trocar_Lista(Node *topo, int busca, int troca){ // Recebe além da lista, valor a procurar e valor a substituir todas as aparições da busca pelo novo elemento "troca".
	if(topo){ // topo != NULL 
		if(topo->valor == busca) topo->valor = troca; // Se valor da iteração atual é o valor buscado, troca ele pelo novo.
		trocar_Lista(topo->prox, busca, troca); // DE QUALQUER FORMA, procede até caso base (topo == NULL) preenchendo as possíveis aparições da busca pelo novo.
	}
	// Quando a recursão da lista chegar até onde topo == NULL, return será chamado finalizando a recursão.
	return; // Não retorna nada.
}

// Funções já antes estudadas.

Node *inserirTopo(Node *topo, int novoValor){
	Node *novoNode = calloc(1, sizeof(Node));
	novoNode->valor = novoValor;
	if(topo == NULL) return novoNode;
	else{
		novoNode->prox = topo;
		return novoNode;
	}
}

void exibirLista(Node *topo){
	Node *atual;
	atual = topo;
	int i = 0;
	
	while(atual != NULL){
		printf("Node %d: %d\n", i, atual->valor);
		++i;
		atual = atual->prox;
	}
}

