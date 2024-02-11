/*Escreva um programa em C que leia do teclado um número inteiro n e, a
partir daí, leia então n inteiros positivos e, ao final, imprima a média dos
pares e a média dos ímpares. Se um inteiro negativo for lido:
? um aviso deve ser impresso na tela
? o laço deve ser interrompido imediatamente
? as médias finais devem ser calculadas e apresentadas somente
com os números até então coletados.
Utilize o comando de repetição “for”.
Teste os valores encontrados. Por exemplo, para N = 10, se os 10 números
lidos do teclado forem {1,2,3,4,5,6,7,8,9,10}, então teremos
“media dos pares = 6”
“media dos ímpares = 5”.*/

#include <stdio.h>
#include <locale.h>

int ler(char s[30]){
	int n;
	printf("%s", s);
	scanf("%d", &n);
	return n;
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
		x = ler("Digite um valor: ");
		if(!checaNegativo(x)){
			printf("Um número negativo foi inserido e as médias serão calculadas somente até aqui, programa interrompido.");
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
