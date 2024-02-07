#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Escrever 7 números e gravar em um arquivo binário, em seguida
// inserir um nº número p/ ver sua posição no arquivo binário
// Esse código irá percorrer o arquivo e procurar onde está posicionado o nº buscado.
// Se houver mais de um mesmo nº, a posição será o do primeiro encontrado.

int main(void){
	const int tam = 7;
	setlocale(LC_ALL, "Portuguese");
	int *v = malloc(tam * sizeof(int)); // Aloc. dinâmica.
	if(v == NULL) return -1;
	
	printf("Digite 7 números, separados por espaço: ");
	for(int i = 0; i < tam; ++i) scanf("%d", v + i);
	
	// Escrita no arq. binário:
	
	FILE *arq;
	if( !(arq = fopen("dados.dat", "wb")) ) return -2;
	else fwrite(v, sizeof(int), tam, arq);
	free(v);
	fclose(arq);
	
	// Busca e leitura no arq. binário:
	
	int i = 1, busca, atual;
	printf("\n----- Consultar pos. do dado no arquivo -----\n");
	printf("Digite um dos números que você digitou: ");
	scanf("%d", &busca);
	
	arq = fopen("dados.dat", "rb");
	while(fread(&atual, sizeof(int), 1, arq)){ // Enquanto leitura é válida..
		if(busca == atual) break;
		++i;
	}
	fclose(arq);
	if(busca == atual){
		printf("\nO número buscado (%d) é o %dº valor do arquivo binário.", busca , i);
		printf("\nSe houver números repetidos, a posição encontrada é a do primeiro no arquivo binário.");
	} 
	else printf("\nValor buscado (%d) não encontrado no arquivo binário.", busca);
	
	return 0;	
}
