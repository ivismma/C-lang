/*Atividade 7 - o desvio incondicional “continue”.
Faça a seguinte modificação na Atividade 6:
Se um inteiro negativo for lido:
? um aviso deve ser impresso na tela;
? o programa então avançará imediatamente para a próx iteração,
sem produzir incremento (para que um total de n números válidos ainda
possa ser lido!);
? se, porém, um número negativo ocorrer 3 vezes, então o laço deve
ser interrompido imediatamente, e as médias apresentadas com os
números até então coletados.*/

#include <stdio.h>
#include <locale.h>

int ler(char s[30]){
	int n;
	printf("%s", s);
	scanf("%d", &n);
	return n;
}

int ler3x(char s[30]){
	int tries; // tentativas.
	int x = ler(s);
	for(int i = 1; i < 3; i++){
		if(!checaNegativo(x))
			ler("Por favor, digite um número positivo: ");
		else
			return x; // Inseriu um número positivo, OK! Retorna o valor inserido.
	}
	return -1; // Não inseriu um número positivo.
}

int checaNegativo(int x){
	if(x >= 0)
		return 1; // É positivo.
	return 0; // É negativo.
}

int checaPar(int x){
	if(x%2 == 0)
		return 1; // É par.
	return 0; // É ímpar.
}

int main(){
	setlocale(LC_ALL, "pt_BR.UTF-8");
	int pares, impares, qtdpares, qtdimpares, x, n = ler("Digite um valor n: ");
	float media1, media2;
	for(int i = 0; i < n; i++){
		x = ler3x("Digite um valor: "); // Resolver problema do negativo contando
		if(x < 0){
			printf("Um número negativo foi inserido 3 vezes e as médias serão calculadas somente até aqui, programa interrompido.");
			break;
		}
		if(checaPar(x)){
			pares += x;
			qtdpares += 1;
		}
		else{
			impares += x;
			qtdimpares += 1;
		}
	}
	media1 = pares/qtdpares;
	media2 = impares/qtdimpares;
	
	printf("\nMédia dos pares: %.2f", media1);
	printf("\nMédia dos ímpares: %.2f", media2);

	return 0;
}
