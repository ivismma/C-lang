/*
Questão lista antiga - Prof. Valéria - Prog I grade 2010.

Super Desafio
Quem ganhou a Francasena?

Em Pindorama, um país que fica ao norte do sul, o jogo é proibido. Você só pode jogar na Ultrasena,
Hiperquina, Duplaalgumacoisa, loteria esportiva e outros quinhentos e trinta e um jogos. Todos estes
jogos, por sinal, são organizados pelo governo, que prende quem joga nos jogos dos outros. Na Fracasena o
jogador deve acertar seis números, entre 1 e 66, que são sorteados semanalmente. O jogador somente pode
jogar em seis números. A sua tarefa é escrever um programa que descubra quem ganhou na Fracasena.
Entrada:
A entrada é composta de várias linhas. Na primeira linha temos 6 números, em ordem crescente, que
correspondem aos números sorteados. Em seguida temos um número inteiro N indicando a quantidade de
cartões que foram jogados durante a semana. Em seguida o programa deve ler N linhas com 6 números
em ordem crescente, que são as apostas.
Saída:
A saída informa quem foram os ganhadores. A informação é ordem do jogador na lista. A lista começa
com o jogador 1 vai até N.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool intervalo(int n){ return (n >= 1 && n <= 66); }
bool igual(int *v1, int *v2);
void lerCartao(int *v);

int main(void){
	
	int N, sorteado[6], jogador[6];
	
	lerCartao(sorteado);
	
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		lerCartao(jogador);
		if(igual(jogador, sorteado))
			printf("Jogador %d acertou\n", i+1);
	}
	
	return 0;
}

void lerCartao(int *v){
	int num, anterior;

	scanf("%d", &num);
	if(intervalo(num)){
		v[0] = num;
		anterior = num;
	}
	else exit(1);
	for(int i = 1; i < 6; ++i){
		scanf("%d", &num);
		if(intervalo(num) && num >= anterior){
			v[i] = num;
			anterior = num;
		}
		else
			exit(1);
	}
}

bool igual(int *v1, int *v2){
	for(int i = 0; i < 6; ++i)
		if(v1[i] != v2[i]) return false;
	
	return true;
}
