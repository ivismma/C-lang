#include <iostream>
#include <stdlib.h>

// baseado em Leetcode #15 (3Sum) - modificado com mais restrições

// Dado um vetor ordenado e um valor N, imprimir TODAS as somas de TRÊS elementos 
// no vetor que resultam no valor N inserido.
// Adicionalmente, remova números repetidos no array, caso existam.

using namespace std;

void achaSoma(int *v, short tam, int N);

int main(void){
	int v[] = {1,1,2,2,3,3,4,4,5,6,7,8,10,11}; // Soma máxima possível nesse array: 29 (8+10+11).
	short tam = sizeof(v)/sizeof(v[0]);
	int N; // target
	
	cout << "Insira N" << endl << "--> ";
	cin >> N;
	achaSoma(v, tam, N);
	
	return 0;
}
void achaSoma(int *v, short tam, int N){
	if(tam < 3) return;
	
	// array p/ filtrar eventuais números repetidos.
	int *v2 = (int*) malloc(tam * sizeof(int));
	v2[0] = v[0];
	int i, j;
	for(i = 1, j = 1; i < tam;){ // Remoção de num. repetidos.
		while(v[i] == v[i-1]) ++i;
		v2[j++] = v[i++];
	}
	i = 0; // i -> inicio 
	int k; // k -> meio
	--j;   // j -> fim;
	bool encontrou = false; // Se encontrou ao menos uma soma.
	
	cout << "---------------" << endl;
	do{
		for(k = i+1; k < j; ++k){
			int soma = v2[i] + v2[k] + v2[j];
			if(soma == N){
				encontrou = true;
				cout << v2[i] << " + " << v2[k] << " + " << v2[j] << " = " << soma << endl;
			}
			else if(soma > N){
				--j; // Reduz dos maiores números.
				--k; // Manter k na mesma pos. para próxima iteração
			}
		}
		++i; // Acrescenta dos menores números.
	} while(k <= j);
	free(v2);
	if(!encontrou) 
		 cout << "Nenhuma soma tripla que resulte em " << N << ".\n---------------\n";
	else cout << "---------------" << endl;
}
