#include <stdio.h>

int obterDigito(int n, char letra);

int main(void){
	int numero, res;
	char letra;

	printf("Insira letra e digito, separados por espaco: ");
	scanf("%d %c", &numero, &letra);
	res = obterDigito(numero, letra);
	if(res != -1)
		printf("%d", res);
	else
		printf("Letra invalida inserida.");

	return 0;
}

int obterDigito(int n, char letra){
	int i, digito;
	n = (n < 0)? -n : n;    // Evitar retorno negativo.
	
	if(letra == 'u') 
		return n%10;        // A unidade do valor inserido é o que procuramos.
	else if(letra == 'd') 
		return n/10%10;     // Necessário pular um dígito
	else if(letra == 'c') 
		i = n/100%10;       // Necessário pular dois dígitos
	else if(letra == 'm') 
		i = n/1000%10;      // Necessário pular três dígitos
	else 
		return -1;          // Letra inválida.
	
}

/*

9. DESAFIO: Na Lista 2 - Questão 3, Tivemos um exercício o qual, a partir de
um inteiro com 5 dígitos, deveria ser impresso a unidade desse valor.
Dessa vez, crie uma função que receba um inteiro e uma letra, o valor
inserido deverá possuir 4 dígitos. Veja o que o programa deverá retornar
em cada caso:
Sugestão de assinatura da função: int obterDigito(int n, char letra);
Letra inserida - Retornar algarismo
‘u’: - Retornar a unidade do valor.
‘d’ - Retornar a dezena do valor.
‘c’ - Retornar a centena do valor.
‘m’ - Retornar a unidade de milhar do valor.
Se outra letra for inserida, o programa deverá retornar -1.
São exemplos de entrada e saída da função:
ENTRADA    SAÍDA
1032, ‘d’    3
2024, ‘u’    4
2024, ‘c’    0
1723, ‘x’   -1

*/
