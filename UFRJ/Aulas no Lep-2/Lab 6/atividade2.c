/*
Atividade 2: No laboratório passado fizemos uma função que imprime a tabuada de
um número entre 1 e 10, lido do teclado.
a) Agora escreva uma função recursiva para a impressão da tabuada.
b) Faça com que sua função exiba a tabuada em ordem crescente ou
decrescente simplesmente alterando o momento da chamada recursiva,
assim como vimos no exercício em Aula.
*/

#include <stdio.h>
// Item (a)
void tabuada(int n, int i){
	if(i < 1)
		return;
	tabuada(n, i-1);
	printf("%d x %d = %d\n", n, i, n*i);
}
// Item (b)
void tabuadaInvertida(int n, int i){
	if(i < 1)
		return;
	printf("%d x %d = %d\n", n, i, n*i);
	tabuadaInvertida(n, i-1);
}

int main(){
	int n, esc;
	
	printf("Digite um número para exibir sua tabuada até o 10: ");
	scanf("%d", &n);
	printf("Digite 1 para exibir uma tabuada normal ou qualquer coisa para sua tabuada invertida: ");
	scanf("%d", &esc);
	if(esc == 1)
		tabuada(n, 10);
	else
		tabuadaInvertida(n, 10);
	return 0;
}
