/* (Beecrowd - problema 1020): Escreva um programa em C que leia um
valor inteiro correspondente à idade de uma pessoa (em dias) e o imprima em anos,
meses e dias, seguido de sua respectiva mensagem “ano(s)”, “mes(es)”, “dia(s)”.

OBS: Para facilitar o cálculo, considere que todo ano possui 365 dias e todo mês possui 30
dias. Nos casos de teste nunca haverá uma situação que permita 12 meses e alguns
dias, como 360, 363 ou 364. */

// Ou seja: 1 ano = 365 dias, 1 mês = 30 dias.

int main(){
	int v[6] = {360,361,362,363,364,365};
	int i,dias,meses,anos,idade;
	printf("Digite a idade em dias:\n");
	scanf("%d", &idade);
	
	for(i=0;i < 6;i++){ // Verifica se a idade é compatível.
		if(idade%v[i] == 0){
			printf("Algumas idades estão restritas a esse programa de exercício.");
			return -1;
		}
	}
	
	anos = idade/365;
	meses = (idade-365*anos)/30;
	dias = idade - 30*meses - 365*anos;
	
	printf("Essa idade em dias, equivale a: %d ano(s), %d mes(es) e %d dia(s).", anos, meses, dias);
	
	return 0;
}
