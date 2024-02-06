#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 6000000 // Tam. vetor dinâmico.
#define INICIA_CRONO clock_gettime(CLOCK_MONOTONIC, &t1);
#define PARA_CRONO clock_gettime(CLOCK_MONOTONIC, &t2);
void exibeTempo(struct timespec t1, struct timespec t2);

// Comparação de desempenho malloc() vs calloc().

int main(void){
	struct timespec t1, t2;
	int *ponteiro;
	
	INICIA_CRONO
	ponteiro = (int *) malloc(TAM * sizeof(int));
	PARA_CRONO
	if(ponteiro == NULL){ 
		printf("problema na alocacao amigo"); return -1;
	}
	for(int i = 0; i < TAM; ++i) *(ponteiro+i) = i%10; // Preencher vetor para causar lixo de memória mesmo após o
	exibeTempo(t1,t2); // MALLOC                        free() obrigando calloc() a limpar na próxima alocação.
	free(ponteiro);
	
	INICIA_CRONO
	ponteiro = (int *) calloc(TAM, sizeof(int));
	PARA_CRONO
	if(ponteiro == NULL){ 
		printf("problema na alocacao amigo"); return -2;
	}
	exibeTempo(t1,t2); // CALLOC
	free(ponteiro);
	
	return 0;
}

// Conclusão:
   // Implementação do calloc é mais cara, aloca e percorre TODO o vetor dinâmico após a alocação, 
   // definindo índices como zero, grande diff de desempenho.. utilizar somente quando necessário.












void exibeTempo(struct timespec t1, struct timespec t2){
	double decorrido = (t2.tv_sec - t1.tv_sec) + (t2.tv_nsec - t1.tv_nsec) / 1e9;
	printf("Tempo decorrido: %.9f s.\n", decorrido);
}
