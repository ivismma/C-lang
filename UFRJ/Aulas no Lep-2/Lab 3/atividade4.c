#include <stdio.h>

int main(){
	
	const float limiar = 5.0; // Limiar de aprovação: 5.0
	float n1,n2,media;
	
	printf("Digite a 1ª nota:\n");
	scanf("%f", &n1);
	printf("Digite a 1ª nota:\n");
	scanf("%f", &n2);
	media = (n1+n2)/2;
	if(media >= limiar){
		printf("APROVADO");
	}
	else{
		printf("REPROVADO");
	}
	
	return 0;
}
