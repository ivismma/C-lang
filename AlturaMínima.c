#include <stdio.h>

// Problema A da Maratona de Programação da SBC 2023 - Sub Regional do Brasil do ICPC
/*
http://maratona.sbc.org.br/eventos/2023/Primeira/contest/maratona.pdf
Link das questões, já que copiar e colar por aqui resulta em erros de caracteres, mesmo assim, enunciado abaixo.

Carlitos ´e um entusiasta de aventuras com um amor insaci´avel por parques de divers˜oes. Apesar da
sua paix˜ao vibrante, Carlitos enfrenta um desafio ´unico: a sua estatura limitada. Enquanto planeja
ansiosamente sua aventura de fim de semana, ele percebe que suas limita¸c˜oes verticais podem atrapalhar sua experiˆencia no parque de divers˜oes. N˜ao se trata apenas de escolher um parque; trata-se de
encontrar um onde ele possa aproveitar a emo¸c˜ao dos brinquedos.
Imagine o caleidosc´opio de cores, as risadas jubilosas e a adrenalina dos passeios. Carlitos sempre
foi atra´ido pela energia dos parques de divers˜oes. Com o fim de semana se aproximando, ele se
debru¸ca sobre os folhetos do parque, estudando os requisitos de altura de cada passeio. O objetivo
dele ´e maximizar sua divers˜ao, e ´e a´i que vocˆe entra.
Sua tarefa ´e ajudar Carlitos a determinar o n´umero de passeios que ele pode desfrutar em um
parque espec´ifico. Considerando sua altura e os requisitos m´inimos de altura de cada passeio, orienteo a aproveitar ao m´aximo sua aventura no parque de divers˜oes.
Entrada
A primeira linha cont´em dois n´umeros inteiros, N e H (1 <= N <= 6 e 90 <= H <= 200), que representam a quantidade de brinquedos em um parque e a altura de Carlitos em cent´imetros, respectivamente.
Na segunda linha da entrada, ser˜ao fornecidas as alturas m´inimas A1, . . . , AN (90 <= Ai <= 200) de
cada um dos brinquedos do parque.
Sa´ida
Seu programa deve imprimir uma ´unica linha contendo a quantidade de brinquedos nos quais
Carlitos pode ir, ou seja, a quantidade de brinquedos para os quais a altura de Carlitos é pelo menos
tão grande quanto a altura m´inima necessária.

*/

// Exemplo de entrada:
// 5 150
// 120 170 120 100 160
// Saída: 3 (Carlinhos pode usufruir de 3 brinquedos com base em sua altura e a altura mínima dos brinquedos.

int main(){
	
	int qtd,altura,i, cont=0; // qtd = Quantidade de brinquedos | altura = Altura de Carlitos | cont = Quantidade de brinquedos que Carlitos pode usufruir.
	
	// Entrada
    scanf("%d %d", &qtd, &altura);
    // DEFESA
	if( (qtd < 1 || qtd > 6) || (altura < 90 || altura > 200) ){ 
		printf("ERRO - Os valores inseridos não respeitam o intervalo da questão 1.");
		return -1;
	}
	// Solução
	int brinquedo[qtd]; // Criação de vetor de tamanho quantidade de brinquedos.
	for(i=0;i < qtd;++i) // Entrada de alturas mínimas dos brinquedos (em uma única linha, separada por espaços).
		scanf("%d", &brinquedo[i]); 
	for(i=0;i < qtd;++i) // Checagem de altura de Carlitos em comparação com a altura mínima dos brinquedos do parque.
		cont += (altura >= brinquedo[i]); // Expressão lógica.
	// Saída
	printf("%d", cont);
    
	return 0;
}
