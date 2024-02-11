/*Questão 5) Faça um programa que leia um número natural n e dois números naturais a e b
diferentes de 0 e apresente na tela em ordem crescente os n primeiros naturais que são múltiplos
de a ou de b.
Exemplo: Para n = 6, a = 2 e b = 3 deverá ser apresentada a sequência: 0 2 3 4 6 8.

O programa deverá conter as 3 seguintes funções:

int ehMultiplo(int r, int s); //verifica se r é múltiplo de s (retorna 1 se sim; 0 caso contrário)

void multiplos(int q, int x, int y); //imprime os q primeiros múltiplos de x ou de y.

int main(); //lê as entradas do usuário e chama a função ’multiplos’.*/

#include <stdio.h>

int ehMultiplo(int r, int s);
void multiplos(int q, int x, int y);


int main(){
	int n,a,b;
	do{ // DEFESA
		printf("Digite um número natural n diferente de zero: ");
		scanf("%d", &n);
	} while(n == 0);
	
	do{ // DEFESA
		printf("Digite um número natural a diferente de zero: ");
		scanf("%d", &a);
	} while(a == 0);
	
	do{ // DEFESA
		printf("Digite um número natural b diferente de zero: ");
		scanf("%d", &b);
	} while(b == 0);
	
	multiplos(n,a,b);
	
	return 0;
}

int ehMultiplo(int r, int s){
	if( !(s%r) ){ 
		return 1; // É Múltiplo
	} return 0; //Não é múltiplo
}

void multiplos(int q, int x, int y){
	int z = 0;
	while(q){ // q é a quantidade de números a ser exibido, enquanto ele for verdadeiro, continua procurando os múltiplos.
		if(ehMultiplo(x,z)){
			printf("%d ", z);
			--q; // 
			++z; // z é o número a ser testado.
			continue;
		}
		if(ehMultiplo(y,z)){
			printf("%d ", z);
			--q;
			++z;
			continue;
		} ++z;
	}
}
