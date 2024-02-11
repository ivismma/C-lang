/*
b) Vimos que a quantidade de dígitos de um inteiro ‘x’ pode ser obtida iterativamente pela
seguinte função (onde ‘x’ é o parâmetro de entrada):

int numDigitos(int x) {
int num = 0;
do {
	num++; //x possui ao menos 1 dígito.
	x /= 10;
	} while (x); //Equivale a "while(x != 0)"
	return num;
}

Escreva uma versão recursiva da função numDigitos.
*/

int numDigitosRec(int n, int soma){
	if(!n) return soma;
	return numDigitosRec(n/10, ++soma);
}

int main(){
	int n;
	do{ printf("Insira um numero diferente de zero: "); scanf("%d", &n);
	} while(!n);
	printf("\n%d possui %d digito(s).", n, numDigitosRec(n, 0));
	
	return 0;
}
