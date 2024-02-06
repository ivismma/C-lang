#include <stdio.h>
#include <locale.h>

void freqAlgarismo(long long int num, int freq[]);

int main(){
	setlocale(LC_ALL, "Portuguese");
	long long int num;	
	int frequencia[10] = {0}; // 0 1 2 3 4 5 6 7 8 9
	// Algarismo == indice.
	
	printf("Digite um numero de ate 16 dígitos:\n");
	scanf("%lld", &num);
	printf("Número: %lld\n\n", num);
	
	freqAlgarismo(num, frequencia);
	for(int i = 0; i < 10; i++) printf("Algarismo %d - %d\n", i, frequencia[i]);
	
	return 0;
}

void freqAlgarismo(long long int num, int freq[]){
	while(num){
		int digito = num%10;
		num /= 10;
		++freq[digito];
	}
}
