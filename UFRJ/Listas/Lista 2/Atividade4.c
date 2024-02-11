/* Questão 4) Vimos em aula que a avaliação de uma expressão lógica em C dá-se da esquerda
para a direita, e é encerrada tão logo seu valor de verdade seja obtido.
? O que será impresso após a execução de cada uma das linhas onde há um comentário de
interrogação (“// ?”) à direita?
Primeiro TENTE determiná-los mentalmente e ESCREVA em cada linha o que você espera como
resultado. Somente depois disso VERIFIQUE em um programa se a sua resposta é correta. Algo saiu
diferente do esperado? Se sim, procure ENTENDER o porquê, e efetue as correções necessárias na
sua resposta final.
*/

#include<stdio.h>
int f(int a);

int main() {
	int a = 2, b = 3, c = 4;
	f(a) || f(b) && f(c); // Será impresso: 2
	f(a) || (f(b) && f(c)); // Será impresso: 2 
	(f(a) || f(b)) && f(c); // Será impresso:  2 4
	(a > b) && f(a) || f(b) && f(c); // Será impresso: 3 4
	(b > a) && f(a) || f(b) && f(c); // Será impresso: 2
	((b > a) && f(a) || f(b)) && f(c); // Será impresso: 2 4 <-- f(c)
	return 0;
}

int f(int a) {
	printf("%d ", a);
	return a;
}
