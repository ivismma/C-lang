#include <stdio.h>

// Objetivo: Escrever no arq binário um valor n = 10 e vetor { 2, 4, 6, 8, n }
// e depois realizar reescrita subtraindo cada valor no arq binário, ou seja, n = 8 e v {0, 2, 4 ,6, n}.

int main(void){
	int i, n = 10, // Deverá semr o último valor do vetor.
	v[] = { 2, 4, 6, 8, 10 };
	FILE *arq;
	
	if ( !(arq =  fopen("arqbin.dat", "wb")) ){
		printf("abertura falhou colega");
		return 1;
	}
	// Escrita do número e vetor no arq binário.
	fwrite(&n, sizeof(int), 1, arq);
	fwrite(v, sizeof(int), 5, arq);
	fclose(arq);
	
	// Antes: 2 4 6 8 10 <--> n = 10.
	printf("n antes: %d\n", n);
	printf("Arquivo antes: ");
	for(i = 0; i < 5; ++i) printf("%d ", v[i]);
	printf("\n");

	////////////////////////////////////////////////////////

	arq = fopen("arqbin.dat", "r+b");
	n = 8; // Vai ser o último valor (8).
	i = 0;
	while(i < 5) v[i++] -= 2; // Troca
	
	// Realizar substituição da escrita no arq binário:
	
	// Mudar 2 4 para: 0 2
	fseek(arq, 1*sizeof(int), SEEK_SET);
	fwrite(v, sizeof(int), 2, arq);
	// Mudar 8 10 em 6 8
	fseek(arq, -2*(long)sizeof(int), SEEK_END);
	fwrite(v + 3, sizeof(int), 2, arq);
	// Trocar o número do meio 6 para 4
	fseek(arq, -3*(long)sizeof(int), SEEK_END);
	fwrite(v + 2, sizeof(int), 1, arq);
	// Resultado esperado: 0 2 4 6 8
	
	rewind(arq); // é o mesmo que fseek usando SEEK_SET.
	fwrite(&n, sizeof(int), 1, arq); // Alterar valor de n de 10 p/ 8.
	
	fclose(arq);
	
	// LEITURA APÓS TROCA: 
	arq = fopen("arqbin.dat", "rb"); 
	int v2[5] = {0};
	
	fread(&n, sizeof(int), 1, arq);
	fread(v2, sizeof(int), 5, arq);
	printf("n depois: %d\n", n);
	printf("Arquivo depois: ");
	for(int i = 0; i < 5; ++i) printf("%d ", v2[i]);
	
	fclose(arq);
	return 0;
}
