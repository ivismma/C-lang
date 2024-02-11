#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Biblioteca p/ valor booleano.
#include <time.h> // Biblioteca para calcular eficiência das funções em termos de tempo.

// Aula 6:
// Removendo ocorrências de um valor em uma lista encadeada 
// de maneira eficiente (Percorrer lista uma única vez).
// Comparando tempo em segundos da função eficiente e não eficiente.

typedef struct node{
	int valor;
	struct node *prox;
} Node;

Node *del_todasOcorrencias(Node *topo, int valor, int *qtd_deletada); 
Node *funcaoNaoEficiente(Node *topo, int valor, int *qtd_deletada);

void exibirLista(Node *topo);
Node *inserirTopo(Node *topo, int novoValor);


// Método eficiente
Node *del_todasOcorrencias(Node *topo, int valor, int *qtd_deletada){
	*qtd_deletada = 0;
	if(!topo) return NULL;
	
	Node *atual = topo, 
	*aux, // Esse ponteiro armazenará como var. auxiliar o nó a ser deletado na iteração.
	*novoTopo;
	while(atual->valor == valor){ // 1º Loop: 
		aux = atual;
		atual = atual->prox;
		free(aux);
		++(*qtd_deletada);
		// Caso a lista inteira seja composta pelo valor a ser deletado..
		if(atual == NULL) return NULL; // Ficou vazia.
	}
	novoTopo = atual; // Caso o topo não for o valor buscado, continuará o mesmo, senão, recebe o novo.
	// 2º Loop: Apagar nós até que o próximo n seja o valor buscado, após isso, o nó ATUAL aponta para o próx nó não removível (tratar sequências de valor buscado).
	// >>> Demonstração no arquivo de imagem no repositório <<<
	while(atual->prox != NULL){ 
		if(atual->prox->valor == valor){ // Se, no próximo nó, o valor dele for valor a ser deletado, apaga e continua checando.
			aux = atual->prox;
			atual->prox = atual->prox->prox; // O próximo nó será deletado, então ele apontará para o próximo nó DO próximo nó a ser deletado.
			free(aux); // Apaga próximo nó (que é o nó a ser deletado).
			++(*qtd_deletada);
		}
		else atual = atual->prox;
	}
	return novoTopo;
}


// MAIN
int main(){
	Node *lista1 = NULL; // Declaração de lista vazia.
	Node *lista2 = NULL; // Declaração de lista vazia.
	int qtd_del;
	
	// Criando duas listas encadeadas com um volume imenso de dados.
	// Existem 40000 6's em cada lista encadeada.
	for(int i = 0; i < 400000;++i)
		lista1 = inserirTopo(lista1, i%10);
	for(int i = 0; i < 400000;++i)
		lista2 = inserirTopo(lista2, i%10);
	clock_t tic, toc; // tic = tempo 1 | toc = tempo 2
	printf("1o metodo - Deletando todas as buscas do valor 6...\n");
	tic = clock();
	lista1 = funcaoNaoEficiente(lista1, 6, &qtd_del);
	toc = clock();
	printf("Total de ocorrencias apagadas: %d\nTempo de execucao: %fs", qtd_del,
	(double) (toc - tic) / CLOCKS_PER_SEC);
	
	printf("\nMetodo eficiente - Deletando todas as buscas do valor 6...\n");
	tic = clock();
	lista2 = del_todasOcorrencias(lista2, 4, &qtd_del);
	toc = clock();
	printf("Total de ocorrencias apagadas: %d\nTempo de execucao: %fs", qtd_del,
	(double) (toc - tic) / CLOCKS_PER_SEC);
	// Se for mostrado valores redondos, sem sentido ou 0.000..s | Possivelmente problema de compat. do compilador usado.
	return 0;
}

//////// Funções já estudadas ////////

// Metodo anterior:
Node *funcaoNaoEficiente(Node *topo, int valor, int *qtd_deletada){
	if(topo == NULL) return NULL; 	
	*qtd_deletada = 0;
	Node *atual = topo;
	Node *anterior = NULL; // Adicionei esta linha para garantir que anterior seja inicializado corretamente

	while(atual != NULL){
		if(atual->valor == valor){
			if(anterior == NULL) { // Se for o primeiro nó
				topo = atual->prox;
			} else {
				anterior->prox = atual->prox;
			}
			free(atual);
			atual = anterior ? anterior->prox : topo;
			++(*qtd_deletada);
		}
		else{
			anterior = atual;
			atual = atual->prox;
		}
	}

	return topo;
}

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
