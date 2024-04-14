#include <stdio.h>

// SEEK_SET Pos. inicial do arquivo.
// SEEK_CUR Pos. atual do arquivo
// SEEK_END Fim do arquivo.      fseek --> (*ARQUIVO, OFFSET, POSICAO)

int main(void){
	FILE *arq  = fopen("antes.txt", "w"),  // Antes
	     *arq2 = fopen("depois.txt", "w"); // Depois das alterações.
	if(!arq || !arq2){
		printf("windows nao quis rsrs"); return 1;
	}
		
	fprintf(arq, "123456789\n");
	fprintf(arq, "--> Segunda linha no arquivo");
	fclose(arq);
	fprintf(arq2, "123456789\n");
	fprintf(arq2, "--> Segunda linha no arquivo");
	
	fseek(arq2, 0, SEEK_SET);
	fprintf(arq2, "2"); // O '1' no arquivo vira '2'.
	
	fseek(arq2, 5, SEEK_CUR);
	fprintf(arq2, "777"); // "789" no arquivo viram "777".
	
	fseek(arq2, -6, SEEK_CUR);
	fprintf(arq2, "00"); // "45" no arquivo vira "00".
	// Resultado esperado 1ª linha: 223006777
	
	fseek(arq2, 0, SEEK_END);
	fprintf(arq2, "..."); // Adicionar reticências no fim da seg. linha.
	
	fclose(arq2);
	printf("Escrita realizada (antes.txt, depois.txt).");
	return 0;
}
