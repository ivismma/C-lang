/*
Atividade 1 (baseada no problema “Vestibular” da OBI-Junior 2008):
Parte das universidades brasileiras ainda usa o vestibular para selecionar seus alunos. O
vestibular consiste de uma ou mais provas sobre as matérias do Ensino Médio, visando
avaliar os conhecimentos dos candidatos. Um formato popular de prova de vestibular é
a prova objetiva. Neste formato, cada candidato deve escolher uma das cinco alternativas
apresentadas pela questão como sendo a correta. Durante a correção dos cartões, cada
questão onde a alternativa escolhida pelo candidato é a mesma do gabarito, ele ganha um
ponto. Escreva um programa que, dado o gabarito e as respostas de um dos candidatos,
determina o número de acertos daquele candidato.
Entrada: A entrada contém um único conjunto de testes, que deve ser lido do
dispositivo de entrada padrão. A primeira linha da entrada contém um único inteiro N (1 <=
N <= 80), representando o número de questões na prova. A segunda linha da entrada
contém uma cadeia de N caracteres, indicando o gabarito da prova. A terceira linha da
entrada contém outra cadeia de N caracteres, indicando as opções marcadas pelo candidato.
Ambas as cadeias contém apenas os caracteres ‘A’, ‘B’, ‘C’, ‘D’ e ‘E’ (sempre em letra
maiúscula).
Saída: Seu programa deve imprimir na saída padrão uma única linha contendo um
único inteiro, indicando o número de acertos do candidato.
Obs.: Para ler as cadeias de caracteres use o formato %s
*/

#define FALSE 0
#define TRUE 1
#include <stdio.h>
#include <string.h>

int verificaResp(char v[], int n){ // Verifica se as alternativas selecionadas estão entre 'A' e 'E', e ao mesmo tempo, se não é maiúscula.
	for(int i = 0; i < n; ++i)
		if(v[i] < 'A' || v[i] > 'E')
			return FALSE; // Retorna -1 caso não respeite os requisitos.
	return TRUE;
}

int contabilizaAcertos(char resp[], char gabarito[], int n){
    int cont = 0;
    for(int i = 0; i < n; i++)
        cont += (resp[i] == gabarito[i]);
    return cont;
} 

int main(){  
    int n, acertos;
    // "A primeira linha da entrada contém um único inteiro N (1 <= N <= 80)"
	do {scanf("%d", &n);} while(n < 1 || n > 80);
	char resp[n], gabarito[n];

	// Retorna -1 se uma das entradas for inválida.
	scanf("%s", gabarito);
    if(!verificaResp(gabarito,n))
    	return -1;
   
    scanf("%s", resp);
    if(!verificaResp(resp,n))
    	return -1;
    
	acertos = contabilizaAcertos(resp, gabarito, n);
	printf("%d", acertos);
    
    return 0;
}
