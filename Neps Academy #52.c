#include <stdio.h>
#include <stdbool.h>

#define MIN 2
#define MAX 100000

// Lâmpadas
// https://neps.academy/br/exercise/52

int main(void){

	bool A  = false;
	bool B  = false;	
	short int botao;
	int N;
	
	scanf("%d", &N);
	if(N < MIN || N > MAX) return 10;
	
	while(N--){
		scanf("%hd", &botao);
		if(botao == 1)
			A = !A;
		else if(botao == 2){
			A = !A;
			B = !B;
		}
		else // Input inválido.
			return 11;
	}
	
	printf("%d\n%d", A, B);
	return 0;
}
