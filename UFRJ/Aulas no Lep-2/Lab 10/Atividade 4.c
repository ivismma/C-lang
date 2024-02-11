/*
Implemente a função copiaString definida abaixo. Essa função recebe duas strings
como entrada e copia a primeira string para a segunda, até o tamanho máximo do espaço de
memória reservado para a segunda string
*/

/*PARTE 1*/

#include <stdio.h>

void copiaString(char str1[], char str2[], int max); // Assinatura da função
void parte2_copiaString(char str1[], char str2[], int max); // Assinatura da função (Parte 2 do exercício)

/*Execute o programa abaixo para avaliar a sua implementação:*/
int main() {
	char palavra1[20], palavra2[10];
	puts("Digite uma palavra com ate 19 caracteres:");
	scanf("%19[^\n]", palavra1);
	copiaString(palavra1, palavra2, 9); // O Exercício pediu para usar essa main, mas isso poderia ser melhorado usando sizeof(palavra2)-1 no lugar do 9.
	printf("%s\n%s\n", palavra1, palavra2);
	return 0;
}

void copiaString(char str1[], char str2[], int max){
	int i = 0;
	str2[max] = '\0'; // Inicializando com o caracter terminador da string.
	
	while(i < max) // Índice anterior ao índice em que será colocado o '\0'.
		str2[i] = str1[i++];
	return; // void
}
// No gabarito, a saída esperada para "ola mundo ola" está dita como "ola mund"
// Aparentemente está errado, pois "ola mund" ainda possuiria mais 2 espaços (1 para o 'o' e outro para '\0')
// Então a resposta certa seria definitivamente "ola mundo" pois palavra2 tem tamanho 10 (vetor de 0-9).

/*PARTE 2 - "Agora inverta o tamanho das palavras: palavra1 com tamanho 10 e palavra2 com tamanho 20, e
verifique a corretude da sua implementação"*/

/*
int main() {
	char palavra1[10], palavra2[20];
	puts("Digite uma palavra com ate 9 caracteres:");
	scanf("%9[^\n]", palavra1);
	copiaString(palavra1, palavra2, 9); // O Exercício pediu para usar essa main, mas isso poderia ser melhorado usando sizeof(palavra2)-1 no lugar do 9.
	printf("%s\n%s\n", palavra1, palavra2);
	return 0;
}

void copiaString(char str1[], char str2[], int max){
	int i = 0;
	str2[max] = '\0'; // Inserindo aracter nulo no fim da string com pré-incremento.
	// max continua 9 pois a str1 (entrada) é menor do que a str 2, então o terminador terá que ser em str2[9].
	while(i < max) // Índice anterior ao índice em que será colocado o '\0'.
		str2[i] = str1[i++];
	return; // void
}
*/
